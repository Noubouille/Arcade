/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML()
{
    std::cout << "constructeur SFML inside" << std::endl;
    
}

SFML::~SFML()
{
}

void SFML::startWindow()
{
    // std::cout << "start window lib" << std::endl;
    this->_window.create(sf::VideoMode(1080, 1080), "Arcade");
    this->_window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - _window.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - _window.getSize().y * 0.5));
    if (!this->_bgTexture.loadFromFile("./assets/bg.png"))
        return;
    this->_bgSprite.setTexture(this->_bgTexture);
}

void SFML::drawMenu()
{
    // sf::RenderWindow window(sf::VideoMode(1080, 1080), "Arcade");
    // window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - window.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - window.getSize().y * 0.5));
    std::cout << "la window" << std::endl;
    sf::Texture bg;
    sf::Texture active;
    sf::Font font;

    // if (!bg.loadFromFile("./assets/bg.png"))
    //     return;

    if (!active.loadFromFile("./assets/btn_green.png"))
        return;

    if (!font.loadFromFile("./assets/Arcade.ttf"))
        return;
    int pos_bar_y = 320;
    int bar_nb = 1;

    sf::Sprite bg_sprite(bg);
    sf::Sprite bouton_sprite(active);
    sf::Text bar_font("-------", font, 35);
    sf::Text Nibbler_font("Nibbler", font, 35);
    sf::Text Pacman_font("Pacman", font, 35);
    bar_font.setPosition(450, pos_bar_y);
    Nibbler_font.setPosition(450, 300);
    Pacman_font.setPosition(450, 360);

    sf::Text Ncurses_font("ncurses", font, 35);
    sf::Text Sfml_font("SFML", font, 35);
    sf::Text Sdl_font("SDL", font, 35);
    Ncurses_font.setPosition(450, 560);
    Sfml_font.setPosition(450, 620);
    Sdl_font.setPosition(450, 680);

    bg_sprite.setTexture(bg);
    bouton_sprite.setTexture(active);

    // while (window.isOpen())
    // {
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
          std::cout << "le pollevent" << std::endl;

            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                this->_window.close();
            if(event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    if (bar_nb > 1) {
                        pos_bar_y -= 60;
                        bar_nb--;
                    }
                    printf("key up\n");
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (bar_nb < 2) {
                        pos_bar_y += 60;
                        bar_nb++;
                    }
                    printf("key down\n");
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    printf("key enter\n");
                }

                sf::Vector2i position = sf::Mouse::getPosition();

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    //if (position == ())
                }
            }

        }

        this->_window.clear(sf::Color(0, 0, 0));
        this->_window.draw(this->_bgSprite);
        this->_window.draw(Pacman_font);
        this->_window.draw(Nibbler_font);
        this->_window.draw(bar_font);

        this->_window.draw(Ncurses_font);
        this->_window.draw(Sfml_font);
        this->_window.draw(Sdl_font);

        bar_font.setPosition(450, pos_bar_y);

        this->_window.display();
    // }
}

MonEnum SFML::getEvent()
{
	sf::Event event;
        // std::cout << "je passe event" << std::endl;
    // if (!this->_window.pollEvent(event))
    //         return "NO_INPUT poll";

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            std::cout << "sf::Event::CLOSE" << std::endl;
            _window.close();
            exit(0);
            return MonEnum::No_Input;
            // return "Closed";
        }
        else if (event.type == sf::Event::KeyPressed) {
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            std::cout << "sf::Event::KeyPressed" << std::endl;
            return MonEnum::Input;

            // switch (event.key.code) {
            //     case sf::Keyboard::Left :
            //         return MonEnum::Input;
            //     case sf::Keyboard::Right :
            //         return MonEnum::Input;
            //     default :
            //         return MonEnum::No_Input;
            //     }
        }
    }


    // std::map<std::string, sf::Keyboard::Key>::iterator it = Key_list.begin();
    // if (event.type == sf::Event::KeyPressed) {
    //     std::cout << "je suis présséééééé mais bof" << std::endl;


    //     while (it != Key_list.end()) {
    //         if (it->first == sf::Keyboard::isKeyPressed(it->first.c_str())) {

    //         }
    //         std::cout << it->first << " :: " << std::endl;
    //         it++;

    // }
    // }
    // for (auto &i : Key_list){
    //     std::cout << "le key list" << i.second << std::endl;
    //     if (sf::Keyboard::isKeyPressed(i.second)) {
    //         return (i.first.c_str());

    //    }
    // }
    return MonEnum::No_Input;
}

std::string SFML::getLibName()
{
    return "SFML";
}

extern "C" IGraphic *createLibrary()
{
    std::cout << "CREATE LIBRARY" << std::endl;
	return new SFML();
}