#ifndef __RENDERER_TEXTURE_TEXTURE_H__
#define __RENDERER_TEXTURE_TEXTURE_H__

#include "../../StdAfx.h"

#include "BaseTexture.h"
#include "SubTexture.h"

namespace Renderer {

    namespace Texture {

        /**********************************************//**
         @brief Klasa odpowiedzialna za przechowywanie informacji o teksturach
        ************************************************/
        class Texture : public BaseTexture {
        private:
            std::string _filename;

            std::map<int, SubTexture> _subTexture;

            std::map<std::string, int> _subTextureNameIndex;

        public:
            /************************************************/
            Texture();


            /************************************************/
            Texture(const std::string &alians, const std::string &group, const std::string &title, const sf::Vector2f &size, const std::string &filename, const int &id);


            /************************************************/
            ~Texture();

        public:
            /************************************************/
            void setFilename(const std::string &filename) {
                _filename = filename;
            }


            /************************************************/
            std::string filename() const {
                return _filename;
            }


            /************************************************/
            bool haveSubTexture() const {
                return !_subTexture.empty();
            }


            /************************************************/
            bool attachSubTexture(const SubTexture &sub);


            /************************************************/
            bool detachSubTexture(const int &id);


            /************************************************/
            bool detachSubTexture(const std::string &name);


            /************************************************/
            bool valid() const;


            /************************************************/
            std::string name() const;

        }; /* class Texture */

    } /* namespace Texture */

} /* namespace Renderer */

#endif /* __RENDERER_TEXTURE_TEXTURE_H__ */
