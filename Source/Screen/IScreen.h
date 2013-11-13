#ifndef __SCREEN_ISCREEN_H__
#define __SCREEN_ISCREEN_H__

#include <SFML/Graphics.hpp>

namespace Screen {

    /**********************************************//**
      @brief Interfejs ekranów
     ************************************************/
    class IScreen : public sf::Drawable {
    private:
        bool _autoDelete; /**< Czy ekran przy przejściu ma zostać automatycznie skasowany */

    public:
        /**********************************************//**
          @brief Wywołuje procesy danego ekranu
         ************************************************/
        virtual void process(sf::Event &event)  = 0;


        /**********************************************//**
          @brief Wykonuje obliczenia dla ekranu względem delty
         ************************************************/
        virtual void update(const float &delta) = 0;


        /**********************************************//**
          @brief Metoda wywoływana przy otwarciu ekranu
         ************************************************/
        virtual void open()  = 0;


        /**********************************************//**
          @brief Metoda wywoływana przy zamknięciu
         ************************************************/
        virtual void close() = 0;


        /**********************************************//**
          @brief Rysowanie
         ************************************************/
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;


        /************************************************/
        bool autoDelete() const { return _autoDelete; }


        /************************************************/
        void autoDelete(const bool &value) { _autoDelete = value; }
    };

}

#endif /*__SCREEN_ISCREEN_H__*/
