#include "FPSCounter.h"
#include <sstream>

namespace Renderer
{
    /*****************************************//**/
    FPSCounter::FPSCounter(const sf::Vector2f &_screen_position, const sf::Color &_color, unsigned int _size, const std::string &_font_name)
        : framesCount(0)
        , timeLimit(0.0)
        , _fps(0.0)
        , enabled(true)
        
    {
        currTime = prevTime = std::chrono::high_resolution_clock::now();

        font.loadFromFile(_font_name);
    
        fps_text.setFont(font);
        fps_text.setColor(_color);
        fps_text.setCharacterSize(_size);
    }

    /*****************************************//**/
    FPSCounter::~FPSCounter()
    { }

    /*****************************************//**/
    void FPSCounter::draw(sf::RenderTarget &_target, sf::RenderStates _states) const
    {
        if (enabled) {
            this->step();
            this->fpsToString();
            _states.transform *= this->getTransform();
            _target.draw(fps_text, _states);
        }
    }

    /*****************************************//**/
    void FPSCounter::fpsToString() const
    {
        std::stringstream sstr;
        sstr << _fps;

        fps_text.setString(sstr.str());
    }

    /*****************************************//**/
    void FPSCounter::step() const
    {
        currTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> delta = currTime - prevTime;
        timeLimit += delta.count();
        ++framesCount;
        if (timeLimit >= 1.0) {
            _fps = static_cast<double>(framesCount) / timeLimit;
            framesCount = 0;
            timeLimit = 0.0;
        }
        prevTime = currTime;
    }

    /*****************************************//**/
    double FPSCounter::fps()
    {
        return _fps;
    }

    /*****************************************//**/
    void FPSCounter::setColor(const sf::Color &_color)
    {
        fps_text.setColor(_color);
    }

    /*****************************************//**/
    void FPSCounter::setFontSize(unsigned int _font_size)
    {
        fps_text.setCharacterSize(_font_size);
    }

    /*****************************************//**/
    void FPSCounter::enable(bool _on)
    {
        enabled = _on;
    }

}