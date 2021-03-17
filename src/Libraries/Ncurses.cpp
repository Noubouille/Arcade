/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    
}

Ncurses::~Ncurses()
{
    
}

void Ncurses::startWindow()
{
    initscr();
    curs_set(FALSE);
}

void Ncurses::drawMenu()
{
    WINDOW *window = initscr();
    curs_set(FALSE);
    while(1)
    {
    wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);
    //initscr();
    // wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);

    // int start_y, start_x;
    // start_y = start_x = 10;

    // WINDOW * win = newwin(height, width, start_y, start_x);

    // box(win, 0, 0);
    // wprintw(win, name.c_str());
    // wrefresh(win);

    mvprintw(2, 2, "Nibbler");
    printw("\n");


    mvprintw(4, 2, "Pacman");
    printw("\n");

    refresh();
    }
}

void Ncurses::getEvent()
{
    int ch = getch();
}

void Ncurses::drawGame()
{

}

extern "C" IGraphic *createLibrary()
{
    std::cout << "CREATE LIBRARY NCURSES" << std::endl;
	return new Ncurses();
}