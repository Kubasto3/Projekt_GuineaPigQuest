#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "guineapig.h"
#include "marchewka.h"
#include "glaz.h"

using namespace std;

int main()
{
    //Stworzenie okna:
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Guinea Pig quest!");

    //###################################Wgranie wszystkich plików zewnętrznych do gry:####################################################
    //Wgranie wszystkich tekstor:
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

    //Ustawienie ikony gry i jej nazwy w okienu .exe
    sf::Image icon;
    icon.loadFromFile("marchewka.png");
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

    //Włączenie dźwięku w tle gry:
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("muzyka.wav")){
        return 1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    //Ustawienie czcionki i rozmiaru napisów w grze; kolejno informacje o życiu graczach i opis gry w zakładce "o grze":
    sf::Font font;
    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        return 1;
    }
    sf::Text text_zycia;
    text_zycia.setFont(font);
    text_zycia.setString("Szanse: 3");
    text_zycia.setCharacterSize(30);
    text_zycia.setPosition(100,700);

    sf::Text text_ogrze;
    text_ogrze.setFont(font);
    text_ogrze.setString
            ("Unikaj ostrych korzeni oraz osuwajacych sie glazow! \nWygrasz kiedy zbierzesz wszystkie marchewki \n \n \n Poruszaj sie strzalkami \n Nacisnij \"R\", aby powrocic do menu \n Tworca: Jakub Stolinski 151191 \n Grafika: Lucja Swat");
    text_ogrze.setCharacterSize(30);
    text_ogrze.setPosition(100,300);

    //Ustawienie Tła gry:
    sf::Sprite Tlo;
    Tlo.setTexture(texture_tlo);

    //Stworzenie postaci gracza oraz przypisanie jej tesktury:
    GuineaPig Mufik(140,345,&texture_swinka);

    //###################################Stworzenie poziomów:####################################################
    //Stworzenie przeszkód na planszy numer 1 wraz z wgraniem im odpowiednich tekstór(ostre korzenie i głaz) i odpowiednie rozstawienie ich.
    //Obiekty są alokowane na stercie z użyciem std::unique_ptr
    std::vector<std::unique_ptr<Obstacle>> wektor;
    wektor.emplace_back(make_unique<Obstacle>(100,300,&texture_sciana,0)); //Krzewy:
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

    wektor.emplace_back(make_unique<Glaz>(273,282,&texture_glaz,false)); //Głazy:
    wektor.emplace_back(make_unique<Glaz>(366,261,&texture_glaz,true));
    wektor.emplace_back(make_unique<Glaz>(518,581,&texture_glaz,false));

    //Stworzenie przeszkód na planszy numer 2 wraz z wgraniem im odpowiednich tekstór(ostre korzenie i głaz) i odpowiednie rozstawienie ich.
    //Obiekty są alokowane na stercie z użyciem std::unique_ptr
    std::vector<std::unique_ptr<Obstacle>> wektor2;
    wektor2.emplace_back(make_unique<Obstacle>(100,300,&texture_sciana,0)); //Krzewy:
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

    wektor2.emplace_back(make_unique<Glaz>(255,282,&texture_glaz,false)); //Głazy:
    wektor2.emplace_back(make_unique<Glaz>(447,458,&texture_glaz,true));
    wektor2.emplace_back(make_unique<Glaz>(624,75,&texture_glaz,false));
    wektor2.emplace_back(make_unique<Glaz>(430,80,&texture_glaz,false));
    wektor2.emplace_back(make_unique<Glaz>(662,344,&texture_glaz,true));

    //Utworzenie marchewek oraz ich ułożenie na planszy:
    std::vector<Marchewka> wektor_marchewek;
    Marchewka Marchewka1(423,210,&texture_marchewka);
    wektor_marchewek.emplace_back(Marchewka1);
    Marchewka Marchewka2(624,610,&texture_marchewka);
    wektor_marchewek.emplace_back(Marchewka2);
    Marchewka Marchewka3(433,549,&texture_marchewka);
    wektor_marchewek.emplace_back(Marchewka3);
    Marchewka Marchewka4(840,147,&texture_marchewka);
    wektor_marchewek.emplace_back(Marchewka4);
    Marchewka Marchewka5(722,561,&texture_marchewka);
    wektor_marchewek.emplace_back(Marchewka5);

    //Flagi pozwalające na przełączeni się pomiędzy poziomami:
    bool Poziom1_flaga=false;
    bool Poziom2_flaga=false;
    bool ogrze_flaga=false;
    AnimatedSprite *wsk=&Mufik;

    //Utworzenie przycisków używanych z poziomu menu startowego:
    sf::Sprite Button1;
    Button1.setTexture(texture_button1);
    Button1.setPosition(400,250);

    sf::Sprite Button2;
    Button2.setTexture(texture_button2);
    Button2.setPosition(400,400);

    sf::Sprite Button3;
    Button3.setTexture(texture_ogrze);
    Button3.setPosition(400,550);

    sf::Clock clock;
    while (window.isOpen()) {
        window.draw(Tlo);
        sf::Time elapsed = clock.restart();
        sf::Event event;

        //Tworzenie menu tylko wtedy, kiedy żadna plansza nie powinna zostać włączona:
        if(Poziom1_flaga==false&&Poziom2_flaga==false&&ogrze_flaga==false){
            window.draw(Button1);
            window.draw(Button2);
            window.draw(Button3);
        }

        //Pętla przechwytująca wciśnięcie myszy oraz restart planszy za pomocą przycisku "R":
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    if(Button1.getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                        Poziom1_flaga=true;
                    }
                    if(Button2.getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                        Poziom2_flaga=true;
                    }
                    if(Button3.getGlobalBounds().contains(mouse_pos.x,mouse_pos.y)){
                        ogrze_flaga=true;
                    }
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                if(Poziom1_flaga==true){
                    Poziom1_flaga=false;
                    Marchewka1.czy_zebrane=false;
                    Marchewka2.czy_zebrane=false;
                    Mufik.setPosition(140,345);
                    Mufik.zycia=3;

                }
                if(Poziom2_flaga==true){
                    Poziom2_flaga=false;
                    Marchewka3.czy_zebrane=false;
                    Marchewka4.czy_zebrane=false;
                    Marchewka5.czy_zebrane=false;
                    Mufik.setPosition(140,345);
                    Mufik.zycia=3;
                }
                if(ogrze_flaga==true){
                    ogrze_flaga=false;
                }
            }
        }

        //###################################Utworzenie Poziomu 1:####################################################
        if(Poziom1_flaga==true){
            for(auto &i: wektor){
                //Zgranie wszystkich przeszkód z kontenera oraz sprawdzenie ich kolizji z główym bohaterem:
                if(Mufik.getGlobalBounds().intersects(i->getGlobalBounds())){
                    wsk->setPosition(140,345);
                    Mufik.zycia=Mufik.zycia-1;
                }
                i->animate(elapsed);
                window.draw(*i);
            }
            //Sprawdzenie kolizji z marchewkami oraz ich usunięcie:
            if(Mufik.getGlobalBounds().intersects(Marchewka1.getGlobalBounds())){
                Marchewka1.czy_zebrane=true;
            }
            if(Mufik.getGlobalBounds().intersects(Marchewka2.getGlobalBounds())){
                Marchewka2.czy_zebrane=true;
            }
            if(Marchewka1.czy_zebrane==false){
                wsk=&Marchewka1;
                wsk->animate(elapsed);
                window.draw(Marchewka1);
            }
            if(Marchewka2.czy_zebrane==false){
                wsk=&Marchewka2;
                wsk->animate(elapsed);
                window.draw(Marchewka2);
            }
            wsk=&Mufik;
            wsk->animate(elapsed);
            window.draw(Mufik);
            window.draw(text_zycia);
            //Wyjsice z planszy w wyniku utraty wszystkich żyć, lub zebrania wszystkich marchewek:
            if((Marchewka1.czy_zebrane==true&&Marchewka2.czy_zebrane==true)||Mufik.zycia<=0){
                Poziom1_flaga=false;
                Marchewka1.czy_zebrane=false;
                Marchewka2.czy_zebrane=false;
                Mufik.setPosition(140,345);
                Mufik.zycia=3;
            }
        }
        //###################################Utworzenie Poziomu 2:####################################################
        if(Poziom2_flaga==true){
            for(auto &i: wektor2){
                if(Mufik.getGlobalBounds().intersects(i->getGlobalBounds())){//Zgranie wszystkich przeszkód z kontenera oraz sprawdzenie ich kolizji z główym bohaterem:
                    wsk->setPosition(140,345);
                    Mufik.zycia=Mufik.zycia-1;
                }
                i->animate(elapsed);
                window.draw(*i);
            }//Sprawdzenie kolizji z marchewkami oraz ich usunięcie:
            if(Mufik.getGlobalBounds().intersects(Marchewka3.getGlobalBounds())){
                Marchewka3.czy_zebrane=true;
            }
            if(Mufik.getGlobalBounds().intersects(Marchewka4.getGlobalBounds())){
                Marchewka4.czy_zebrane=true;
            }
            if(Mufik.getGlobalBounds().intersects(Marchewka5.getGlobalBounds())){
                Marchewka5.czy_zebrane=true;
            }
            if(Marchewka3.czy_zebrane==false){
                wsk=&Marchewka3;
                wsk->animate(elapsed);
                window.draw(Marchewka3);
            }
            if(Marchewka4.czy_zebrane==false){
                wsk=&Marchewka4;
                wsk->animate(elapsed);
                window.draw(Marchewka4);
            }
            if(Marchewka5.czy_zebrane==false){
                wsk=&Marchewka5;
                wsk->animate(elapsed);
                window.draw(Marchewka5);
            }
            wsk=&Mufik;
            wsk->animate(elapsed);
            window.draw(Mufik);
            window.draw(text_zycia);
            //Wyjsice z planszy w wyniku utraty wszystkich żyć, lub zebrania wszystkich marchewek:
            if((Marchewka3.czy_zebrane==true&&Marchewka4.czy_zebrane==true&&Marchewka5.czy_zebrane)||Mufik.zycia<=0){
                Poziom2_flaga=false;
                Marchewka3.czy_zebrane=false;
                Marchewka4.czy_zebrane=false;
                Marchewka5.czy_zebrane=false;
                Mufik.setPosition(140,345);
                Mufik.zycia=3;
            }
        }
        //Dodanie następnego poziomu wymagałoby utworzenia kontenera zawierającego nowe ułożenie lementów głazów i korzeni.
        //Również byłaby potrzeba dodania marchwek i przypisania odpowiednich flag poziomu i flag ilości zebranych marchewek.

        //###################################Utworzenie poziomu opisującego grę:####################################################
        if(ogrze_flaga==true){
            window.draw(text_ogrze);
        }
        if(Mufik.zycia==3){
            text_zycia.setString("Szanse: 3");
        }else if(Mufik.zycia==2){
            text_zycia.setString("Szanse: 2");
        }else{
            text_zycia.setString("Szanse: 1");
        }
        window.display();
    }
    return 0;
}
