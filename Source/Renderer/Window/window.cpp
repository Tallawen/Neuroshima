#include "window.h"

namespace Renderer
{

Window::Window()
	: RenderWindow()
{ }

Window::Window(sf::VideoMode _mode, const sf::String &_title, sf::Uint32 _style, const sf::ContextSettings &_settings)
	: RenderWindow(_mode, _title, _style, _settings)
	, mode(_mode)
	, title(_title)
	, style(_style)
	, settings(_settings)
{ }
	

//Window::Window(sf::WindowHandle handle, const sf::ContextSettings& settings)
//	: Window(handle, settings)
//	, _settings(settings)
//{ }


void Window::resize(const sf::Vector2u &_size)
{
	mode.width = _size.x;
	mode.height = _size.y;
	this->setSize(_size);
}




void Window::setStyle(sf::Uint32 _style)
{
	style = _style;
	this->create(mode, title, style, settings);
}




sf::Sprite Window::screenShot()
{
	_screenShot.loadFromImage(this->capture());
	return sf::Sprite(_screenShot);
}




void Window::onResize()
{
	this->setView(sf::View(sf::FloatRect(0.0f, 0.0f, static_cast<float>(this->getSize().x), static_cast<float>(this->getSize().y))));
}

} // namespace Renderer