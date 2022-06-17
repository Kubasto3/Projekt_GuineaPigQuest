#include "marchewka.h"
#include <cmath>


Marchewka::Marchewka()
{

}

Marchewka::Marchewka(int x,int y, sf::Texture *tekstura)
{
  setPosition(x,y);
  setTexture(*tekstura);
  position_startowa=getPosition();
}

void Marchewka::animate(sf::Time time){
    pos_obecna=getPosition();
    move(0*time.asSeconds(),vel*time.asSeconds());
    if((std::sqrt((position_startowa.y-pos_obecna.y)*(position_startowa.y-pos_obecna.y))>=15)){
        position_startowa=pos_obecna;
        vel=vel*-1;
    }
}
