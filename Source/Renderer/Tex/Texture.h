#ifndef __RENDERER_TEX_TEXTURE_H__
#define __RENDERER_TEX_TEXTURE_H__

#include "../../StdAfx.h"
#include "SubTexture.h"

namespace Renderer
{

    namespace Tex
    {
        /*/*************************************************
        * @ingroup RENDERER_TEX
        * @class Texture Texture.h "Renderer/Tex/Texture.h"
        *
        * @brief Klasa odpowiedzialna za przechowywanie informacji o teksturach
        **************************************************/
        class Texture : public BaseTexture
        {
        private:
            std::string _filename;

            bool _subTex;

            std::map<int, SubTexture> _subTexture;

            std::map<std::string, int> _subTextureNameIndex;

        public:
            Texture();

            Texture(std::string alians, std::string group, std::string title, sf::Vector2f size, int id, std::string fname, bool subTex);

            ~Texture() {
                _subTexture.clear();
                _subTextureNameIndex.clear();
            }

        public:
            void setFileName(std::string fname) {
                _filename = fname;
            }

            std::string fileName() const {
                return _filename;
            }

            bool haveSubTexture() const {
                return _subTex;
            }

            bool attachSubTexture(SubTexture &sub);

            bool detachSubTexture(int &id);

            bool detachSubTexture(std::string &name);

        }; /* class Texture */

    } /* namespace Tex */

} /* namespace Renderer */

#endif /* __RENDERER_TEX_TEXTURE_H__ */
