#ifndef __RENDERER_WINDOW_FPSCOUNTER_H__
#define __RENDERER_WINDOW_FPSCOUNTER_H__

#include "../../StdAfx.h"
#include <chrono>

namespace Renderer
{
    /******************************************//*
        Klasa liczy ile jest wyswietlanych klatek
        na sekunde. Oraz wyswietla ich ilosc.

        Do dzialania wymagane jest jednokrotne
        wyrysowanie obiektu co klatke.
    *********************************************/
    class FPSCounter : public sf::Transformable, public sf::Drawable
    {
        private:
            mutable std::chrono::time_point<std::chrono::high_resolution_clock> currTime;
            mutable std::chrono::time_point<std::chrono::high_resolution_clock> prevTime;
            mutable unsigned int    framesCount;
            mutable double          timeLimit;
            mutable double          _fps;

            bool        enabled;

            sf::Font    font;
            mutable sf::Text    fps_text;

        
        public:
            /******************************************//**/
            FPSCounter(const sf::Vector2f &_screen_position = sf::Vector2f(0.f, 0.f), const sf::Color &_color = sf::Color::Yellow, unsigned int _size = 20, const std::string &_font_name = "arial.ttf");
            /******************************************//**/
            ~FPSCounter();
        
        protected:
            /******************************************//**/
            void draw(sf::RenderTarget &_target, sf::RenderStates _states) const override;
            /******************************************//**/
            void fpsToString() const;
            /******************************************//**/
            void step() const;

        public:
            /******************************************//*
                zwraca wartosc liczbowa klatek na sekunde
            *********************************************/
            double fps();

            /******************************************//*
                ustawianie koloru tekstu
            *********************************************/
            void setColor(const sf::Color &_color);

            /******************************************//*
                ustawienie wielkosci czcionki
            *********************************************/
            void setFontSize(unsigned int _size);

            /******************************************//*
                wlaczenie/wylaczenie wyswietlania
            *********************************************/
            void enable(bool _on = true);
    };

}


#endif // __RENDERER_WINDOW_FPSCOUNTER_H__