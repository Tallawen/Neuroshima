#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "Utils/Pattern/Singleton.h"

#include "Utils/Logger.h"

class Global : public Utils::Pattern::Singleton<Global> {
public:
    Utils::Logger *logger;

public:
    /************************************************/
    Global();

    /************************************************/
    ~Global();
};

#ifndef LOG
#define LOG (*Global::Instance().logger)
#endif /*LOG*/

#endif /*__GLOBAL_H__*/
