#include "glaz.h"
#include <cmath>

Glaz::Glaz()
{

}

Glaz::Glaz(int x,int y,sf::Texture *tekstura, bool kieruneczek)
{
    setPosition(x,y);
    setTexture(*tekstura);
    kierunek=kieruneczek;
    position_startowa=getPosition();
    vel=rand()%150+50;//Nadanie głazowi losowej prędkości z danego przedziału
}

void Glaz::animate(sf::Time time){
    pos_obecna=getPosition();
    add_animation_frame(time);//animacja
    //"dryfowanie obiektu"; obiekt porusza się w obie strone pewnej wyznaczonej ścieżki; liczona jest tutaj odległośc obiektu od punktu za pomocą wzoru
    // odległośc=sqrt(współrzędne_1^2/współrzędne_2^2)
    if(kierunek==true){
        move(vel*time.asSeconds(),0*time.asSeconds());
        if(std::sqrt((position_startowa.x-pos_obecna.x)*(position_startowa.x-pos_obecna.x))>=140){
            position_startowa=pos_obecna;
            vel=vel*-1;
        }
    }else{
        move(0*time.asSeconds(),vel*time.asSeconds());
        if((std::sqrt((position_startowa.y-pos_obecna.y)*(position_startowa.y-pos_obecna.y))>=140)){
            position_startowa=pos_obecna;
            vel=vel*-1;
        }
    }
}
