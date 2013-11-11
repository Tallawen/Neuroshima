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
            if(!validTextureName(texture)) {
                LOG << LOG_INFO(LMsg::Error) << "Niepoprawna nazwa textury: group = \"" << texture.group() << "\", alias = \"" << texture.alias()
                                             << "\", title = \"" << texture.title() << "\", filename = \"" << texture.filename() << "\"" << std::endl;
              return -1;
            }

            if(texturesIndexName[texture.group()].find(textureName(texture)) != texturesIndexName[texture.group()].end()) {
                LOG << LOG_INFO(LMsg::Error) << "Texktura o takiej nazwie już istnieje: group = \"" << texture.group() << "\", alias = \"" << texture.alias()
                                             << "\", title = \"" << texture.title() << "\", filename = \"" << texture.filename() << "\"" << std::endl;

              return -1;
            }

            texture.setID(newID());
            texturesResource[texture.id()] = texture;
            texturesIndexName[texture.group()][textureName(texture)] = texture.id();

            // TODO: Dodać loga typu debug o informacji że textura zaotała dodana (ten typ poestanie dopiero po złączeniu Mastera i MTexture)

          return texture.id();
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
            texturesIndexName[texture.group()].erase(textureName(texture));
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
                                            << "\", name = \"" << textureName(texture) << "\"" << std::endl;

                detach(id);
            }
          return true;
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


        /************************************************/
        inline bool Manager::validTextureName(const Texture &texture) const {
            if(/*texture.group().length() > 0 &&*/ (texture.alias().length() > 0 || texture.title().length() > 0))
                return true;

          return false;
        }


        /************************************************/
        inline std::string Manager::textureName(const Texture &texture) const {
          return texture.alias().length() > 0 ? texture.alias() : texture.title();
        }

    }

}
