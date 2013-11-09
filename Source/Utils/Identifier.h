#ifndef __UTILS_IDENTIFIER_H__
#define __UTILS_IDENTIFIER_H__

#include <map>

namespace Utils {

    /**********************************************//**
     * @brief Klasa tworząca ID dla poszczególnych grup
     ************************************************/
    class Identifier {
    private:
        static std::map<std::string, int> _ID; /**< Mapa przechowujaca następną wartość @b ID dla danej grupy */

        std::string group; /**< Nazwa grupy */

    public:
        /**********************************************//**/
        Identifier(std::string group);

    public:
        /**********************************************//**
         * @brief Metoda zwracająca nową wartość ID
         ************************************************/
        int newID() {
          return _ID[group]++;
        }

        /**********************************************//**
         * @brief Metoda zwracająca ostatnią wartość ID
         ************************************************/
        int lastID() const {
          return _ID[group];
        }
    };

}

#endif /*__UTILS_IDENTIFIER_H__*/

/**********************************************//**
   @class Utils::Identifier Identifier.h "Utils/Identifier.h"
   @ingroup Utils

   Klasa tworzy unikalne ID dla poszczególnych grup.
   Może zostać odziedziczona lub używana jako obiekt.

   Przykład:
      - dziedziczenie

      @code
      class Texture : protected Identifier {
      private:
          std::map<int, ....> data;

      public:
          Texture() : Identifier("tex") { }

           void add(...) {
              data[newID()] = ...; *
          }
          .
          .
          .
      };
      @endcode

      - obiekt
      @code
      class Texture {
      private:
          std::map<int, ....> data;
          Utils::Identifier identifier;

      public:
          Texture() : identifier("tex") { }

          void add(...) {
              data[identifier.newID()] = ...; *
          }

          .
          .
          .
      };
      @endcode

   @note Proponuję używać wariantu z dziedziczeniem.
 ************************************************/
