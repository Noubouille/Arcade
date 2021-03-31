/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <string>
#include <vector>
#include "../../includes/Pixel.hpp"
#include "../Libraries/IGraphic.hpp"


class IGames {
    public:
        virtual bool isGameOver() = 0;
		virtual void reset() = 0;
		virtual std::string getName() = 0;
		virtual std::string getBg() = 0;
        virtual int getScore() = 0;

        virtual std::vector<Pixel> getMain() = 0;
        virtual std::vector<Pixel> getSprite() = 0;
        virtual void getInput(MonEnum) = 0;
        virtual void updateGame() = 0;


    protected:
    private:
};

#endif /* !IGAMES_HPP_ */
