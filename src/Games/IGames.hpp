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
#include <utility>

class IGames {
    public:
        virtual bool isGameOver() = 0;
		virtual void reset() = 0;
		virtual std::string getName() = 0;
		virtual std::string getBg() = 0;
		virtual std::string sendPauseSprite() = 0;
		virtual std::string sendMusic() = 0;
        virtual int getScore() = 0;
        virtual bool isGameStart() = 0;

        virtual std::vector<Pixel> getMain() = 0;
        virtual Pixel getSprite() = 0;
        virtual std::vector<Pixel> getSprites() = 0;
        virtual void getInput(MonEnum) = 0;
        virtual void getLibName(std::string libname) = 0;
        virtual void updateGame() = 0;
        virtual void bgSize(std::pair<int, int>) = 0;


    protected:
    private:
};

#endif /* !IGAMES_HPP_ */
