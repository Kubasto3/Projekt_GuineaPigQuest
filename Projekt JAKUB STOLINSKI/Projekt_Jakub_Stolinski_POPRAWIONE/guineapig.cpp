#include "guineapig.h"


GuineaPig::~GuineaPig(){

}

void GuineaPig::animate(sf::Time elapsed){
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    add_animation_frame(elapsed);
    pos_obecna=getPosition();
    // Poruszanie się klawiszami:
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        if(rectangle_bounds.top<=0)
        {
        }
        else
        {
            move(0,
                 -150*elapsed.asSeconds());
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(rectangle_bounds.top+rectangle_bounds.height>=800)
        {

        }
        else
        {
            move(0,
                 150*elapsed.asSeconds());
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if( rectangle_bounds.left<=0)
        {

        }
        else
        {
            //setScale(-1,1);
            //setPosition(pos_obecna.x,pos_obecna.y);
            move(-150*elapsed.asSeconds(),
                 0);
        }

    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(rectangle_bounds.left+rectangle_bounds.width>=1000)
        {

        }
        else
        {
            //setScale(1,1);
            //setPosition(pos_obecna.x,pos_obecna.y);
            move(150*elapsed.asSeconds(),
                 0);
        }
    }
}

GuineaPig::GuineaPig(int x,int y,sf::Texture *tekstura){
    setPosition(x,y);
    setTexture(*tekstura);
}
