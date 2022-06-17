#include "obstacle.h"
#include <cmath>

Obstacle::Obstacle()
{

}

Obstacle::~Obstacle(){

}
//"dryfowanie obiektu"; obiekt porusza się w obie strone pewnej wyznaczonej ścieżki; liczona jest tutaj odległośc obiektu od punktu za pomocą wzoru
// odległośc=sqrt(współrzędne_1^2/współrzędne_2^2)
void Obstacle::animate(sf::Time time){

}

Obstacle::Obstacle(int x,int y,sf::Texture *tekstura,int kat){
    setPosition(x,y);
    setTexture(*tekstura);
    rotate(kat);
}
