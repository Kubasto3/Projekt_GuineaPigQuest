#ifndef GUINEAPIG_H
#define GUINEAPIG_H
#include "AnimatedSprite.h"

class GuineaPig : public AnimatedSprite
{
public:
    int zycia=3;
    GuineaPig  (sf::Vector2f pos);
    void animate(sf::Time elapsed);
};

#endif // GUINEAPIG_H
