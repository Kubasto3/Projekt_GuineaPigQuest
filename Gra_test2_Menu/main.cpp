#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class AnimatedSprite : public sf::Sprite{
public:
    sf::Vector2f pos_obecna=(sf::Vector2f(0,0));

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

class Obstacle : public AnimatedSprite{
public:
    bool czy_glaz_poziomo=false;
    bool czy_glaz_pionowo=false;
    int prekosc_pozioma=20;
    int prekosc_pionowa=20;
    int odleglosc_ruchu=120;
    bool czy_zebrane=false;

    sf::Vector2f position_startowa=(sf::Vector2f(0,0));
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
    int zycia=3;
    GuineaPig  (sf::Vector2f pos){
        setPosition(pos);
    }
    void animate(sf::Time elapsed){
        sf::FloatRect rectangle_bounds = getGlobalBounds();
        pos_obecna=getPosition();

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
};

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Guinea Pig quest!");
    //Menu:
    sf::Texture texture_tlo;
    if (!texture_tlo.loadFromFile("Tlo.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite Tlo;
    Tlo.setTexture(texture_tlo);

    sf::Texture texture_button1;
    if (!texture_button1.loadFromFile("Przycisk_poziom1.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Sprite Button1;
    Button1.setTexture(texture_button1);
    Button1.setPosition(400,250);

    sf::Texture texture_button2;
    if (!texture_button2.loadFromFile("Przycisk_poziom2.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite Button2;
    Button2.setTexture(texture_button2);
    Button2.setPosition(400,400);

    sf::Texture texture_ogrze;
    if (!texture_ogrze.loadFromFile("Przycisk_ogrze.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite Button3;
    Button3.setTexture(texture_ogrze);
    Button3.setPosition(400,550);

    bool Poziom1_flaga=false;
    bool Poziom2_flaga=false;
    bool ogrze_flaga=false;

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

    sf::Texture texture_glaz;
    if (!texture_glaz.loadFromFile("glaz.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

////////////////////////////POZIOM 1//////////////////////////////////////
    std::vector<std::unique_ptr<Obstacle>> wektor;
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

/////////////////////////POZIOM 2///////////////////////////////////////
    std::vector<std::unique_ptr<Obstacle>> wektor2;

    for(int i=0;i<=39;i++){
        std::unique_ptr<Obstacle> sciana = std::make_unique<Obstacle>();
        switch (i)
        {
        case 0:
            sciana->setPosition(100, 300);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 1:
            sciana->setPosition(200, 300);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 2:
            sciana->setPosition(300, 400);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 3:
            sciana->setPosition(100, 400);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 4:
            sciana->setPosition(200, 400);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 5:
            sciana->setPosition(300, 200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 6:
            sciana->setPosition(110, 305);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 7:
            sciana->setPosition(300,100);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 8:
            sciana->setPosition(400,100);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 9:
            sciana->setPosition(500,100);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 10:
            sciana->setPosition(600,100);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 11:
            sciana->setPosition(700,100);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 12:
            sciana->setPosition(800,100);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 13:
            sciana->setPosition(300,100);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 14:
            sciana->setPosition(900,100);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 15:
            sciana->setPosition(800,200);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 16:
            sciana->setPosition(500,200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 17:
            sciana->setPosition(600,200);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 18:
            sciana->setPosition(400,200);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 19:
            sciana->setPosition(400,200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 20:
            sciana->setPosition(400,300);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 21:
            sciana->setPosition(400,400);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 22:
            sciana->setPosition(600,200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 23:
            sciana->setPosition(600,300);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 24:
            sciana->setPosition(600,400);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 25:
            sciana->setPosition(500,400);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 26:
            sciana->setPosition(600,500);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 27:
            sciana->setPosition(500,600);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 28:
            sciana->setPosition(400,600);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 29:
            sciana->setPosition(400,500);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        case 30:
            sciana->setPosition(400,500);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 31:
            sciana->setPosition(700,200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 32:
            sciana->setPosition(700,300);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 33:
            sciana->setPosition(700,400);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 34:
            sciana->setPosition(800,200);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 35:
            sciana->setPosition(800,300);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 36:
            sciana->setPosition(800,400);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 37:
            sciana->setPosition(700,500);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 38:
            sciana->setPosition(800,500);
            sciana->setTexture(texture_sciana);
            sciana->rotate(90);
            wektor2.emplace_back(move(sciana));
            break;
        case 39:
            sciana->setPosition(700,600);
            sciana->setTexture(texture_sciana);
            wektor2.emplace_back(move(sciana));
            break;
        }
    }

    for(int i=0;i<=4;i++){
        std::unique_ptr<Obstacle> glaz = std::make_unique<Obstacle>();
        switch (i){
        case 0:
            glaz->setPosition(255, 282);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_pionowo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pionowa=200;
            wektor2.emplace_back(move(glaz));
            break;
        case 1:
            glaz->setPosition(447, 458);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_poziomo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pozioma=300;
            glaz->odleglosc_ruchu=350;
            wektor2.emplace_back(move(glaz));
            break;
        case 2:
            glaz->setPosition(624, 75);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_pionowo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pionowa=80;
            wektor2.emplace_back(move(glaz));
            break;
        case 3:
            glaz->setPosition(430, 80);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_pionowo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pionowa=100;
            wektor2.emplace_back(move(glaz));
            break;
        case 4:
            glaz->setPosition(662, 344);
            glaz->setTexture(texture_glaz);
            glaz->czy_glaz_poziomo=true;
            glaz->position_startowa=glaz->getPosition();
            glaz->prekosc_pozioma=100;
            wektor2.emplace_back(move(glaz));
            break;
        }
    }
/////////////////////Marchewki + ikona okna + teksty/////////////////////////////
    sf::Texture texture_marchewka;
    if (!texture_marchewka.loadFromFile("marchewka.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    sf::Image icon;
    icon.loadFromFile("marchewka.png");
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

    Obstacle Marchewka1;
    Marchewka1.setPosition(423, 210);
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

    Obstacle Marchewka3;
    Marchewka3.setPosition(433, 549);
    Marchewka3.setTexture(texture_marchewka);
    Marchewka3.czy_glaz_pionowo=true;
    Marchewka3.position_startowa=Marchewka2.getPosition();
    Marchewka3.odleglosc_ruchu=15;

    Obstacle Marchewka4;
    Marchewka4.setPosition(840, 147);
    Marchewka4.setTexture(texture_marchewka);
    Marchewka4.czy_glaz_pionowo=true;
    Marchewka4.position_startowa=Marchewka2.getPosition();
    Marchewka4.odleglosc_ruchu=15;

    Obstacle Marchewka5;
    Marchewka5.setPosition(722, 561);
    Marchewka5.setTexture(texture_marchewka);
    Marchewka5.czy_glaz_pionowo=true;
    Marchewka5.position_startowa=Marchewka2.getPosition();
    Marchewka5.odleglosc_ruchu=15;

    sf::Font font;
    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        std::cerr << "Could not load texture" << std::endl;
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
    text_ogrze.setPosition(200,300);

    sf::Clock clock;
    int timer_w=0;

    ///////////////////////////GLOWNA PETLA/////////////////////////////////////
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    //std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

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
        window.clear(sf::Color::Black);
        window.draw(Tlo);
////////////////////////POZIOM 1:///////////////////////////////////////
        if(Poziom1_flaga==true){
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
                    Mufik.zycia=Mufik.zycia-1;
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

            if(Mufik.zycia==3){
              text_zycia.setString("Szanse: 3");
            }else if(Mufik.zycia==2){
               text_zycia.setString("Szanse: 2");
            }else{
              text_zycia.setString("Szanse: 1");
            }
            window.draw(text_zycia);
            if((Marchewka1.czy_zebrane==true&&Marchewka2.czy_zebrane==true)||Mufik.zycia<=0){
                Poziom1_flaga=false;
                Marchewka1.czy_zebrane=false;
                Marchewka2.czy_zebrane=false;
                Mufik.setPosition(140,345);
                Mufik.zycia=3;
                std::cerr<<"Gratulacje!!"<<std::endl;
            }
        }

///////////////////////////Poziom 2:////////////////////////////////////////
        if(Poziom2_flaga==true){
            Mufik.animate(elapsed);
            Mufik.add_animation_frame(timer_w);
            timer_w++;
            if(timer_w==100){
                timer_w=0;
            }
            for(auto &i:wektor2){
                if(Mufik.getGlobalBounds().intersects(i->getGlobalBounds())){
                    std::cerr<<"Bum"<<std::endl; 
                    Mufik.setPosition(140,345);
                    Mufik.zycia=Mufik.zycia-1;
                }
                i->animate(elapsed);
                if(i->czy_glaz_pionowo==true||i->czy_glaz_poziomo==true){
                    i->add_animation_frame(timer_w);
                }
                window.draw(*i);
            }
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
                Marchewka3.animate(elapsed);
                window.draw(Marchewka3);
            }
            if(Marchewka4.czy_zebrane==false){
                Marchewka4.animate(elapsed);
                window.draw(Marchewka4);
            }
            if(Marchewka5.czy_zebrane==false){
                Marchewka5.animate(elapsed);
                window.draw(Marchewka5);
            }
            window.draw(Mufik);
            if(Mufik.zycia==3){
              text_zycia.setString("Szanse: 3");
            }else if(Mufik.zycia==2){
               text_zycia.setString("Szanse: 2");
            }else{
              text_zycia.setString("Szanse: 1");
            }
            window.draw(text_zycia);

            if((Marchewka3.czy_zebrane==true&&Marchewka4.czy_zebrane==true&&Marchewka5.czy_zebrane)||Mufik.zycia<=0){
                Poziom2_flaga=false;
                Marchewka3.czy_zebrane=false;
                Marchewka4.czy_zebrane=false;
                Marchewka5.czy_zebrane=false;
                Mufik.setPosition(140,345);
                Mufik.zycia=3;
                std::cerr<<"Gratulacje!!"<<std::endl;
            }
        }

        if(ogrze_flaga==true){
            window.draw(text_ogrze);
        }
        if(Poziom1_flaga==false&&Poziom2_flaga==false&&ogrze_flaga==false){
            window.draw(Button1);
            window.draw(Button2);
            window.draw(Button3);
        }
        window.display();
    }
    return 0;
}
