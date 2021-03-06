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

#include <SFML/Audio.hpp>

class SFML : public IGraphic
{
public:
    SFML();
    ~SFML();

    void startWindow();

    MonEnum getEvent();
    void drawMenu();
    void utilityGame();
    std::string getNameGame();
    void destroyWindow();
    std::string getLibName() override;
    std::string getUsername() override;
    void drawBackground(const std::string &Background);
	std::pair<int, int> sendBgSize() override;

    void clearWindow();
    void updateWindow();
    void drawMain(std::vector<Pixel>);
    void drawSprite(Pixel sprite);
    void drawSprites(std::vector<Pixel> sprites) override;

    void getMusic(const std::string &Background) override;

    void putText(const Text &text) override;
    void reset() override;
	bool getUsernameloop() override;
    void drawPause(const std::string &Background) override;


    sf::RenderWindow _window;
    sf::Font _font;
    sf::Music _musicMenu;
    sf::Music _musicGame;
    sf::Texture _bgTexture;
    sf::Sprite _bgSprite;
    std::string _gameName;
    std::string _input;
    std::pair<int, int> _bgSize = std::make_pair(600, 600);

private:
    sf::String _playerInput;
    sf::Text _playerText;

    sf::Time m_elapsedTime;

    int pos_bar_y = 320;
    int bar_nb = 1;
    bool music_on = false;
    bool music_game_on = false;
};

extern "C" IGraphic *createLibrary();

#endif /* !SFML_HPP_ */

