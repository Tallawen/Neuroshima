#ifndef __RENDERER_TEXTURE_MANAGER_H__
#define __RENDERER_TEXTURE_MANAGER_H__

#include "../../StdAfx.h"
#include "../../Utils/Identifier.h"

#include "Texture.h"

namespace Renderer {

    namespace Texture {

        /**********************************************//**
          @brief Klasa obslugujaca tekstury
         ************************************************/
        class Manager : protected Utils::Identifier {
        private:
            std::map<int, sf::Texture> textures;

            /* TODO: Jednak textures muszą mieć osobne indexy :( albo i nie
             * SubTexture muszą mieć też nadawane id z Managera (tylko kiedy i jak)
             */

            std::map<int, Texture> texturesResource;
            std::map<std::string/*grupa*/, std::map<std::string/*nazwa*/, int>> texturesIndexName;

            std::list<std::string> _loadGroup;

        public:
            Manager();
            ~Manager();

        public:
            int attach(Texture texture);
            //int attach(sf::Texture texture);

            bool detach(const int &id);
            bool detach(const std::string &group, const std::string &name);

            bool fDetach(const int &id);

           // int load();
          //  int unload();

      //      std::string loadGroup() const;

        //    sf::Texture& texture();

       //     Texture & textureResource();

        private:
            inline bool validTextureName(const Texture &texture) const;
            inline std::string textureName(const Texture &texture) const;

        };

    }

}

#endif /*__RENDERER_TEXTURE_MANAGER_H__*/
