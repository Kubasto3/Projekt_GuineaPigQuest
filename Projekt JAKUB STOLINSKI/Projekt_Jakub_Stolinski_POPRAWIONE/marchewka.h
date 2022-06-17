#ifndef MARCHEWKA_H
#define MARCHEWKA_H
#include "obstacle.h"

//obiekt zbierany podczas gry
//zawiera metoda pozwalającą "dryfować jej po określonym torze"
class Marchewka : public Obstacle
{
public:
    bool czy_zebrane=false;
    Marchewka();
    Marchewka(int,int,sf::Texture *x);
    virtual void animate(sf::Time elapsed);
    ~Marchewka()=default;

private:
    sf::Vector2f position_startowa;
    sf::Vector2f position_obecna;
    int vel=20;
};

#endif // MARCHEWKA_H
