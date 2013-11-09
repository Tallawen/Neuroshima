#include "Identifier.h"

namespace Utils {

    std::map<std::string, int> Identifier::_ID;

    /**********************************************//**/
    Identifier::Identifier(std::string group) {
        this->group = group;

        if(_ID.find(group) == _ID.end())
            _ID[group] = 0;
    }

}
