/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML(): m_elapsedTime(sf::Time::Zero)
{
    this->_gameName = "NIBBLER";
    this->_bgSize = std::make_pair(600, 600);
    if (!_font.loadFromFile("./assets/Arcade.ttf"))
        return;

    if (!_musicMenu.openFromFile("./assets/menu_music.ogg"))
        return;
    _musicMenu.play();
    _musicMenu.setVolume(30);
    _input = (char *)malloc(32);
    sf::Text oui("", _font, 25);
    _playerText = oui;
}

SFML::~SFML()
{
}

void SFML::startWindow()
{
    this->_window.create(sf::VideoMode(1080, 1080), "Arcade sfml");
    this->_window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - _window.getSize().x * 0.5, sf::VideoMode::getDesktopMode().height * 0.5 - _window.getSize().y * 0.5));
    if (!this->_bgTexture.loadFromFile("./assets/bg.png"))
        return;
    this->_bgSprite.setTexture(this->_bgTexture);
}

void SFML::drawMenu()
{
    sf::Texture bg;
    sf::Texture active;
    sf::Sprite bg_sprite(bg);
    sf::Text bar_font("-------", _font, 35);
    sf::Text Nibbler_font("Nibbler", _font, 35);
    sf::Text Pacman_font("Pacman", _font, 35);
    sf::Text Currentlib_font("Current lib : SFML", _font, 25);
    Currentlib_font.setPosition(400, 20);
    bar_font.setPosition(450, pos_bar_y);
    Nibbler_font.setPosition(450, 300);
    Pacman_font.setPosition(450, 360);

    sf::Text user_text("Username :", _font, 25);
    sf::Text next_font("[F1] next graphical library", _font, 25);
    sf::Text prev_font("[F2] previous graphical library", _font, 25);
    next_font.setPosition(50, 580);
    prev_font.setPosition(50, 640);

    bg_sprite.setTexture(bg);
    _playerText.setPosition(510, 90);
    user_text.setPosition(350, 90);

    this->_window.clear(sf::Color(0, 0, 0));
    this->_window.draw(this->_bgSprite);
    this->_window.draw(Pacman_font);
    this->_window.draw(Nibbler_font);
    this->_window.draw(Currentlib_font);
    this->_window.draw(bar_font);
    this->_window.draw(next_font);
    this->_window.draw(prev_font);
    this->_window.draw(_playerText);
    this->_window.draw(user_text);

    bar_font.setPosition(450, pos_bar_y);

    this->_window.display();
}

bool SFML::getUsernameloop()
{
    return false;
}


void SFML::utilityGame()
{
    _musicMenu.stop();
}

void SFML::drawPause(const std::string &Background)
{
    if (Background.empty()) {
        return;
    }

    std::string tmp = Background + ".png";

	sf::Texture texture;
	texture.loadFromFile(tmp);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(340, 450);
	_window.draw(sprite);
}

MonEnum SFML::getEvent()
{
	sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            destroyWindow();
            exit(0);
            return MonEnum::CLOSE;
        }
        if (event.type == sf::Event::TextEntered) {
            if(event.text.unicode < 128) {
                _playerInput += event.text.unicode;
                _playerText.setString(_playerInput);
                _input = _playerInput;
            }
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
    this->_musicGame.stop();
    this->_musicMenu.stop();
    this->_window.close();
}

void SFML::clearWindow()
{
    this->_window.clear(sf::Color::Black);
}

void SFML::updateWindow()
{
    this->_window.display();
}

std::string SFML::getLibName()
{
    return "SFML";
}

std::string SFML::getUsername()
{

    return _input;
}

void SFML::drawBackground(const std::string &Background)
{

    if (Background.empty()) {
        return;
    }

    std::string tmp = Background + ".png";

	sf::Texture texture;
	texture.loadFromFile(tmp);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0 ,0));
	_window.draw(sprite);

}

void SFML::drawMain(std::vector<Pixel> snake)
{

        for (auto it = std::next(snake.begin()); it != snake.end(); it++) {
            std::string tmp = it->pathSprite + ".png";

            sf::Texture texture;
            if (!texture.loadFromFile(tmp)) {
                return ;
            }

            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setPosition(sf::Vector2f(it->x, it->y));
            _window.draw(sprite);
        }
    if (m_elapsedTime.asSeconds() > 0.1) {
        m_elapsedTime = sf::Time::Zero;
    }
}

void SFML::drawSprite(Pixel sprite) {
    auto it = sprite;
    std::string tmp = it.pathSprite + ".png";

    sf::Texture texture;
    texture.loadFromFile(tmp);
    sf::Sprite Sprite;
    Sprite.setTexture(texture);
    Sprite.setPosition(sf::Vector2f(it.x, it.y));
    _window.draw(Sprite);
}

void SFML::drawSprites(std::vector<Pixel> sprites)
{
    for (auto it = std::next(sprites.begin()); it != sprites.end(); it++) {
        if (it->pathSprite.empty()) return;
        std::string tmp = it->pathSprite + ".png";

        sf::Texture texture;
        if (!texture.loadFromFile(tmp)) {
            return ;
        }

        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(it->x, it->y));
        _window.draw(sprite);
    }
}

void SFML::getMusic(const std::string &music)
{
    if (music_game_on == false) {
        if (!_musicGame.openFromFile(music)) {
            return;
        }

        _musicGame.play();
        _musicGame.setVolume(20);
        music_game_on = true;
    }
}

void SFML::reset() {
    _musicGame.stop();
    music_game_on = false;
    _musicMenu.play();
}


std::pair<int, int> SFML::sendBgSize()
{
    return _bgSize;
}

void SFML::putText(const Text &some_text)
{
    sf::Text text(some_text.text, _font);
	text.setPosition(some_text.x, some_text.y);
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
	_window.draw(text);
}

extern "C" IGraphic *createLibrary()
{
	return new SFML();
}