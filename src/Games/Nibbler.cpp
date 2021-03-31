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
    this->setFruit();
}

void Nibbler::getInput(MonEnum Input)
{
    Orientation tmp_orientation;
	switch (Input) {
		case MonEnum::UP_ARROW:
			tmp_orientation = Orientation::UP;
			break;
		case MonEnum::DOWN_ARROW:
			tmp_orientation = Orientation::DOWN;
			break;
		case MonEnum::RIGHT_ARROW:
			tmp_orientation = Orientation::RIGHT;
			break;
		case MonEnum::LEFT_ARROW:
			tmp_orientation = Orientation::LEFT;
			break;
		default:
            return;
	}
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
		this->_pos_fruit.first = rand()%(20) + 300;
		this->_pos_fruit.second = rand()%(20) + 300;
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
        setFruit();
        std::cout << "je mets un new fruit" << std::endl;
    }

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

bool Nibbler::checkMoveSnake()
{

}



std::vector<Pixel> Nibbler::getMain()
{
	if (_nextMove == Orientation::UP) {
        for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
            it->y -= 3.f;
        }
	} else if (_nextMove == Orientation::DOWN) {
        for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
            it->y += 3.f;
        }
	} else if (_nextMove == Orientation::RIGHT) {
        for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
            it->x += 3.f;
        }
    } else if (_nextMove == Orientation::LEFT) {
        for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
            it->x -= 3.f;
        }
    }
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

extern "C" IGames *createGame()
{
	return new Nibbler();
}