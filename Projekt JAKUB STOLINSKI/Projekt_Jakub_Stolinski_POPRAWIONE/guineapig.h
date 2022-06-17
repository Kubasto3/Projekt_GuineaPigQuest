#ifndef GUINEAPIG_H
#define GUINEAPIG_H
#include "animatedsprite.h"

//Klasa głównego bohatera
//Posiada zaimplementowaną metodą poruszania się za pomocą klawiatury, oraz licznik życia
class GuineaPig : public AnimatedSprite
{
public:
    int zycia=3;
    int zebrane=0;
    GuineaPig  (int,int, sf::Texture *x);
    // Poruszanie się klawiszami:
    virtual void animate(sf::Time elapsed);
    virtual ~GuineaPig();
};

#endif // GUINEAPIG_H
