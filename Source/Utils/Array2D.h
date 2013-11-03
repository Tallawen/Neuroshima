/* TODO: Dokończyć dokumentację */

#ifndef __UTILS_ARRAY2D_H__
#define __UTILS_ARRAY2D_H__

#include <sstream>
#include <type_traits>

namespace Utils {

    /**********************************************//**
      @brief Tablica dwuwymiarowa

      Klasa została przetestowana tylko w praktyce :P | TODO : Przetestować
     ************************************************/
    template<typename T> class Array2D {
    private:
        T *array;

        int _width;
        int _height;

    public:
        /************************************************/
        Array2D() {
            array = nullptr;

            _width  = 0;
            _height = 0;
        }


        /************************************************/
        Array2D(const int &width, const int &height) : Array2D() {
            create(width, height);;
        }


        /************************************************/
        ~Array2D() {
            destroy();
        }

    public:
        /**********************************************//**
          @brief Tworzy nową tablicę.

          Gdy tablica już istnieje lub długość/szerokość jest mniejsza bądź równa 0 to tablica nie zostanie utworzona.

          @return Zwraca informację czy tablica została utworzona
         ************************************************/
        bool create(const int &width, const int &height) {
            if(width <= 0 || height <= 0)
                return false;

            if(array != nullptr)
                return false;

            _width  = width;
            _height = height;

            array = new T[width * height];

          return true;
        }


        /**********************************************//**
          @brief Metoda niszcząca tablicę.

          Niszczeniu nie podlegają elementy tablicy.
          Odnośnie niszczenia elementów istnieje statyczna @link DestroyAll
         ************************************************/
        void destroy() {
            if(array == nullptr)
                return;

            delete array;
            array = nullptr;
        }


        /************************************************/
        int width() const { return _width; }


        /************************************************/
        int height() const { return _height; }


        /**********************************************//**
          @brief Dostęp do elementu podając poszczególne indexy

          @exception std::range_error Gdy nie mieścimy się w przedziale tablicy
         ************************************************/
        T& at(const int &x, const int &y) throw(std::range_error) {
            if(x < 0 || y < 0 || x >= _width || y >= _height) {
                 std::ostringstream ss;
                ss << "Ojj troche Cie wywialo (x = " << x << ", width = " << _width << " | y = " << y << ", height = " << _height << ")";

                throw std::range_error(ss.str());
            }

          return array[y * _width + x];
        }


        /**********************************************//**
          @brief Dostęp do elementu podając index w postaci @b y*width+x

          @exception std::range_error Gdy nie mieścimy się w przedziale tablicy
         ************************************************/
        T& operator[] (const int &idx) throw(std::range_error) {
            if(idx < 0 || idx >= _width * _height) {
                 std::ostringstream ss;
                ss << "Ojj troche Cie wywialo (min = 0, idx = " << idx << ", max = " << _width * _height << ")";

                throw std::range_error(ss.str());
            }

          return array[idx];
        }


        /**********************************************//**
          @brief Metoda inicjalizuje elementy (wskaźniki) tablic na nullptr.

          @mark Ostrożnie z nią (nie uzuniemy danych gdy ją za wczasu użyjemy)
         ************************************************/
        static void InitialAllPtr(Array2D<T> &array) {
            if(!std::is_pointer<T>::value)
                return;

            if(array == nullptr)
                return;

            for(int i = 0; i < array.width() * array.height(); ++i) {
                array[i] = nullptr;
            }
        }


        /**********************************************//**
          @brief Metoda kasuje wszystkie elementy z pamięci (gdy @b T jest wskaźnikiem).
         ************************************************/
        static void DestroyAll(Array2D<T> &array) {
            if(!std::is_pointer<T>::value)
                return;

            if(array == nullptr)
                return;

            for(int i = 0; i < array.width() * array.height(); ++i) {
                if(array[i] != nullptr) {
                    delete array[i];
                    array[i] = nullptr;
                }
            }
        }
    };

}

#endif /*__UTILS_ARRAY2D_H__*/
