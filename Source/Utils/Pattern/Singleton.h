#ifndef __UTILS_PATTERN_SINGLETON_H__
#define __UTILS_PATTERN_SINGLETON_H__

#include <cassert>

namespace Utils {

    namespace Pattern {

        template<typename T> class Singleton {
        private:
            static T *_Instance;

        public:
            /************************************************/
            Singleton() {
                assert(_Instance == nullptr);

                int offset = (int)(T*)1 - (int)(Singleton<T>*)(T*)1;
                _Instance = (T*)((int)this - offset);
            }

            /************************************************/
            ~Singleton() {
                assert(_Instance != nullptr);

                _Instance = nullptr;
            }

        public:
            /************************************************/
            static T& Instance() {
                assert(_Instance != nullptr);

              return *_Instance;
            }


            /************************************************/
            static T* InstancePtr() {
                assert(_Instance != nullptr);

              return _Instance;
            }
        };

        template<typename T> T* Singleton<T>::_Instance = nullptr;

    }

}

#endif /*__UTILS_PATTERN_SINGLETON_H__*/
