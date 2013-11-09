#ifndef __RENDERER_TEXTURE_SUBTEXTURE_H__
#define __RENDERER_TEXTURE_SUBTEXTURE_H__

#include "../../StdAfx.h"

#include "BaseTexture.h"

namespace Renderer {

    namespace Texture {

        /**********************************************//**
          @brief Klasa odpowiedzialna za przechowywanie informacji o subteksturach
         ************************************************/
        class SubTexture : public BaseTexture {
        private:
            sf::Vector2f _position;

        public:
            /************************************************/
            SubTexture() : BaseTexture(), _position() { }


            /*SubTexture(std::string alians, std::string group, std::string title, sf::Vector2f size, int id, sf::Vector2f pos, Texture * tex) :
                BaseTexture(alians, group, title, size, id), _position(pos), texPtr(tex)
            {}*/


            /************************************************/
            ~SubTexture() { }

        public:
            /************************************************/
            void setPosition(sf::Vector2f pos) {
                if(pos.x >= 0 && pos.y >= 0)
                    _position = pos;
            }


            /************************************************/
            sf::Vector2f position() const {
                return _position;
            }

        }; /* class SubTexture */

    } /* namespace Texture */

} /* namespace Renderer */

#endif /* __RENDERER_TEXTURE_SUBTEXTURE_H__ */
