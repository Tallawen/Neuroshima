#ifndef __UTILS_IDENTIFIER_H__
#define __UTILS_IDENTIFIER_H__

#include <unordered_map>

namespace Utils {

    /**********************************************//**
     * @brief Klasa tworząca ID dla poszczególnych grup
     ************************************************/
    class Identifier {
    private:
        static std::unordered_map<std::string, int> _ID; /**< Mapa przechowujaca następną wartość @b ID dla danej grupy */

        std::string group; /**< Nazwa grupy */

    public:
        /**********************************************//**/
        Identifier(std::string group) {
            this->group = group;

            if(_ID.find(group) == _ID.end())
                _ID[group] = 0;
        }

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

    std::unordered_map<std::string, int> Identifier::_ID;
}

#endif /*__UTILS_IDENTIFIER_H__*/

/**********************************************//**
 * @class Utils::Identifier Identifier.h "Utils/Identifier.h"
 * @ingroup Utils
 *
 * Klasa tworzy unikalne ID dla poszczególnych grup.
 * Może zostać odziedziczona lub używana jako obiekt.
 *
 * Przykład:
 *     - dziedziczenie
 *
 *    @code
 *    class Texture : protected Identifier {
 *    private:
 *        std::map<int, ....> data;
 *
 *    public:
 *        Texture() : Identifier("tex") { }
 *
 *         void add(...) {
 *            map[newID()] = ...; *
 *        }
 *        .
 *        .
 *        .
 *    };
 *    @endcode
 *
 *     - obiekt
 *     @code
 *     class Texture {
 *     private:
 *         std::map<int, ....> data;
 *         Utils::Identifier identifier;
 *
 *     public:
 *         Texture() : identifier("tex") { }
 *
 *         void add(...) {
 *             map[identifier.newID()] = ...; *
 *         }
 *
 *         .
 *         .
 *         .
 *     };
 *     @endcode
 *
 * @note Proponuję używać wariantu z dziedziczeniem.
 */
