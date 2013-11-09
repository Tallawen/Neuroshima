#ifndef __RENDERER_TEX_MANAGER_H__
#define __RENDERER_TEX_MANAGER_H__

#include "../../StdAfx.h"
#include "../../Utils/Identifier.h"
#include "Texture.h"

namespace Renderer
{
    namespace Tex
    {
        /*/*************************************************
         * @ingroup RENDERER_TEX
         * @class Manager Manager.h "Renderer/Tex/Manager.h"
         *
         * @brief Klasa obslugujaca tekstury
         **************************************************/
        class Manager
                : protected Utils::Identifier
        {
        private:
            //std::map<Texture, sf::Texture> _textures;

        }; /* class TextureManager */

    } /* namespace Tex */

} /* namespace Renderer */

#endif /* __RENDERER_TEX_MANAGER_H__ */
