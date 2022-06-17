#ifndef GLAZ_H
#define GLAZ_H
#include "obstacle.h"

class Glaz : public Obstacle
{
public:
    Glaz();
    virtual void animate(sf::Time);
    virtual ~Glaz()=default;
    Glaz(int,int,sf::Texture *x,bool);

private:
    bool kierunek;
    sf::Vector2f position_startowa;
    sf::Vector2f position_obecna;
    int vel=20;
};

#endif // GLAZ_H
