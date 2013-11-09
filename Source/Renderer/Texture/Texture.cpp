#include "Texture.h"

namespace Renderer {

    namespace Texture {

        /************************************************/
        Texture::Texture() : BaseTexture() {
            _filename = "";

            _subTexture.clear();
            _subTextureNameIndex.clear();
        }


        /************************************************/
        Texture::Texture(const std::string &alians, const std::string &group, const std::string &title, const sf::Vector2f &size, const std::string &filename, const int &id)
            : BaseTexture() {

            setAlians(alians);
            setGroup(group);
            setTitle(title);
            setSize(size);
            setID(id);

            _filename = filename;
        }


        /************************************************/
        bool Texture::attachSubTexture(const SubTexture &sub) {
            if(_subTexture.find(sub.id()) != _subTexture.end())
                return false;

            _subTexture.insert(std::pair<int, SubTexture>(sub.id(), sub));
            _subTextureNameIndex.insert(std::pair<std::string, int>(sub.alians(), sub.id()));

          return true;
        }


        /************************************************/
        bool Texture::detachSubTexture(const int &id) {
            if(_subTexture.find(id) == _subTexture.end())
                return false;

            _subTextureNameIndex.erase(_subTexture[id].alians());
            _subTexture.erase(id);

          return true;
        }


        /************************************************/
        bool Texture::detachSubTexture(const std::string &name) {
            if (_subTextureNameIndex.find(name) == _subTextureNameIndex.end())
                return false;

          return detachSubTexture(_subTextureNameIndex[name]);
        }

    } /*namespace Texture */

} /* namespace Renderer */
