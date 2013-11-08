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

            sf::Vector2f _size;

            int _id;

            Texture * texPtr;

        public:
            SubTexture() : _position(), _size(), _id(), texPtr(nullptr)
            {}

            SubTexture(sf::Vector2f pos, sf::Vector2f size, int id, Texture tPtr) :
                _position(pos), _size(size), _id(id), texPtr(tPtr)
            {}

            ~SubTexture() {
                texPtr = nullptr;
            }

        public:
            sf::Texture texture(const int &id) {
              //  return texPtr->texture(_id).
               // return // texPtr->texture(_id).
                return sf::Texture;
            }

            sf::Texture texture(const std::string &name) {
                return sf::Texture;
            }

            void setPosition(sf::Vector2f pos) {
                _position = pos;
            }

            void setSize(sf::Vector2f size) {
                _size = size;
            }

            int id() const {
                return _id;
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
