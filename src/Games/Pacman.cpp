/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>

Pacman::Pacman()
{
}

Pacman::~Pacman() {}


Pacman::Pacman(std::pair<int, int> bgSize)
{
    this->_bg_size = bgSize;
    srand(time(NULL));
    this->_pos_fruit.first = rand()%(this->_bg_size.first);
    this->_pos_fruit.second = rand()%(this->_bg_size.second);
    this->pos_x = _bg_size.first / 2;
    this->pos_y = _bg_size.second / 2;
	_nextMove = Orientation::RIGHT;
	Pixel pixel;

	_players.emplace_back(pixel);
    if (_bg_size.first > 100) {
	    pixel = {pos_x, pos_y, "./assets/Pacman/pacman_right"};
    } else {
	    pixel = {pos_x, pos_y, ">"};
    }
	_players.emplace_back(pixel);
    _score = 0;

    _ghost1_pos = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));
    _ghost2_pos = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));
    _ghost3_pos = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));
    _ghost4_pos = std::make_pair(rand()%(this->_bg_size.first), rand()%(this->_bg_size.second));

    Pixel mob;
	_mobs.emplace_back(mob);
	mob = {_ghost1_pos.first, _ghost1_pos.second, "./assets/Pacman/blinky"};
	_mobs.emplace_back(mob);
	mob = {_ghost2_pos.first, _ghost2_pos.second, "./assets/Pacman/clyde"};
	_mobs.emplace_back(mob);
	mob = {_ghost3_pos.first, _ghost3_pos.second, "./assets/Pacman/inky"};
	_mobs.emplace_back(mob);
	mob = {_ghost4_pos.first, _ghost4_pos.second, "./assets/Pacman/pinky"};
	_mobs.emplace_back(mob);
}

void Pacman::moving_ghost1(std::string move)
{
	if (move.compare("Up") == 0) {
        if (this->_ghost1_pos.second <= 0) {
            this->_ghost1_pos.second = this->_ghost1_pos.second;
        } else {
            this->_ghost1_pos.second--;
        }

	} else if (move.compare("Down") == 0) {
        if (this->_ghost1_pos.second >= this->_bg_size.second) {
            this->_ghost1_pos.second = this->_ghost1_pos.second;

        } else {
            this->_ghost1_pos.second++;

        }
	} else if (move.compare("Left") == 0) {
        if (this->_ghost1_pos.first <= 0) {
            this->_ghost1_pos.first = 0;
        } else {
            this->_ghost1_pos.first--;
        }

	} else if (move.compare("Right") == 0) {
        if (this->_ghost1_pos.first >= this->_bg_size.first) {
            this->_ghost1_pos.first = this->_ghost1_pos.first;
        } else {
            this->_ghost1_pos.first++;
        }
	}
}

void Pacman::moving_ghost2(std::string move)
{
	if (move.compare("Up") == 0) {
        if (this->_ghost2_pos.second <= 0) {
            this->_ghost2_pos.second = this->_ghost2_pos.second;
        } else {
            this->_ghost2_pos.second--;
        }

	} else if (move.compare("Down") == 0) {
        if (this->_ghost2_pos.second >= this->_bg_size.second) {
            this->_ghost2_pos.second = this->_ghost2_pos.second;

        } else {
            this->_ghost2_pos.second++;

        }
	} else if (move.compare("Left") == 0) {
        if (this->_ghost2_pos.first <= 0) {
            this->_ghost2_pos.first = 0;
        } else {
            this->_ghost2_pos.first--;
        }

	} else if (move.compare("Right") == 0) {
        if (this->_ghost2_pos.first >= this->_bg_size.first) {
            this->_ghost2_pos.first = this->_ghost2_pos.first;
        } else {
            this->_ghost2_pos.first++;
        }
	}
}

void Pacman::moving_ghost3(std::string move)
{
	if (move.compare("Up") == 0) {
        if (this->_ghost3_pos.second <= 0) {
            this->_ghost3_pos.second = this->_ghost3_pos.second;
        } else {
            this->_ghost3_pos.second--;
        }

	} else if (move.compare("Down") == 0) {
        if (this->_ghost3_pos.second >= this->_bg_size.second) {
            this->_ghost3_pos.second = this->_ghost3_pos.second;

        } else {
            this->_ghost3_pos.second++;

        }
	} else if (move.compare("Left") == 0) {
        if (this->_ghost3_pos.first <= 0) {
            this->_ghost3_pos.first = 0;
        } else {
            this->_ghost3_pos.first--;
        }

	} else if (move.compare("Right") == 0) {
        if (this->_ghost3_pos.first >= this->_bg_size.first) {
            this->_ghost3_pos.first = this->_ghost3_pos.first;
        } else {
            this->_ghost3_pos.first++;
        }
	}
}

