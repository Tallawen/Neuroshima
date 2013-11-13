#ifndef __SCREEN_SCREENS_INTRO_H__
#define __SCREEN_SCREENS_INTRO_H__

#include "../IScreen.h"

namespace Screen {

    class Intro : public IScreen {
    public:
        sf::CircleShape shape;

    public:
        /************************************************/
        Intro();

        /************************************************/
        ~Intro();

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

#endif /*__SCREEN_SCREENS_INTRO_H__*/
