#ifndef GUINEAPIG_H
#define GUINEAPIG_H
#include "animatedsprite.h"

class GuineaPig : public AnimatedSprite
{
public:
    int zycia=3;
    GuineaPig  (int,int, sf::Texture *x);
    // Poruszanie się klawiszami:
    virtual void animate(sf::Time elapsed);
    virtual ~GuineaPig();
};

#endif // GUINEAPIG_H
