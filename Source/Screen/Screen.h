#ifndef __SCREEN_SCREEN_H__
#define __SCREEN_SCREEN_H__

#include <SFML/Graphics.hpp>

#include "../Renderer/Window/Window.h"

#include "IScreen.h"

/* Podpinamy tutaj dodane ekrany */
#include "Screens/Authors.h"
#include "Screens/Intro.h"

namespace Screen {

    /**********************************************//**
      @brief Klasa do zmiany stanów między ekranami
     ************************************************/
    class Screen {
    private:
        const float CHANGE_TIME = 3.0f; // TODO: Dodać do pliku ini lub gdzieś indziej (to nie jest za dobre miejsce)*/

        IScreen *next; /**< Screen jaki ma zostać otworzony */
        IScreen *current; /**< Screen obecny */

        float changeTimer; /**< Timer odnośnie przejścia */
        bool changeScreen; /**< Czy zmieniamy screen */

        sf::Color transitionColor; /**< Kolor przejścia */

    public:
        /************************************************/
        Screen();


        /************************************************/
        ~Screen();

    public:
        /**********************************************//**
          @brief Wywołuje procesy danego ekranu
         ************************************************/
        void process(sf::Event &event);


        /**********************************************//**
          @brief Wykonuje obliczenia dla danej klatki
         ************************************************/
        void update(const float &delta);


        /**********************************************//**
          @brief Zmienia ekran

          @param screen Wskaźnik na nowy ekran który ma zostać załadowany
          @param now    Czy ekran ma zostać zmieniony natychmiastowo
          @param color  Jaki kolor ma zostać użyty do zmiany ekranu (gdy zmieniamy sposobem domyślnym)
         ************************************************/
        void change(IScreen *screen, bool now = false, sf::Color color = sf::Color::Black);


        /**********************************************//**
          @brief Rysuje daną klatkę
         ************************************************/
        void draw(Renderer::Window *window);
    };

}

#endif /*__SCREEN_SCREEN_H__*/
