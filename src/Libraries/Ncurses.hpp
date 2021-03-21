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

class Ncurses : public IGraphic
{
    public:
        Ncurses();

        ~Ncurses();
        void startWindow();

        MonEnum getEvent();

        void drawMenu();
        void drawGame();
        MonEnum getNameGame();
        void destroyWindow()

        //etc
};
extern "C" IGraphic *createLibrary();
#endif /* !NCURSES_HPP_ */
