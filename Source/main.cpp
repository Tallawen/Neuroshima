#include "StdAfx.h"

#include "Screen/Screen.h"

//#include "Manager.h"


int main() {
    Global global;
 //   Manager manager;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    Renderer::Window window(sf::VideoMode(800, 600), "Window", sf::Style::Default, settings);

    Renderer::FPSCounter fps;
    fps.setColor(sf::Color::Red);

    Screen::Screen screen;

    sf::Clock deltaTimer;
    float delta;

    screen.change(new Screen::Authors);

     sf::Event event;
    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            screen.process(event);

            if(event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                screen.change(new Screen::Intro);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                screen.change(new Screen::Authors);
        }

        delta = deltaTimer.restart().asSeconds();

        screen.update(delta);

        window.clear();

        screen.draw(&window);

        window.draw(fps);
        window.display();
    }
  return 0;
}
