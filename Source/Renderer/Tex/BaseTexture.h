#ifndef __RENDERER_TEX_BASE_TEXTURE_H__
#define __RENDERER_TEX_BASE_TEXTURE_H__

#include "../../StdAfx.h"

namespace Renderer
{

    namespace Tex
    {
        /*/*************************************************
         * @ingroup RENDERER_TEX
         * @class BaseTexture BaseTexture.h "Renderer/Tex/BaseTexture
         *
         * @brief Podstawowa klasa tekstur do dziedziczenia
         */
        class BaseTexture
        {
        private:
            std::string _alians;

            std::string _group;

            std::string _title;

            sf::Vector2f _size;

            int _id;

        public:
            BaseTexture() : _alians(), _group(), _title(), _size(), _id()
            {}

            BaseTexture(std::string alians, std::string group, std::string title, sf::Vector2f size, int id) :
                _alians(alians), _group(group), _title(title), _size(size), _id(id)
            {}

        public:
            void setAlians(std::string alians) {
                _alians = alians;
            }

            std::string alians() const {
                return _alians;
            }

            void setGroup(std::string group) {
                _group = group;
            }

            std::string group() const {
                return _group;
            }

            void setSize(sf::Vector2f size) {
                _size = size;
            }

            sf::Vector2f size() const {
                return _size;
            }

            int id() const {
                return _id;
            }

        }; /* class BaseTexture */

    } /* namespace Tex */

} /* namespace Renderer */

#endif /* __RENDERER_TEX_BASE_TEXTURE_H__ */
