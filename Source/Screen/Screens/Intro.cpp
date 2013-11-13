#include "Intro.h"

#include "../../StdAfx.h"

namespace Screen {

    /************************************************/
    Intro::Intro() : shape(50) {
        LOG << LOG_INFO(LMsg::Info) << "Create" << std::endl;

        shape.setFillColor(sf::Color(150, 50, 250));
        shape.setOutlineColor(sf::Color(250, 150, 100));

        autoDelete(true);
    }


    /************************************************/
    Intro::~Intro() {
        LOG << LOG_INFO("Delete") << std::endl;
    }


    /************************************************/
    void Intro::process(sf::Event &event) {


    }


    /************************************************/
    void Intro::update(const float &delta) {

    }


    /************************************************/
    void Intro::open() {

    }


    /************************************************/
    void Intro::close() {

    }


    /************************************************/
    void Intro::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.clear(sf::Color::Blue);

        target.draw(shape);
    }

}
