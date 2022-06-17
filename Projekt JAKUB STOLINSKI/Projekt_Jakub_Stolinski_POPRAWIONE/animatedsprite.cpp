#include "animatedsprite.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


//Ciągle odwarzenie animacji danego obiektu
void AnimatedSprite::add_animation_frame(sf::Time elapsed){
    if(elapsed.asMicroseconds()%2==0&&elapsed.asMicroseconds()<250){
        setTextureRect(sf::IntRect(11, 11, 28, 28));
    }else if (elapsed.asMicroseconds()%2!=0&&elapsed.asMicroseconds()<250){
        setTextureRect(sf::IntRect(61, 11, 28, 28));
    }else if (elapsed.asMicroseconds()%2==0&&elapsed.asMicroseconds()>250){
        setTextureRect(sf::IntRect(111, 11, 28, 28));
    }else{
        setTextureRect(sf::IntRect(161, 11, 28, 28));
    }
}

AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::~AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(int x, int y, sf::Texture tekstura)
{
    setPosition(x,y);
    setTexture(tekstura);
}

void animate(sf::Time elapsed){

}
