#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

namespace Renderer
{


/**********************************************//**
 * @brief Klasa odpowiedziala za g³ówne okno
 ************************************************/
class Window : public sf::RenderWindow
{
private:
	sf::VideoMode			mode;
	sf::String				title;
	sf::Uint32				style;
	sf::ContextSettings		settings;
	sf::Texture				_screenShot;

public:
	/************************************************/
	Window();

	/************************************************/
	Window(sf::VideoMode _mode, const sf::String &_title, sf::Uint32 _style = sf::Style::Default, const sf::ContextSettings &_settings = sf::ContextSettings::ContextSettings());
	
	
	//explicit Window(sf::WindowHandle handle, const sf::ContextSettings& settings = sf::ContextSettings::ContextSettings());

public: 
	/************************************************/
	void		resize(const sf::Vector2u &_size);

	/************************************************/
	void		setStyle(sf::Uint32 _style);

	/************************************************/
	sf::Sprite	screenShot();

protected:

	/************************************************/
	virtual void onResize() override;

};


} // namespace Renderer
#endif // __WINDOW_H__