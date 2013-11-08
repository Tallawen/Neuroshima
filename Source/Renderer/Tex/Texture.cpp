#include "Texture.h"

namespace Renderer
{
    namespace Tex
    {
        Texture::Texture() : BaseTexture(), _filename(), _subTex(false), _id()
        {
            _subTexture.clear();
            _subTextureNameIndex.clear();
        }

        Texture::Texture(std::string alians, std::string group, std::string title, sf::Vector2f size, int id
                , std::string fname, bool subTex)
            : BaseTexture(alians, group, title, size, id), _filename(fname), _subTex(subTex)
        {
            _subTexture.clear();
            _subTextureNameIndex.clear();
        }

        bool Texture::attachSubTexture(SubTexture &sub) {
            if (_subTexture.find(sub.id()) != _subTexture.end())
                return false;
            _subTexture.insert(std::pair<int, SubTexture>(sub.id(), sub));
            _subTextureNameIndex.insert(std::pair<std::string, int>(sub.alians(), sub.id()));
            return true;
        }

        bool Texture::detachSubTexture(int &id) {
            if (_subTexture.find(id) == _subTexture.end())
                return false;
            _subTextureNameIndex.erase(_subTexture[id]._alians);
            _subTexture.erase(id);
            return true;
        }

        bool Texture::detachSubTexture(std::string &name) {
            if (_subTextureNameIndex.find(name) == _subTextureNameIndex.end())
                return false;
            _subTexture.erase(_subTextureNameIndex[name]);
            _subTextureNameIndex.erase(name);
            return true;
        }

    } /*namespace Tex */

} /* namespace Renderer */
