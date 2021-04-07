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
    this->_bg_size = std::make_pair(0, 0);
    this->_pos_fruit = std::make_pair(0, 0);

	// std::vector<Pixel> player;
	_nextMove = Orientation::UP;
	// _pos_snake = std::make_pair(16.f, 16.f);
	Pixel pixel;

	_players.emplace_back(pixel);
	pixel = {pos_x, pos_y, "./assets/Nibbler/body.png"};
	_players.emplace_back(pixel);
	// pixel = {pos_x + 16.f, pos_y, "./assets/Nibbler/body.png"};
	// _players.emplace_back(pixel);
	// pixel = {pos_x + 32.f, pos_y, "./assets/Nibbler/body.png"};
	// _players.emplace_back(pixel);
    // this->setFruit();
    _score = 0;
}

Nibbler::Nibbler(std::pair<int, int> bgSize)
{
    std::cout << "je suis dans l'autre constructeur ! bb" <<std::endl;
    this->_bg_size = bgSize;
    this->_pos_fruit = std::make_pair(0, 0);
    this->pos_x = _bg_size.first / 2;
    this->pos_y = _bg_size.second / 2;
	// std::vector<Pixel> player;
	_nextMove = Orientation::UP;
	// _pos_snake = std::make_pair(16.f, 16.f);
	Pixel pixel;

	_players.emplace_back(pixel);
	pixel = {pos_x, pos_y, "./assets/Nibbler/body.png"};
	_players.emplace_back(pixel);
	// pixel = {pos_x + 16.f, pos_y, "./assets/Nibbler/body.png"};
	// _players.emplace_back(pixel);
	// pixel = {pos_x + 32.f, pos_y, "./assets/Nibbler/body.png"};
	// _players.emplace_back(pixel);
    // this->setFruit();
    _score = 0;
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

std::vector<Pixel> Nibbler::getSprite()
{
    Pixel fruit;
	fruit = {this->_pos_fruit.first, this->_pos_fruit.second, "./assets/Nibbler/fruit.png"};
	_fruit.push_back(fruit);
    return _fruit;
}

void Nibbler::setFruit()
{
    srand(time(NULL));
    this->_pos_fruit = std::make_pair(0, 0);
	if (this->foodCheck() == false) {
		this->_pos_fruit.first = rand()%(this->_bg_size.first);
		this->_pos_fruit.second = rand()%(this->_bg_size.second);
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

void Nibbler::updateGame()
{
    if (foodCheck() == false) {
        this->_fruit.clear();
        setFruit();
        std::cout << "je mets un new fruit" << std::endl;
    }
    if (speed_snake > 10) {
        speed_snake = 10;
    }


}

void Nibbler::bgSize(std::pair<int, int> size)
{
    // this->_bg_size = size;
}

Nibbler::~Nibbler()
{
}

bool Nibbler::isGameOver()
{
    return false;
}

void Nibbler::initsnake()
{
    
}

void Nibbler::reset()
{

}

int Nibbler::getScore()
{
	return _score;
}

bool Nibbler::checkMoveSnake_up(std::vector<Pixel>::iterator it)
{
    if ((it->x > this->_pos_fruit.first - 25 && it->x < this->_pos_fruit.first + 25) &&
    (it->y > this->_pos_fruit.second - 25 && it->y < this->_pos_fruit.second + 25)) {
        this->_pos_fruit = std::make_pair(0, 0);
        _score++;
        //speed_snake++;
    }
    // if (it->y - 30 <= 0) {
    //     //std::cout << "je suis false it->y > bg!" << std::endl;
    //     //return false;
    // }

    if (it->y <= 0) {
        return false;
    }

    return true;
}

bool Nibbler::checkMoveSnake_down(std::vector<Pixel>::iterator it)
{
    if ((it->x > this->_pos_fruit.first - 25 && it->x < this->_pos_fruit.first + 25) &&
    (it->y > this->_pos_fruit.second - 25 && it->y < this->_pos_fruit.second + 25)) {
        this->_pos_fruit = std::make_pair(0, 0);
        _score++;
        //speed_snake++;

    }
    if (it->y >= _bg_size.second) {
        return false;
    }

    // if (it->y >= 34) {
    //     //std::cout << "je suis false  it y<0 !" << std::endl;
    //     return false;
    // }
    return true;
}

bool Nibbler::checkMoveSnake_right(std::vector<Pixel>::iterator it)
{
    if ((it->x > this->_pos_fruit.first - 25 && it->x < this->_pos_fruit.first + 25) &&
    (it->y > this->_pos_fruit.second - 25 && it->y < this->_pos_fruit.second + 25)) {
        this->_pos_fruit = std::make_pair(0, 0);
        _score++;
        //speed_snake++;

    }
    if (it->x >= _bg_size.first) {
        return false;
    }

    // if (it->x >= 99) {
    //     //std::cout << "je suis false  it->x > bg size!" << std::endl;
    //     return false;
    // }
    return true;
}

bool Nibbler::checkMoveSnake_left(std::vector<Pixel>::iterator it)
{
    if ((it->x > this->_pos_fruit.first - 25 && it->x < this->_pos_fruit.first + 25) &&
    (it->y > this->_pos_fruit.second - 25 && it->y < this->_pos_fruit.second + 25)) {
        this->_pos_fruit = std::make_pair(0, 0);
        _score++;
        //speed_snake++;

    }
    // if (it->x - 30 <= 0) {
    //     //std::cout << "je suis false  it->x < 0!" << std::endl;
    //     //return false;
    // }

    if (it->x <= 5) {
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
                    it->y -= speed_snake;
                } else {
                    // it->y -= 0;
                }
            }
        } else if (_nextMove == Orientation::DOWN) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_down(it)) {
                    it->y += speed_snake;
                } else {
                    // it->y += 0;
                }
            }
        } else if (_nextMove == Orientation::RIGHT) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_right(it)) {
                    it->x += speed_snake;
                } else {
                    // it->x += 0;
                }
            }
        } else if (_nextMove == Orientation::LEFT) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_left(it)) {
                    it->x -= speed_snake;

                } else {
                    // it->x -= 0;
                }
            }
        }
    }
    //std::cout << "speed_snake :" << speed_snake << std::endl;
    return this->_players;
}

std::string Nibbler::getName()
{
    return "NIBBLER";
}

std::string Nibbler::getBg()
{
    return "assets/Nibbler/background.png";
}

void Nibbler::getLibName(std::string libname)
{
    this->_libname = libname;
}


extern "C" IGames *createGame(std::pair<int, int> jesuisjesus)
{
    // std::cout << "le pair :" << jesuisjesus.first << std::endl;
	return new Nibbler(jesuisjesus);
}