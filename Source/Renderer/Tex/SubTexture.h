#ifndef __RENDERER_TEX_SUB_TEXTURE_H__
#define __RENDERER_TEX_SUB_TEXTURE_H__

#include "../../StdAfx.h"
#include "BaseTexture.h"

namespace Renderer
{

    namespace Tex
    {
        class Texture;
        /*/*************************************************
         * @ingroup RENDERER_TEX
         * @class SubTexture SubTexture.h "Renderer/Tex/SubTexture.h"
         *
         * @brief Klasa odpowiedzialna za przechowywanie informacji o subteksturach
         **************************************************/
        class SubTexture : public BaseTexture
        {
        private:
            sf::Vector2f _position;

            Texture * texPtr;

        public:
            SubTexture() : BaseTexture(), _position(), texPtr(nullptr)
            {}

            SubTexture(std::string alians, std::string group, std::string title, sf::Vector2f size, int id, sf::Vector2f pos, Texture * tex) :
                BaseTexture(alians, group, title, size, id), _position(pos), texPtr(tex)
            {}

            ~SubTexture() {
                texPtr = nullptr;
            }

        public:
            void setPosition(sf::Vector2f pos) {
                _position = pos;
            }

            void setSize(sf::Vector2f size) {
                _size = size;
            }

            sf::Vector2f position() const {
                return _position;
            }

            sf::Vector2f size() const {
                return _size;
            }

        }; /* class SubTexture */

    } /* namespace Tex */

} /* namespace Renderer */

#endif /* __RENDERER_Tex_SUB_TEXTURE_H__ */
