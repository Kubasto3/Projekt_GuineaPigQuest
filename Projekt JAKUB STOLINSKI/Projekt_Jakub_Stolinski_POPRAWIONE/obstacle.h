#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "animatedsprite.h"


class Obstacle : public AnimatedSprite
{
public:
    Obstacle();
    Obstacle(int, int,sf::Texture *x,int);
    //"dryfowanie obiektu"; obiekt porusza się w obie strone pewnej wyznaczonej ścieżki; liczona jest tutaj odległośc obiektu od punktu za pomocą wzoru
    // odległośc=sqrt(współrzędne_1^2/współrzędne_2^2)
    virtual void animate(sf::Time time);
    virtual ~Obstacle();
};

#endif // OBSTACLE_H
