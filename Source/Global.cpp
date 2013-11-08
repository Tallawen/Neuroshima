#include "Global.h"

/************************************************/
Global::Global() {
    logger = new Utils::Logger(Utils::Logger::Stream::File, "logger.log", Utils::Logger::Openmode::Append);
}


/************************************************/
Global::~Global() {
    delete logger;
}