void Pacman::moving_ghost4(std::string move)
{
	if (move.compare("Up") == 0) {
        if (this->_ghost4_pos.second <= 0) {
            this->_ghost4_pos.second = this->_ghost4_pos.second;
        } else {
            this->_ghost4_pos.second--;
        }

	} else if (move.compare("Down") == 0) {
        if (this->_ghost4_pos.second >= this->_bg_size.second) {
            this->_ghost4_pos.second = this->_ghost4_pos.second;

        } else {
            this->_ghost4_pos.second++;

        }
	} else if (move.compare("Left") == 0) {
        if (this->_ghost4_pos.first <= 0) {
            this->_ghost4_pos.first = 0;
        } else {
            this->_ghost4_pos.first--;
        }

	} else if (move.compare("Right") == 0) {
        if (this->_ghost4_pos.first >= this->_bg_size.first) {
            this->_ghost4_pos.first = this->_ghost4_pos.first;
        } else {
            this->_ghost4_pos.first++;
        }
	}
}

void Pacman::move_ghost(std::string move, int nb)
{
	if (nb == 0)
		moving_ghost1(move);
	else if (nb == 1)
		moving_ghost2(move);
	else if (nb == 2)
		moving_ghost3(move);
	else if (nb == 3)
		moving_ghost4(move);
	return ;
}

void Pacman::move_ghost()
{
    int i;
	int j;
	int k;
	int l;

	srand(time(NULL));
	i = rand()%(4 - 0 + 1) + 1;
	j = rand()%(4 - 0 + 1) + 1;
	k = rand()%(4 - 0 + 1) + 1;
	l = rand()%(4 - 0 + 1) + 1;

    if ( i == 1)
		this->move_ghost("Up", 0);
	else if (i == 2)
		this->move_ghost("Down", 0);
	else if (i == 3)
		this->move_ghost("Left", 0);
	else if (i == 4)
		this->move_ghost("Right", 0);
	if ( j == 1)
		this->move_ghost("Up", 1);
	else if (j == 2)
		this->move_ghost("Down", 1);
	else if (j == 3)
		this->move_ghost("Left", 1);
	else if (j == 4)
		this->move_ghost("Right", 1);
	if ( k == 1)
		this->move_ghost("Up", 2);
	else if (k == 2)
		this->move_ghost("Down", 2);
	else if (k == 3)
		this->move_ghost("Left", 2);
	else if (k == 4)
		this->move_ghost("Right", 2);
	if (l == 1)
		this->move_ghost("Up", 3);
	else if (l == 2)
		this->move_ghost("Down", 3);
	else if (l == 3)
		this->move_ghost("Left", 3);
	else if (l == 4)
		this->move_ghost("Right", 3);
}

void Pacman::getInput(MonEnum Input)
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

Pixel Pacman::getSprite()
{
    Pixel fruit;
	fruit = {this->_pos_fruit.first, this->_pos_fruit.second, "./assets/Pacman/blinky"};

    return fruit;
}

std::vector<Pixel> Pacman::getSprites()
{
    _mobs.clear();

    Pixel mob;
	_mobs.emplace_back(mob);
	mob = {_ghost1_pos.first, _ghost1_pos.second, "./assets/Pacman/blinky"};
	_mobs.emplace_back(mob);
	mob = {_ghost2_pos.first, _ghost2_pos.second, "./assets/Pacman/clyde"};
	_mobs.emplace_back(mob);
	mob = {_ghost3_pos.first, _ghost3_pos.second, "./assets/Pacman/inky"};
	_mobs.emplace_back(mob);
	mob = {_ghost4_pos.first, _ghost4_pos.second, "./assets/Pacman/pinky"};
	_mobs.emplace_back(mob);
    return _mobs;
}

void Pacman::setFruit()
{
}

void Pacman::updateGame()
{
    if (_start_game) {
        move_ghost();
    }

}

void Pacman::bgSize(std::pair<int, int> size)
{
    this->_bg_size = size;
}

bool Pacman::isGameOver()
{
    if (_game_over) {
        _game_over = false;
        return true;
    }
    return false;
}

bool Pacman::isGameStart()
{
    return _start_game;
}

void Pacman::reset()
{
    _score = 0;
    speed_snake = 1;
    for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
        it->x =_bg_size.first / 2;
        it->y =_bg_size.second / 2;
    }
    this->_pos_fruit = std::make_pair(0, 0);
    this->_game_over = false;
    _nextMove = Orientation::RIGHT;
}

