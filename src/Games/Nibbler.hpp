/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGames.hpp"

class Nibbler : public IGames {
    public:
        Nibbler();
        Nibbler(std::pair<int, int> bgSize);

        ~Nibbler();
        bool isGameOver() override;
		void reset() override;
		std::string getBg() override;
		std::string getName() override;
        int getScore();
        void initsnake();
        void getInput(MonEnum);
        std::vector<Pixel> getMain() override;
        Pixel getSprite() override;
        std::vector<Pixel> getSprites() override;

        bool foodCheck();
        bool foodCheck2();
        bool foodCheck3();
        void setFruit();
        void updateGame() override;
        bool checkMoveSnake_right(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_left(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_up(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_down(std::vector<Pixel>::iterator it);
        void bgSize(std::pair<int, int>) override;
        void getLibName(std::string libname) override;
        void eatFruit(std::vector<Pixel>::iterator it);
        std::string sendMusic() override;
        bool isGameStart() override;
		std::string sendPauseSprite() override;

        enum Orientation {
            UP,
            RIGHT,
            DOWN,
            LEFT,
        };

        std::vector<Pixel> _players;
        std::vector<Pixel> _fruit;

        Orientation _nextMove;
        std::pair<int, int> _pos_fruit;
        std::pair<int, int> _pos_fruit2;
        std::pair<int, int> _pos_fruit3;
        std::pair<int, int> _bg_size;
        int pos_x = 0;
        int pos_y = 0;
        unsigned int speed_snake = 1;

    private:
    std::string _libname;
    bool _game_over = false;
    bool _start_game = false;
    int _score;

};

extern "C" IGames *createGame(std::pair<int, int> jesuisjesus);


#endif /* !NIBBLER_HPP_ */
