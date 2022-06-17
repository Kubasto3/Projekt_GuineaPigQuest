#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class AnimatedSprite : public sf::Sprite
{
public:
    sf::Vector2f pos_obecna=(sf::Vector2f(0,0));
    AnimatedSprite(int, int, sf::Texture);
    AnimatedSprite();
    virtual ~ AnimatedSprite();
    //Ciągle odwarzenie animacji danego obiektu
    void add_animation_frame(sf::Time elapsed);
    virtual void animate(sf::Time elapsed)=0;
};

#endif // ANIMATEDSPRITE_H
