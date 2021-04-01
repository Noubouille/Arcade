/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "IGraphic.hpp"
#include <ncurses.h>
#include <iostream>
#include <string>
class Ncurses : public IGraphic
{
    public:
        Ncurses();

        ~Ncurses();
        void startWindow();

        MonEnum getEvent();

        void drawMenu();
        void drawGame();
        std::string getNameGame();
        void destroyWindow();
        void drawBackground(const std::string &Background) override;
        void drawMain(std::vector<Pixel> snake) override;
        void drawSprite(std::vector<Pixel> sprite) override;
		void clearWindow() override;
		void updateWindow() override;


        WINDOW *window = initscr();
        //etc
};
extern "C" IGraphic *createLibrary();
#endif /* !NCURSES_HPP_ */
