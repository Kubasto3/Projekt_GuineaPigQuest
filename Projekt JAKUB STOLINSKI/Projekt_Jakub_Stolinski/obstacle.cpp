#include "obstacle.h"
#include <cmath>

Obstacle::Obstacle()
{

}

void Obstacle::animate(sf::Time time){
    pos_obecna=getPosition();
    if(czy_glaz_poziomo==true){
        move(prekosc_pozioma*time.asSeconds(),0*time.asSeconds());
        if(std::sqrt((position_startowa.x-pos_obecna.x)*(position_startowa.x-pos_obecna.x))>=odleglosc_ruchu){
            position_startowa=pos_obecna;
            prekosc_pozioma=prekosc_pozioma*-1;
        }
    }else if(czy_glaz_pionowo==true){
        move(0*time.asSeconds(),prekosc_pionowa*time.asSeconds());
        if((std::sqrt((position_startowa.y-pos_obecna.y)*(position_startowa.y-pos_obecna.y))>=odleglosc_ruchu)){
            position_startowa=pos_obecna;
            prekosc_pionowa=prekosc_pionowa*-1;
        }
    }
}
