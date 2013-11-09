#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "Utils/Pattern/Singleton.h"

#include "Renderer/Texture/Manager.h"

class Manager : public Utils::Pattern::Singleton<Manager> {
public:
    Renderer::Texture::Manager texture;

};

#ifndef Mgr
#define Mgr Manager::Instance()
#endif /*Mgr*/

#endif /*__MANAGER_H__*/
