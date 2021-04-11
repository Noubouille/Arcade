/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <iostream>

Nibbler::Nibbler()
{
}

Nibbler::Nibbler(std::pair<int, int> bgSize)
{
    this->_bg_size = bgSize;
    srand(time(NULL));
    this->pos_x = _bg_size.first / 2;
    this->pos_y = _bg_size.second / 2;
	_nextMove = Orientation::UP;
	Pixel pixel;

	_players.emplace_back(pixel);
    if (_bg_size.first > 100) {
	    pixel = {pos_x, pos_y, "./assets/Nibbler/head_up"};
    } else {
	    pixel = {pos_x, pos_y, "^"};
    }
	_players.emplace_back(pixel);
    _score = 0;

    _pos_fruit = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));
    _pos_fruit2 = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));
    _pos_fruit3 = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));

    Pixel fruit;
	_fruit.emplace_back(fruit);
	fruit = {_pos_fruit.first, _pos_fruit.second, "./assets/Nibbler/fruit"};
	_fruit.emplace_back(fruit);
	fruit = {_pos_fruit2.first, _pos_fruit2.second, "./assets/Nibbler/fruit"};
	_fruit.emplace_back(fruit);
	fruit = {_pos_fruit3.first, _pos_fruit3.second, "./assets/Nibbler/fruit"};
	_fruit.emplace_back(fruit);

}

void Nibbler::getInput(MonEnum Input)
{
    Orientation tmp_orientation;
	switch (Input) {
		case MonEnum::UP_ARROW:
			tmp_orientation = Orientation::UP;
            _start_game = true;
			break;
		case MonEnum::DOWN_ARROW:
			tmp_orientation = Orientation::DOWN;
            _start_game = true;
			break;
		case MonEnum::RIGHT_ARROW:
			tmp_orientation = Orientation::RIGHT;
            _start_game = true;
			break;
		case MonEnum::LEFT_ARROW:
			tmp_orientation = Orientation::LEFT;
            _start_game = true;
			break;
        case MonEnum::P_KEY:
            _start_game = false;

		default:
            return;
	}
    if (_libname == "SFML" || _libname == "SDL") {
        if (_nextMove == Orientation::UP && tmp_orientation == Orientation::DOWN) {
            _nextMove = _nextMove;
        } else if (_nextMove == Orientation::DOWN && tmp_orientation == Orientation::UP) {
            _nextMove = _nextMove;
        } else if (_nextMove == Orientation::RIGHT && tmp_orientation == Orientation::LEFT) {
            _nextMove = _nextMove;
        } else if (_nextMove == Orientation::LEFT && tmp_orientation == Orientation::RIGHT) {
            _nextMove = _nextMove;
        } else {
            _nextMove = tmp_orientation;
        }
    } else {
        _nextMove = tmp_orientation;
    }
}

Pixel Nibbler::getSprite()
{
    Pixel fruit;
	fruit = {this->_pos_fruit.first, this->_pos_fruit.second, "./assets/Nibbler/fruit"};

    return fruit;
}

std::vector<Pixel> Nibbler::getSprites()
{
    _fruit.clear();
    Pixel fruit;
	_fruit.emplace_back(fruit);
	fruit = {_pos_fruit.first, _pos_fruit.second, "./assets/Nibbler/fruit"};
	_fruit.emplace_back(fruit);
	fruit = {_pos_fruit2.first, _pos_fruit2.second, "./assets/Nibbler/fruit"};
	_fruit.emplace_back(fruit);
	fruit = {_pos_fruit3.first, _pos_fruit3.second, "./assets/Nibbler/fruit"};
	_fruit.emplace_back(fruit);
    return _fruit;
}


void Nibbler::setFruit()
{
    srand(time(NULL));
	if (this->foodCheck() == false) {
		this->_pos_fruit.first = rand()%(this->_bg_size.first);
	    this->_pos_fruit.second = rand()%(this->_bg_size.second);
	}
	if (this->foodCheck2() == false) {
		this->_pos_fruit2.first = rand()%(this->_bg_size.first);
		this->_pos_fruit2.second = rand()%(this->_bg_size.second);
	}
	if (this->foodCheck3() == false) {
		this->_pos_fruit3.first = rand()%(this->_bg_size.first);
		this->_pos_fruit3.second = rand()%(this->_bg_size.second);
	}
}

bool Nibbler::foodCheck()
{
    if (this->_pos_fruit.first != 0 && this->_pos_fruit.second != 0) {
        return true;
    } else {
        return false;
    }
}

bool Nibbler::foodCheck2()
{
    if (this->_pos_fruit2.first != 0 && this->_pos_fruit2.second != 0) {
        return true;
    } else {
        return false;
    }
}

bool Nibbler::foodCheck3()
{
    if (this->_pos_fruit3.first != 0 && this->_pos_fruit3.second != 0) {
        return true;
    } else {
        return false;
    }
}

void Nibbler::updateGame()
{
    if (foodCheck() == false || foodCheck2() == false || foodCheck3() == false) {
        setFruit();
    }
    if (speed_snake > 10) {
        speed_snake = 10;
    }
}

void Nibbler::bgSize(std::pair<int, int> size)
{
    this->_bg_size = size;
}

Nibbler::~Nibbler()
{
}

bool Nibbler::isGameOver()
{
    if (_game_over) {
        _game_over = false;
        return true;
    }
    return false;
}

void Nibbler::initsnake()
{
}

void Nibbler::reset()
{
    _score = 0;
    speed_snake = 1;
    for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
        it->x =_bg_size.first / 2;
        it->y =_bg_size.second / 2;
    }
    this->_pos_fruit = std::make_pair(0, 0);
    _nextMove = Orientation::UP;
}

