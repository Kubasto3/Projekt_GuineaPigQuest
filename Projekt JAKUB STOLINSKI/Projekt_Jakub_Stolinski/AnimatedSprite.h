#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class AnimatedSprite : public sf::Sprite
{
public:
    sf::Vector2f pos_obecna=(sf::Vector2f(0,0));
    AnimatedSprite();
    void add_animation_frame(int fps);
    void dupa();
};

#endif // ANIMATEDSPRITE_H
