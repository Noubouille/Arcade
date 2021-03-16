/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Core
*/

#include "../includes/Core.hpp"
// #include <filesystem>
#include <experimental/filesystem>
#include <regex>

namespace fs = std::experimental::filesystem;

Core::Core(const std::string &lib_name)
{
    const auto libpath = realpath(lib_name.c_str(), nullptr);

    if (libpath == nullptr) {
        perror(lib_name.c_str());
        exit(84);
    }
    this->getGraphicLib(libpath);
}

void Core::getGraphicLib(const std::string &lib_name)
{
    // recuperer les libs dans ./lib
	std::regex r("/arcade_(.+)\\.so$");
	std::smatch m;

    for (const auto & entry : fs::directory_iterator(realpath("./lib", nullptr))) {
        std::string path = entry.path().c_str();

        if (std::find(this->_listLib.begin(), this->_listLib.end(), path) == this->_listLib.end() && std::regex_search(path, m, r)) {
            this->_listLib.push_back(entry.path().c_str());
        }
    }
    for (std::string str: this->_listLib)
        std::cout << str << std::endl;
}

Core::~Core()
{
    std::cout << "je suis le destructor" << std::endl;
}

void Core::gameMenu()
{
    sf::RenderWindow window(sf::VideoMode(1080, 1080), "Arcade");
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - window.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - window.getSize().y * 0.5));

    sf::Texture bg;
    sf::Texture active;
    sf::Font font;

    if (!bg.loadFromFile("assets/bg.png"))
        return;

    if (!active.loadFromFile("assets/btn_green.png"))
        return;

    if (!font.loadFromFile("assets/Arcade.ttf"))
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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
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

        window.clear(sf::Color(0, 0, 0));
        window.draw(bg_sprite);
        window.draw(Pacman_font);
        window.draw(Nibbler_font);
        window.draw(bar_font);

        window.draw(Ncurses_font);
        window.draw(Sfml_font);
        window.draw(Sdl_font);


        bar_font.setPosition(450, pos_bar_y);

        window.display();
    }
}