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
        ~Nibbler();
        bool isGameOver() override;
		void reset() override;
		std::string getBg() override;
		std::string getName() override;
        int getScore();
        void initsnake();
        void getInput(MonEnum);
        std::vector<Pixel> getMain() override;
        std::vector<Pixel> getSprite() override;
        bool foodCheck();
        void setFruit();
        void updateGame() override;
        bool checkMoveSnake_right(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_left(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_up(std::vector<Pixel>::iterator it);
        bool checkMoveSnake_down(std::vector<Pixel>::iterator it);
        void bgSize(std::pair<int, int>) override;

        enum Orientation {
            UP,
            RIGHT,
            DOWN,
            LEFT,
        };
    // std::vector<std::vector<Pixel>> _players;
        std::vector<Pixel> _players;
        std::vector<Pixel> _fruit;

        // std::vector <std::pair <std::string, std::pair<float, float> > > snake;
        Orientation _nextMove;
        std::pair<int, int> _pos_fruit;
        std::pair<int, int> _bg_size;
        int pos_x = 500;
        int pos_y = 500;

    protected:
    private:
    bool _game_over = false;
    bool _start_game = false;
    int _score;

};

extern "C" IGames *createGame();


#endif /* !NIBBLER_HPP_ */
