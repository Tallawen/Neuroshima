#include "Authors.h"

#include "../../StdAfx.h"

namespace Screen {

    /************************************************/
    Authors::Authors() : shape(50) {
        LOG << LOG_INFO(LMsg::Info) << "Create" << std::endl;

        shape.setFillColor(sf::Color(150, 50, 250));
        shape.setOutlineColor(sf::Color(250, 150, 100));
        shape.setPosition(100, 100);

        autoDelete(true);
    }


    /************************************************/
    Authors::~Authors() {
        LOG << LOG_INFO("Delete") << std::endl;
    }


    /************************************************/
    void Authors::process(sf::Event &event) {


    }


    /************************************************/
    void Authors::update(const float &delta) {

    }


    /************************************************/
    void Authors::open() {

    }


    /************************************************/
    void Authors::close() {

    }


    /************************************************/
    void Authors::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.clear(sf::Color::Red);

        target.draw(shape);
    }

}
