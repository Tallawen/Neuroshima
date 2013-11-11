#include "Tools.h"

#include <fstream>

namespace Utils {

    namespace Tools {

        namespace File {

            /************************************************/
            bool exists(const std::string &filename) {
                std::ifstream file(filename);

                if(file.good()) {
                    file.close();
                  return true;
                }

                file.close();
              return false;
            }

        }

    }

}