int Pacman::getScore()
{
	return _score;
}

void Pacman::eatFruit(std::vector<Pixel>::iterator it)
{
    if (_libname == "SFML" || _libname == "SDL") {
        if ((it->x > this->_ghost1_pos.first - 25 && it->x < this->_ghost1_pos.first + 25) &&
        (it->y > this->_ghost1_pos.second - 25 && it->y < this->_ghost1_pos.second + 25)) {
            _game_over = true;
        }
        if ((it->x > this->_ghost2_pos.first - 25 && it->x < this->_ghost2_pos.first + 25) &&
        (it->y > this->_ghost2_pos.second - 25 && it->y < this->_ghost2_pos.second + 25)) {
            _game_over = true;
        }
        if ((it->x > this->_ghost3_pos.first - 25 && it->x < this->_ghost3_pos.first + 25) &&
        (it->y > this->_ghost3_pos.second - 25 && it->y < this->_ghost3_pos.second + 25)) {
            _game_over = true;
        }
        if ((it->x > this->_ghost4_pos.first - 25 && it->x < this->_ghost4_pos.first + 25) &&
        (it->y > this->_ghost4_pos.second - 25 && it->y < this->_ghost4_pos.second + 25)) {
            _game_over = true;
        }
    } else if (_libname == "NCURSES") {
        if ((it->x > this->_pos_fruit.first - 2 && it->x < this->_pos_fruit.first + 2) &&
        (it->y > this->_pos_fruit.second - 2 && it->y < this->_pos_fruit.second + 2)) {
            _game_over = true;
        }
        if ((it->x > this->_ghost2_pos.first - 2 && it->x < this->_ghost2_pos.first + 2) &&
        (it->y > this->_ghost2_pos.second - 2 && it->y < this->_ghost2_pos.second + 2)) {
            _game_over = true;
        }
        if ((it->x > this->_ghost3_pos.first - 2 && it->x < this->_ghost3_pos.first + 2) &&
        (it->y > this->_ghost3_pos.second - 2 && it->y < this->_ghost3_pos.second + 2)) {
            _game_over = true;
        }
        if ((it->x > this->_ghost4_pos.first - 2 && it->x < this->_ghost4_pos.first + 2) &&
        (it->y > this->_ghost4_pos.second - 2 && it->y < this->_ghost4_pos.second + 2)) {
            _game_over = true;
        }
    }
}

bool Pacman::checkMoveSnake_up(std::vector<Pixel>::iterator it)
{
    eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {
        if (it->y - 30 <= 0) {
            return false;
        }
    }

    if (it->y <= 0) {
        return false;
    }

    return true;
}

bool Pacman::checkMoveSnake_down(std::vector<Pixel>::iterator it)
{
    eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {

    }
    if (it->y >= _bg_size.second) {
        return false;
    }

    return true;
}

bool Pacman::checkMoveSnake_right(std::vector<Pixel>::iterator it)
{
        eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {
    }
    if (it->x >= _bg_size.first) {
        return false;
    }

    return true;
}

bool Pacman::checkMoveSnake_left(std::vector<Pixel>::iterator it)
{
        eatFruit(it);
    if (_libname == "SFML" || _libname == "SDL") {
        if (it->x - 30 <= 0) {
            return false;
        }
    }

    if (it->x <= 1) {
        return false;
    }
    return true;
}

std::vector<Pixel> Pacman::getMain()
{
    if (_start_game) {
        if (_nextMove == Orientation::UP) {
            for (auto it = std::next(_players.begin()); it != _players.end(); it++) {
                if (checkMoveSnake_up(it)) {
                    if (_libname == "SFML" || _libname == "SDL") {
	                    it->pathSprite = "./assets/Pacman/pacman_up";
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
	                    it->pathSprite = "./assets/Pacman/pacman_down";
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
	                    it->pathSprite = "./assets/Pacman/pacman_right";
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
	                    it->pathSprite = "./assets/Pacman/pacman_left";
                    } else if (_libname == "NCURSES") {
	                    it->pathSprite = "<";
                    }

                    it->x -= speed_snake;

                }
            }
        }
    }
    return this->_players;
}

std::string Pacman::getName()
{
    return "PACMAN";
}

std::string Pacman::sendMusic() {
    return "assets/Pacman/pacman_song.ogg";
}

std::string Pacman::getBg()
{
    return "assets/Pacman/background";
}

void Pacman::getLibName(std::string libname)
{
    this->_libname = libname;
}

extern "C" IGames *createGame(std::pair<int, int> jesuisjesus)
{
	return new Pacman(jesuisjesus);
}