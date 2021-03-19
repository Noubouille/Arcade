/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IGraphic.hpp"
#include <string>
#include <iostream>

class SFML : public IGraphic
{
public:
    SFML();

    ~SFML();

    void startWindow();

    MonEnum getEvent();

    void drawMenu();

    void drawGame()
    {
        //draw game en sfml
    }
    std::string getLibName();
    // SFML *createLibrary();

    sf::RenderWindow _window;
    sf::Font _font;
    sf::Texture _bgTexture;
    sf::Sprite _bgSprite;
    // std::string _gameName;

    std::map<std::string, sf::Keyboard::Key> Key_list = {
		{"A", sf::Keyboard::A},
		{"Z", sf::Keyboard::Z},
		{"L", sf::Keyboard::L},
		{"Q", sf::Keyboard::Q},
		{"S", sf::Keyboard::S},
		{"D", sf::Keyboard::D},
		{"F", sf::Keyboard::F},
		{"M", sf::Keyboard::M},
		{"E", sf::Keyboard::E},
		{"Left", sf::Keyboard::Left},
		{"Right", sf::Keyboard::Right},
		{"Up", sf::Keyboard::Up},
		{"Down", sf::Keyboard::Down},
	};


};

// extern "C" SFML *createLibrary();
extern "C" IGraphic *createLibrary();

#endif /* !SFML_HPP_ */

