/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_


#include "IGames.hpp"

class Pacman : public IGames {
    public:
        Pacman();
        Pacman(std::pair<int, int> bgSize);

        ~Pacman();
        bool isGameOver() override;
		void reset() override;
		std::string getBg() override;
		std::string getName() override;
        int getScore();
        void getInput(MonEnum);
        std::vector<Pixel> getMain() override;
        Pixel getSprite() override;
        std::vector<Pixel> getSprites() override;
        // bool foodCheck();
        void setFruit();
        void updateGame() override;
        bool checkMoveSnake_right(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_left(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_up(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_down(std::vector<Pixel>::iterator it);
        void bgSize(std::pair<int, int>) override;
        void getLibName(std::string libname) override;
        void eatFruit(std::vector<Pixel>::iterator it);
        void move_ghost();
        void move_ghost(std::string move, int nb);


        void moving_ghost1(std::string);
        void moving_ghost2(std::string);
        void moving_ghost3(std::string);
        void moving_ghost4(std::string);
		std::string sendMusic() override;
        bool isGameStart() override;
		std::string sendPauseSprite() override;

        enum Orientation {
            UP,
            RIGHT,
            DOWN,
            LEFT,
        };
    // std::vector<std::vector<Pixel>> _players;
        std::vector<Pixel> _players;
        std::vector<Pixel> _mobs;

        Orientation _nextMove;
        std::pair<int, int> _pos_fruit;
        std::pair<int, int> _bg_size;
        int pos_x = 0;
        int pos_y = 0;
        unsigned int speed_snake = 2;

    private:
    std::string _libname;
    bool _game_over = false;
    bool _start_game = false;
    int _score;

	std::pair <int, int> _ghost1_pos;
	std::pair <int, int> _ghost2_pos;
	std::pair <int, int> _ghost3_pos;
	std::pair <int, int> _ghost4_pos;

};

extern "C" IGames *createGame(std::pair<int, int> jesuisjesus);


// class Pacman {
//     public:
//         Pacman();
//         ~Pacman();

//     protected:
//     private:
// };

#endif /* !PACMAN_HPP_ */
