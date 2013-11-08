#include "StdAfx.h"

int main() {
    Global global;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    Renderer::Window window(sf::VideoMode(800, 600), "Window", sf::Style::Default, settings);

     sf::Event event;
    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

  return 0;
}
