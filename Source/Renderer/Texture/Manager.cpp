#include "Manager.h"

namespace Renderer {

    namespace Texture {

        /************************************************/
        Manager::Manager() : Utils::Identifier("Texture") {

        }


        /************************************************/
        Manager::~Manager() {

        }


        /************************************************/
        int Manager::attach(Texture texture) {
            if(!texture.valid())
                return -1;

            if(texturesIndexName[texture.group()].find(texture.name()) != texturesIndexName[texture.group()].end()) {
                LOG << LOG_INFO(LMsg::Error) << "Textura o takiej nazwie już istnieje: group = \"" << texture.group() << "\", alias = \"" << texture.alias()
                                             << "\", title = \"" << texture.title() << "\", filename = \"" << texture.filename() << "\"" << std::endl;
              return -1;
            }

            texture.setID(newID());
            texturesResource[texture.id()] = texture;
            texturesIndexName[texture.group()][texture.name()] = texture.id();

            // TODO: Dodać loga typu debug o informacji że textura zaotała dodana (ten typ poestanie dopiero po złączeniu Mastera i MTexture)

          return texture.id();
        }


        /************************************************/
        int Manager::attachSub(const int &id, SubTexture &subtexture) {
            if(!textureResourceExists(id))
                return -1;

            subtexture.setGroup(texturesResource[id].group());
            if(!subtexture.valid())
                return -1;

            subtexture.setID(newID());

            texturesResource[id].attachSubTexture(subtexture);
          return subtexture.id();
        }


        /************************************************/
        int Manager::attachSub(const std::string &group, const std::string &name, SubTexture &subtexture) {
            if(!textureResourceExists(group, name))
                return -1;

          return attachSub(texturesIndexName[group][name], subtexture);
        }


        /************************************************/
        int Manager::attachSub(const Texture &texture, SubTexture &subtexture) {
            if(!texture.valid())
                return -1;

          return attachSub(texture.group(), texture.name(), subtexture);
        }


        /************************************************/
        bool Manager::detach(const int &id) {
            if(!textureResourceExists(id))
                return false;

            if(textureExists(id, false)) {
                LOG << LOG_INFO(LMsg::Warning) << "Textura (id = " << id << ") jest obecnie załadowana w pamieci. Nie można jej odpiąć." << std::endl;
              return false;
            }

             Texture texture = texturesResource[id];
            texturesIndexName[texture.group()].erase(texture.name());
            texturesResource.erase(id);
            textures.erase(id);

            // TODO: Dodać loga typu debug o informacji że textura zaotała usunięta

          return true;
        }


        /************************************************/
        bool Manager::detach(const std::string &group, const std::string &name) {
            if(!textureResourceExists(group, name))
                return false;

          return detach(texturesIndexName[group][name]);
        }


        /************************************************/
        bool Manager::fDetach(const int &id) {
            if(!textureExists(id))
                return false;

            textures.erase(id);

            if(texturesResource.find(id) != texturesResource.end()) {
                 Texture texture = texturesResource[id];
                LOG << LOG_INFO(LMsg::Info) << "Wymuszono usunięcie podpiętej textury (id = " << id << "): group = \"" << texture.group()
                                            << "\", name = \"" << texture.name() << "\"" << std::endl;

                detach(id);
            }
          return true;
        }


        /************************************************/
        std::string Manager::showTextures() {
            std::stringstream tree;

            std::map<std::string, int>::iterator it;

            std::list<std::string>::iterator groupIt = _loadGroup.begin();

            tree << "[Załadowane textury]" << std::endl;

            while(groupIt != _loadGroup.end()) { /* Iteracja po grupach */
                tree << *groupIt << std::endl;

                 it = texturesIndexName[*groupIt].begin();
                while(it != texturesIndexName[*groupIt].end()) { /* Iteracja po texturach należących do danej grupy */
                    if(textureExists(it->second)) /* Gdy textura jest załadowana */
                        tree << std::string(2, ' ') << "|_ id = " << /*std::setw(4) <<*/ it->second << ", name = \"" << it->first << "\"" << std::endl;

                    ++it;
                }

                ++groupIt;
            }
          return tree.str();
        }


        /************************************************/
        std::string Manager::showTexturesResource() {
            std::stringstream tree;
            std::string currentGroup = "";

            std::map<std::string, int>::iterator it;
            std::map<std::string, int>::iterator subIt; /* Iterator po subtexturach */

            auto groupIt = texturesIndexName.begin();

            tree << "[Baza textur]" << std::endl;

            while(groupIt != texturesIndexName.end()) { /* Iteracja po grupach */
                it = groupIt->second.begin();

                while(it != groupIt->second.end()) { /* Iteracja po texturach należących do danej grupy */
                    if(textureResourceExists(it->second)) { /* Gdy textura istnieje w bazie */

                        if(groupIt->first.compare(currentGroup)) { /* Gdy nie została jeszcze wypisana jej grupa w drzewie */
                            currentGroup = groupIt->first;
                            tree << currentGroup << std::endl;
                        }

                        tree << std::string(2, ' ') << "|_ id = " << /*std::setw(4) <<*/ it->second << ", name = \"" << it->first << "\"" << std::endl;

                         subIt = texturesResource[it->second]._subTextureNameIndex.begin();
                        while(subIt != texturesResource[it->second]._subTextureNameIndex.end()) { /* Wypisujemy subtextury */
                            tree << std::string(6, ' ') << "|_ id = " << /*std::setw(4) <<*/ subIt->second << ", name = \"" << subIt->first << "\"" << std::endl;

                            ++subIt;
                        }

                    }
                    ++it;
                }
                ++groupIt;
            }
          return tree.str();
        }


        /************************************************/
        bool Manager::textureExists(const int &id, const bool &printLog) const {
            bool exists = textures.find(id) != textures.end();

            if(!exists && printLog)
                LOG << LOG_INFO(LMsg::Error) << "Textura (id = " << id << ") nie istnieje w pamięci." << std::endl;

          return exists;
        }


        /************************************************/
        bool Manager::textureExists(const std::string &group, const std::string &name, const bool &printLog) {
            bool exists = texturesIndexName[group].find(name) != texturesIndexName[group].end();

            if(exists)
                exists = textureExists(texturesIndexName[group][name], false);

            if(!exists && printLog)
                LOG << LOG_INFO(LMsg::Error) << "Textura nie istnieje w bazie: group = \"" << group << "\", name = \"" << name << "\"" << std::endl;

          return exists;
        }


        /************************************************/
        bool Manager::textureResourceExists(const int &id, const bool &printLog) const {
            bool exists = texturesResource.find(id) != texturesResource.end();

            if(!exists && printLog)
                LOG << LOG_INFO(LMsg::Warning) << "Textura (id = " << id << ") nie iestnieje w bazie." << std::endl;

          return exists;
        }


        /************************************************/
        bool Manager::textureResourceExists(const std::string &group, const std::string &name, const bool &printLog) {
            bool exists = texturesIndexName[group].find(name) != texturesIndexName[group].end();

            if(exists)
                exists = textureResourceExists(texturesIndexName[group][name], false);

            if(!exists && printLog)
                LOG << LOG_INFO(LMsg::Error) << "Textura nie istnieje w bazie: group = \"" << group << "\", name = \"" << name << "\"" << std::endl;

          return exists;
        }

    }

}
