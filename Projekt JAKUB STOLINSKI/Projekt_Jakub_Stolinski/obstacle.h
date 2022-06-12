#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "AnimatedSprite.h"


class Obstacle : public AnimatedSprite
{
public:
    bool czy_glaz_poziomo=false;
    bool czy_glaz_pionowo=false;
    int prekosc_pozioma=20;
    int prekosc_pionowa=20;
    int odleglosc_ruchu=120;
    bool czy_zebrane=false;
    sf::Vector2f position_startowa=(sf::Vector2f(0,0));
    Obstacle();

    void animate(sf::Time time);
};

#endif // OBSTACLE_H
