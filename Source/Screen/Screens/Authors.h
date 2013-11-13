#ifndef __SCREEN_SCREENS_AUTHORS_H__
#define __SCREEN_SCREENS_AUTHORS_H__

#include "../IScreen.h"

namespace Screen {

    class Authors : public IScreen {
    public:
        sf::CircleShape shape;

    public:
        /************************************************/
        Authors();

        /************************************************/
        ~Authors();

    public:
        /************************************************/
        void process(sf::Event &event);

        /************************************************/
        void update(const float &delta);

        /************************************************/
        void open();

        /************************************************/
        void close();

        /************************************************/
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };

}

#endif /*__SCREEN_SCREENS_AUTHORS_H__*/
