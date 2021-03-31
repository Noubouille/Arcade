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
        bool checkMoveSnake();

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
        std::pair<float, float> _pos_fruit;
        float pos_x = 500.f;
        float pos_y = 500.f;

    protected:
    private:
    bool _game_over = false;
    bool _start_game = false;
    int _score;

};

extern "C" IGames *createGame();


#endif /* !NIBBLER_HPP_ */
