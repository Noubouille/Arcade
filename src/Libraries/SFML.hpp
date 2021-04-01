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
    std::string getNameGame();
    void destroyWindow();
    std::string getLibName();
    void drawBackground(const std::string &Background);
	std::pair<int, int> sendBgSize() override;

    void clearWindow();
    void updateWindow();
    void drawMain(std::vector<Pixel>);
    void drawSprite(std::vector<Pixel> sprite);
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Texture _bgTexture;
    sf::Sprite _bgSprite;
    std::string _gameName;

private:
    sf::Time m_elapsedTime;
    std::pair<int, int> _bgSize;

    int pos_bar_y = 320;
    int bar_nb = 1;
};

extern "C" IGraphic *createLibrary();

#endif /* !SFML_HPP_ */

