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

    protected:
    private:
};

extern "C" IGames *createGame();


#endif /* !NIBBLER_HPP_ */
