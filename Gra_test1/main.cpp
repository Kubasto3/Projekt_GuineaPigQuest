#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class AnimatedSprite : public sf::Sprite{
public:
    void add_animation_frame(int fps){
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
};
//korzen sf::IntRect(0,0,104,16)
class Obstacle : public AnimatedSprite{
public:
    bool czy_glaz_poziomo=false;
    bool czy_glaz_pionowo=false;
    int prekosc_pozioma=20;
    int prekosc_pionowa=20;
    int odleglosc_ruchu=120;
    bool czy_zebrane=false;

    sf::Vector2f position_startowa=(sf::Vector2f(0,0));
    sf::Vector2f pos_obecna=(sf::Vector2f(0,0));
    Obstacle(){
    }
    void animate(sf::Time time){
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
};

class GuineaPig : public AnimatedSprite{
public:
    GuineaPig  (sf::Vector2f pos){
        setPosition(pos);
    }
    void animate(sf::Time elapsed){
        sf::FloatRect rectangle_bounds = getGlobalBounds();

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
                move(150*elapsed.asSeconds(),
                     0);
            }
        }
    }
};


int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");
    std::vector<std::unique_ptr<Obstacle>> wektor;

    sf::Texture texture_swinka;
    if (!texture_swinka.loadFromFile("swinka.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    GuineaPig Mufik(sf::Vector2f(140,345));
    Mufik.setTexture(texture_swinka);

    sf::Texture texture_sciana;
    if (!texture_sciana.loadFromFile("korzen.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }


    for(int i=0;i<=21;i++){
        std::unique_ptr<Obstacle> sciana = std::make_unique<Obstacle>();
        switch (i)
        {
        case 0:
            sciana->setPosition(100, 300);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 1:
            sciana->setPosition(200, 300);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 2:
            sciana->setPosition(300, 300);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 3:
            sciana->setPosition(100, 400);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 4:
            sciana->setPosition(200, 400);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 5:
            sciana->setPosition(300, 400);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 6:
            sciana->setPosition(110, 305);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 7:
            sciana->setPosition(390, 300);
            sciana->setTexture(texture_sciana);
            sciana->rotate(270);
            wektor.emplace_back(move(sciana));
            break;
        case 8:
            sciana->setPosition(400, 200);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 9:
            sciana->setPosition(500, 200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 10:
            sciana->setPosition(500, 300);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 11:
            sciana->setPosition(500, 400);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 12:
            sciana->setPosition(500, 500);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 13:
            sciana->setPosition(400, 400);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 14:
            sciana->setPosition(400, 500);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 15:
            sciana->setPosition(400, 600);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 16:
            sciana->setPosition(500, 600);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 17:
            sciana->setPosition(600, 600);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 18:
            sciana->setPosition(700, 600);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor.emplace_back(move(sciana));
            break;
        case 19:
            sciana->setPosition(600, 700);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 20:
            sciana->setPosition(500, 700);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;
        case 21:
            sciana->setPosition(400, 700);
            sciana->setTexture(texture_sciana);
            wektor.emplace_back(move(sciana));
            break;

        }
    }

    sf::Texture texture_glaz;
    if (!texture_glaz.loadFromFile("glaz.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    for(int i=0;i<=2;i++){
        std::unique_ptr<Obstacle> glaz = std::make_unique<Obstacle>();
        switch (i){
        case 0:
            glaz->setPosition(273, 282);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_pionowo=true;
            glaz->position_startowa=glaz->getPosition();
            wektor.emplace_back(move(glaz));
            break;
        case 1:
            glaz->setPosition(366, 261);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_poziomo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pozioma=100;
            wektor.emplace_back(move(glaz));
            break;
        case 2:
            glaz->setPosition(518, 581);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_pionowo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pionowa=80;
            wektor.emplace_back(move(glaz));
            break;
        }
    }
    sf::Texture texture_marchewka;
    if (!texture_marchewka.loadFromFile("marchewka.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    Obstacle Marchewka1;
    Marchewka1.setPosition(423, 211);
    Marchewka1.setTexture(texture_marchewka);
    Marchewka1.czy_glaz_pionowo=true;
    Marchewka1.position_startowa=Marchewka1.getPosition();
    Marchewka1.odleglosc_ruchu=15;

    Obstacle Marchewka2;
    Marchewka2.setPosition(624, 630);
    Marchewka2.setTexture(texture_marchewka);
    Marchewka2.czy_glaz_pionowo=true;
    Marchewka2.position_startowa=Marchewka2.getPosition();
    Marchewka2.odleglosc_ruchu=15;



    // run the program as long as the window is open
    sf::Clock clock;
    int timer_w=0;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if(event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        Mufik.animate(elapsed);
        Mufik.add_animation_frame(timer_w);
        timer_w++;
        if(timer_w==100){
            timer_w=0;
        }
        for(auto &i:wektor){
            if(Mufik.getGlobalBounds().intersects(i->getGlobalBounds())){
                std::cerr<<"Bum"<<std::endl;
                Mufik.setPosition(140,345);
            }
            i->animate(elapsed);
            if(i->czy_glaz_pionowo==true||i->czy_glaz_poziomo==true){
                i->add_animation_frame(timer_w);
            }
            window.draw(*i);
        }
        if(Mufik.getGlobalBounds().intersects(Marchewka1.getGlobalBounds())){
            Marchewka1.czy_zebrane=true;
        }
        if(Mufik.getGlobalBounds().intersects(Marchewka2.getGlobalBounds())){
            Marchewka2.czy_zebrane=true;
        }
        if(Marchewka1.czy_zebrane==false){
            Marchewka1.animate(elapsed);
            window.draw(Marchewka1);
        }
        if(Marchewka2.czy_zebrane==false){
            Marchewka2.animate(elapsed);
            window.draw(Marchewka2);
        }
        window.draw(Mufik);
        // end the current frame
        if(Marchewka1.czy_zebrane==true&&Marchewka2.czy_zebrane==true){
            std::cerr<<"Gratulacje!!"<<std::endl;
            //return 0;
        }
        window.display();
    }

    return 0;
}
