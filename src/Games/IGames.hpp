/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <string>

class IGames {
    public:
        virtual bool isGameOver() = 0;
		virtual void reset() = 0;
		// virtual std::string getName() = 0;
		virtual std::string getBg() = 0;

    protected:
    private:
};

#endif /* !IGAMES_HPP_ */
