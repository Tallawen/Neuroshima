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

        Texture::Texture(std::string alians, std::string group, std::string title, sf::Vector2f size, std::string fname, bool subTex, int id)
            : BaseTexture(alians, group, title, size), _filename(fname), _subTex(subTex), _id(id)
        {
            _subTexture.clear();
            _subTextureNameIndex.clear();
        }

        sf::Texture Texture::texture(const int &id) {
            return sf::Texture();
        }

        sf::Texture Texture::texture(const std::string &name) {
            return sf::Texture();
        }

        bool Texture::attachSubTexture(SubTexture &sub) {
            return false;
        }

        bool Texture::detachSubTexture(int &id) {
            return false;
        }

        bool Texture::detachSubTexture(std::string &name) {
            return false;
        }

    } /*namespace Tex */

} /* namespace Renderer */
