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
    this->_gameName = "NIBBLER";
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
    // std::cout << "la window" << std::endl;
    sf::Texture bg;
    sf::Texture active;
    sf::Font font;

    // if (!bg.loadFromFile("./assets/bg.png"))
    //     return;

    if (!active.loadFromFile("./assets/btn_green.png"))
        return;

    if (!font.loadFromFile("./assets/Arcade.ttf"))
        return;
    // int pos_bar_y = 320;
    // int bar_nb = 1;

    sf::Sprite bg_sprite(bg);
    sf::Sprite bouton_sprite(active);
    sf::Text bar_font("-------", font, 35);
    sf::Text Nibbler_font("Nibbler", font, 35);
    sf::Text Pacman_font("Pacman", font, 35);
    bar_font.setPosition(450, pos_bar_y);
    Nibbler_font.setPosition(450, 300);
    Pacman_font.setPosition(450, 360);

    sf::Text next_font("[F1] next graphical library", font, 35);
    sf::Text prev_font("[F2] previous graphical library", font, 35);
    next_font.setPosition(50, 580);
    prev_font.setPosition(50, 640);

    bg_sprite.setTexture(bg);
    bouton_sprite.setTexture(active);

    this->_window.clear(sf::Color(0, 0, 0));
    this->_window.draw(this->_bgSprite);
    this->_window.draw(Pacman_font);
    this->_window.draw(Nibbler_font);
    this->_window.draw(bar_font);

    this->_window.draw(next_font);
    this->_window.draw(prev_font);

    bar_font.setPosition(450, pos_bar_y);

    this->_window.display();
}

void SFML::drawGame()
{

}

MonEnum SFML::getEvent()
{
	sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            std::cout << "sf::Event::CLOSE" << std::endl;
            _window.close();
            exit(0);
            return MonEnum::CLOSE;
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Left :
                return MonEnum::LEFT_ARROW;
            case sf::Keyboard::Right :
                return MonEnum::RIGHT_ARROW;
            case sf::Keyboard::Up :
                if (this->bar_nb > 1) {
                    this->pos_bar_y -= 60;
                    this->bar_nb--;
                    this->_gameName = "NIBBLER";

                }
                return MonEnum::UP_ARROW;
            case sf::Keyboard::Down :
                if (this->bar_nb < 2) {
                    this->pos_bar_y += 60;
                    this->bar_nb++;
                    this->_gameName = "PACMAN";
                }
                return MonEnum::DOWN_ARROW;
            case sf::Keyboard::Space :
                return MonEnum::SPACE;
            case sf::Keyboard::BackSpace :
                return MonEnum::BACKSPACE;
            case sf::Keyboard::Return :
                return MonEnum::ENTER;
            case sf::Keyboard::Escape :
                return MonEnum::ESCAPE;
            case sf::Keyboard::A :
                return MonEnum::A_KEY;
            case sf::Keyboard::B :
                return MonEnum::B_KEY;
            case sf::Keyboard::C :
                return MonEnum::C_KEY;
            case sf::Keyboard::D :
                return MonEnum::D_KEY;
            case sf::Keyboard::E :
                return MonEnum::E_KEY;
            case sf::Keyboard::F :
                return MonEnum::F_KEY;
            case sf::Keyboard::G :
                return MonEnum::G_KEY;
            case sf::Keyboard::H :
                return MonEnum::H_KEY;
            case sf::Keyboard::I :
                return MonEnum::I_KEY;
            case sf::Keyboard::J :
                return MonEnum::J_KEY;
            case sf::Keyboard::K :
                return MonEnum::K_KEY;
            case sf::Keyboard::L :
                return MonEnum::L_KEY;
            case sf::Keyboard::M :
                return MonEnum::M_KEY;
            case sf::Keyboard::N :
                return MonEnum::N_KEY;
            case sf::Keyboard::O :
                return MonEnum::O_KEY;
            case sf::Keyboard::P :
                return MonEnum::P_KEY;
            case sf::Keyboard::Q :
                return MonEnum::Q_KEY;
            case sf::Keyboard::R :
                return MonEnum::R_KEY;
            case sf::Keyboard::S :
                return MonEnum::S_KEY;
            case sf::Keyboard::T :
                return MonEnum::T_KEY;
            case sf::Keyboard::U :
                return MonEnum::U_KEY;
            case sf::Keyboard::V :
                return MonEnum::V_KEY;
            case sf::Keyboard::W :
                return MonEnum::W_KEY;
            case sf::Keyboard::X :
                return MonEnum::X_KEY;
            case sf::Keyboard::Y :
                return MonEnum::Y_KEY;
            case sf::Keyboard::Z :
                return MonEnum::Z_KEY;
            case sf::Keyboard::F1 :
                return MonEnum::F1;
            case sf::Keyboard::F2 :
                return MonEnum::F2;
            case sf::Keyboard::F3 :
                return MonEnum::F3;
            case sf::Keyboard::F4 :
                return MonEnum::F4;
            case sf::Keyboard::F5 :
                return MonEnum::F5;
            case sf::Keyboard::F6 :
                return MonEnum::F6;
            case sf::Keyboard::F7 :
                return MonEnum::F7;
            case sf::Keyboard::F8 :
                return MonEnum::F8;
            case sf::Keyboard::F9 :
                return MonEnum::F9;
            case sf::Keyboard::F10 :
                return MonEnum::F10;
            case sf::Keyboard::F11 :
                return MonEnum::F11;
            case sf::Keyboard::F12 :
                return MonEnum::F12;
            default :
                return MonEnum::NO_INPUT;
            }
        }
    }
    return MonEnum::NO_INPUT;
}

std::string SFML::getNameGame()
{
    return _gameName;
}

void SFML::destroyWindow()
{
    this->_window.close();
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