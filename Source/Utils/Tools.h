#ifndef __UTILS_TOOLS_H__
#define __UTILS_TOOLS_H__

#include <string>

namespace Utils {

    namespace Tools {

        /**********************************************//**
          Funkcje powiązane z plikami
         ************************************************/
        namespace File {

            /**********************************************//**
              @brief Sprawdza czy plik istnieje
             ************************************************/
            bool exists(const std::string &filename);

        }

    }

}

#endif /*__UTILS_TOOLS_H__*/
