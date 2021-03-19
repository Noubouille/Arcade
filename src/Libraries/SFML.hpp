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

    void drawGame();
    MonEnum getNameGame();

    std::string getLibName();
    // SFML *createLibrary();

    sf::RenderWindow _window;
    sf::Font _font;
    sf::Texture _bgTexture;
    sf::Sprite _bgSprite;
    // std::string _gameName;

private:
    int pos_bar_y = 320;
    int bar_nb = 1;
};

// extern "C" SFML *createLibrary();
extern "C" IGraphic *createLibrary();

#endif /* !SFML_HPP_ */

