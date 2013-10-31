#ifndef __RENDERER_WINDOW_WINDOW_H__ /* Zmieniłem ponieważ przy większej ilości plików z takim define kod zostanie pominięty */
#define __RENDERER_WINDOW_WINDOW_H__

#include "..\..\StdAfx.h"

namespace Renderer
{


/**********************************************//**
 * @brief Klasa odpowiedziala za glowne okno
 ************************************************/
class Window : public sf::RenderWindow
{
private:
    sf::VideoMode            mode;
    sf::String               title;
    sf::Uint32               style;
    sf::ContextSettings      settings;
    sf::Texture             _screenShot;

public:
    /************************************************/
    Window();

    /************************************************/
    Window(sf::VideoMode _mode, const sf::String &_title, sf::Uint32 _style = sf::Style::Default, const sf::ContextSettings &_settings = sf::ContextSettings());
    
    
    //explicit Window(sf::WindowHandle handle, const sf::ContextSettings& settings = sf::ContextSettings::ContextSettings());

public: 
    /************************************************/
    void        resize(const sf::Vector2u &_size);

    /************************************************/
    void        setStyle(sf::Uint32 _style);

    /************************************************/
    sf::Sprite  screenShot();

protected:

    /************************************************/
    void onResize() override;

};


} // namespace Renderer
#endif // __RENDERER_WINDOW_WINDOW_H__