int Nibbler::getScore()
{
	return _score;
}

void Nibbler::eatFruit(std::vector<Pixel>::iterator it)
{
    if (_libname == "SFML" || _libname == "SDL") {
        if ((it->x > this->_pos_fruit.first - 25 && it->x < this->_pos_fruit.first + 25) &&
        (it->y > this->_pos_fruit.second - 25 && it->y < this->_pos_fruit.second + 25)) {
            this->_pos_fruit = std::make_pair(0, 0);
            _score++;
            speed_snake++;
        }
        if ((it->x > this->_pos_fruit2.first - 25 && it->x < this->_pos_fruit2.first + 25) &&
        (it->y > this->_pos_fruit2.second - 25 && it->y < this->_pos_fruit2.second + 25)) {
            this->_pos_fruit2 = std::make_pair(0, 0);
            _score++;
            speed_snake++;
        }
        if ((it->x > this->_pos_fruit3.first - 25 && it->x < this->_pos_fruit3.first + 25) &&
        (it->y > this->_pos_fruit3.second - 25 && it->y < this->_pos_fruit3.second + 25)) {
            this->_pos_fruit3 = std::make_pair(0, 0);
            _score++;
            speed_snake++;
        }
    } else if (_libname == "NCURSES") {
        if ((it->x > this->_pos_fruit.first - 2 && it->x < this->_pos_fruit.first + 2) &&
        (it->y > this->_pos_fruit.second - 2 && it->y < this->_pos_fruit.second + 2)) {
        this->_pos_fruit = std::make_pair(0, 0);
            _score++;
            if (speed_snake != 2) speed_snake++;
        }
        if ((it->x > this->_pos_fruit2.first - 2 && it->x < this->_pos_fruit2.first + 2) &&
        (it->y > this->_pos_fruit2.second - 2 && it->y < this->_pos_fruit2.second + 2)) {
            this->_pos_fruit2 = std::make_pair(0, 0);
            _score++;
            if (speed_snake != 2) speed_snake++;
        }
        if ((it->x > this->_pos_fruit3.first - 2 && it->x < this->_pos_fruit3.first + 2) &&
        (it->y > this->_pos_fruit3.second - 2 && it->y < this->_pos_fruit3.second + 2)) {
            this->_pos_fruit3 = std::make_pair(0, 0);
            _score++;
            if (speed_snake != 2) speed_snake++;
        }
    }
}

bool Nibbler::checkMoveSnake_up(std::vector<Pixel>::iterator it)
{
    eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {
        if (it->y - 30 <= 0) {
            _game_over = true;
            return false;
        }
    }

    if (it->y <= 0) {

        return false;
    }

    return true;
}

bool Nibbler::checkMoveSnake_down(std::vector<Pixel>::iterator it)
{
    eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {

    }
    if (it->y >= _bg_size.second) {
        _game_over = true;
        return false;
    }

    return true;
}

bool Nibbler::checkMoveSnake_right(std::vector<Pixel>::iterator it)
{
        eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {
    }
    if (it->x >= _bg_size.first) {
        _game_over = true;

        return false;
    }

    return true;
}

bool Nibbler::checkMoveSnake_left(std::vector<Pixel>::iterator it)
{
        eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {
        if (it->x - 30 <= 0) {
            _game_over = true;

            return false;
        }
    }

    if (it->x <= 1) {
        _game_over = true;

        return false;
    }
    return true;
}

std::vector<Pixel> Nibbler::getMain()
{
    if (_start_game) {
        if (_nextMove == Orientation::UP) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_up(it)) {
                    if (_libname == "SFML" || _libname == "SDL") {
	                    it->pathSprite = "./assets/Nibbler/head_up";
                    } else if (_libname == "NCURSES") {
	                    it->pathSprite = "^";
                    }

                    it->y -= speed_snake;
                }
            }
        } else if (_nextMove == Orientation::DOWN) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_down(it)) {
                    if (_libname == "SFML" || _libname == "SDL") {
	                    it->pathSprite = "./assets/Nibbler/head_down";
                    } else if (_libname == "NCURSES") {
	                    it->pathSprite = "v";
                    }

                    it->y += speed_snake;
                }
            }
        } else if (_nextMove == Orientation::RIGHT) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_right(it)) {
                    if (_libname == "SFML" || _libname == "SDL") {
	                    it->pathSprite = "./assets/Nibbler/head_right";
                    } else if (_libname == "NCURSES") {
	                    it->pathSprite = ">";
                    }

                    it->x += speed_snake;
                }
            }
        } else if (_nextMove == Orientation::LEFT) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_left(it)) {
                    if (_libname == "SFML" || _libname == "SDL") {
	                    it->pathSprite = "./assets/Nibbler/head_left";
                    } else if (_libname == "NCURSES") {
	                    it->pathSprite = "<";
                    }

                    it->x -= speed_snake;

                }
            }
        }
    }
    //std::cout << "speed_snake :" << speed_snake << std::endl;
    return this->_players;
}

std::string Nibbler::sendMusic()
{
    return "assets/Nibbler/nibbler_song.ogg";
}

std::string Nibbler::sendPauseSprite()
{
    return "assets/pause_bg";
}


std::string Nibbler::getName()
{
    return "NIBBLER";
}

std::string Nibbler::getBg()
{
    return "assets/Nibbler/background";
}

void Nibbler::getLibName(std::string libname)
{
    this->_libname = libname;
}

bool Nibbler::isGameStart()
{
    return _start_game;
}


extern "C" IGames *createGame(std::pair<int, int> jesuisjesus)
{
	return new Nibbler(jesuisjesus);
}