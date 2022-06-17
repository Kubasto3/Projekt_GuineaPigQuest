#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "guineapig.h"
#include "marchewka.h"
#include "glaz.h"
#include <iostream>


using namespace std;

int main()
{
    //Wgranie tekstór do przycisków, postaci, oraz pozostałych obiektów + utworzenie tych obiektów

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Guinea Pig quest!");

    sf::Texture texture_tlo;
    if (!texture_tlo.loadFromFile("Tlo.png")) {
        return 1;
    }

    sf::Texture texture_button1;
    if (!texture_button1.loadFromFile("Przycisk_poziom1.png")) {
        return 1;
    }

    sf::Texture texture_button2;
    if (!texture_button2.loadFromFile("Przycisk_poziom2.png")) {
        return 1;
    }

    sf::Texture texture_ogrze;
    if (!texture_ogrze.loadFromFile("Przycisk_ogrze.png")) {
        return 1;
    }

    sf::Texture texture_swinka;
    if (!texture_swinka.loadFromFile("swinka.png")) {
        return 1;
    }

    sf::Texture texture_sciana;
    if (!texture_sciana.loadFromFile("korzen.png")) {
        return 1;
    }

    sf::Texture texture_glaz;
    if (!texture_glaz.loadFromFile("glaz.png")) {
        return 1;
    }

    sf::Texture texture_marchewka;
    if (!texture_marchewka.loadFromFile("marchewka.png")) {
        return 1;
    }
    sf::Image icon;
    icon.loadFromFile("marchewka.png");
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("muzyka.wav")){
        return 1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    sf::Sprite Tlo;
    Tlo.setTexture(texture_tlo);


    GuineaPig Mufik(140,345,&texture_swinka);

    std::vector<std::unique_ptr<Obstacle>> wektor;
    wektor.emplace_back(make_unique<Obstacle>(100,300,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(200,300,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(300,300,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(100,400,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(200,400,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(300,400,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(110,305,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(390,300,&texture_sciana,270));
    wektor.emplace_back(make_unique<Obstacle>(400,200,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(500,200,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(500,300,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(500,400,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(500,500,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(400,400,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(400,600,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(500,600,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(600,600,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(700,600,&texture_sciana,90));
    wektor.emplace_back(make_unique<Obstacle>(600,700,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(500,700,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(400,700,&texture_sciana,0));
    wektor.emplace_back(make_unique<Obstacle>(400,500,&texture_sciana,90));

    wektor.emplace_back(make_unique<Glaz>(273,282,&texture_glaz,false));
    wektor.emplace_back(make_unique<Glaz>(366,261,&texture_glaz,true));
    wektor.emplace_back(make_unique<Glaz>(518,581,&texture_glaz,false));
    wektor.emplace_back(make_unique<Marchewka>(423,210,&texture_marchewka));
    wektor.emplace_back(make_unique<Marchewka>(624,630,&texture_marchewka));



    std::vector<std::unique_ptr<Obstacle>> wektor2;
    wektor2.emplace_back(make_unique<Obstacle>(100,300,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(200,300,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(300,400,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(100,400,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(200,400,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(300,200,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(110,305,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(300,100,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(400,100,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(500,100,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(600,100,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(700,100,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(800,100,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(300,100,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(900,100,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(800,200,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(500,200,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(600,200,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(400,200,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(400,200,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(400,300,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(400,400,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(600,200,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(600,300,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(600,400,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(500,400,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(600,500,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(500,600,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(400,600,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(400,500,&texture_sciana,0));
    wektor2.emplace_back(make_unique<Obstacle>(400,500,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(700,200,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(700,300,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(700,400,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(800,200,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(800,300,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(800,400,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(700,500,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(800,500,&texture_sciana,90));
    wektor2.emplace_back(make_unique<Obstacle>(700,600,&texture_sciana,0));

    wektor2.emplace_back(make_unique<Glaz>(255,282,&texture_glaz,false));
    wektor2.emplace_back(make_unique<Glaz>(447,458,&texture_glaz,true));
    wektor2.emplace_back(make_unique<Glaz>(624,75,&texture_glaz,false));
    wektor2.emplace_back(make_unique<Glaz>(430,80,&texture_glaz,false));
    wektor2.emplace_back(make_unique<Glaz>(662,344,&texture_glaz,true));
    wektor2.emplace_back(make_unique<Marchewka>(433,549,&texture_marchewka));
    wektor2.emplace_back(make_unique<Marchewka>(840,147,&texture_marchewka));
    wektor2.emplace_back(make_unique<Marchewka>(722,561,&texture_marchewka));

    bool Poziom1_flaga=false;
    bool Poziom2_flaga=false;
    bool ogrze_flaga=false;
    AnimatedSprite *wsk=&Mufik;

    sf::Clock clock;
    while (window.isOpen()) {
        window.draw(Tlo);
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    //std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            }
        }
        //window.clear(sf::Color::Black);
        for(auto &i: wektor2){
            if(Mufik.getGlobalBounds().intersects(i->getGlobalBounds())){
                Mufik.setPosition(140,345);
                Mufik.zycia=Mufik.zycia-1;
            }
            i->animate(elapsed);
            window.draw(*i);
        }
        wsk->animate(elapsed);
        window.draw(Mufik);
        std::cerr<<elapsed.asMicroseconds()<<std::endl;
        window.display();
    }

    return 0;
}
