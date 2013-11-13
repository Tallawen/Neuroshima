#include "Screen.h"

namespace Screen {

    /************************************************/
    Screen::Screen() {
        current = nullptr;
        next    = nullptr;

        changeTimer = 0.0f;
        changeScreen = false;

        transitionColor = sf::Color::Black;
    }


    /************************************************/
    Screen::~Screen() {
        if(current != nullptr)
            delete current;

        if(next != nullptr)
            delete next;
    }


    /************************************************/
    void Screen::process(sf::Event &event) {
        if(current != nullptr && !changeScreen)
            current->process(event);
    }


    /************************************************/
    void Screen::update(const float &delta) {
        if(changeTimer >= 0) {
            changeTimer += delta;

            if(changeTimer > CHANGE_TIME/2.0f && changeScreen && next != nullptr) {
                changeScreen = false;

                if(current != nullptr) {
                    current->close();

                    if(current->autoDelete())
                        delete current;
                }

                current = next;
                next = nullptr;

                current->open();
            }

            if(changeTimer >= CHANGE_TIME)
                changeTimer = -1.0f;

        } else if(current != nullptr)
            current->update(delta);
    }


    /************************************************/
    void Screen::change(IScreen *screen, bool now, sf::Color color) {
        if(changeScreen && screen->autoDelete()) {
            delete screen;
          return;
        }

        changeScreen = true;
        transitionColor = color;

        if(now)
            changeTimer = CHANGE_TIME;
        else
            changeTimer = 0.0f;

        next = screen;
    }


    /************************************************/
    void Screen::draw(Renderer::Window *window) {
        static float alpha = 0;
        static sf::RectangleShape rectangle;

        if(current != nullptr)
            window->draw(*current);

        if(changeTimer >= 0.0f) {
            alpha = changeTimer/CHANGE_TIME * 2.0f;

            alpha = 1.0f - alpha;
            alpha *= alpha;
            alpha = 1.0f - alpha;

            transitionColor.a = sf::Uint8(255 * alpha);

            rectangle.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
            rectangle.setFillColor(transitionColor);

            window->draw(rectangle);
        }
    }

}
