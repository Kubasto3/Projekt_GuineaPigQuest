#include "AnimatedSprite.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

AnimatedSprite::AnimatedSprite()
{

}

void AnimatedSprite::add_animation_frame(int fps){
    if(fps<25){
        setTextureRect(sf::IntRect(11, 11, 28, 28));
    }else if (fps<50){
        setTextureRect(sf::IntRect(61, 11, 28, 28));
    }else if (fps<75){
        setTextureRect(sf::IntRect(111, 11, 28, 28));
    }else{
        setTextureRect(sf::IntRect(161, 11, 28, 28));
    }
}
