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
    keypad(stdscr, TRUE);
    //while(1)
    //{
    wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);
    //initscr();
    // wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);

    int start_y, start_x;
    start_y = start_x = 10;

    WINDOW *win = newwin(4, 15, 1, 1);
    refresh();

    box(win, 0, 0);
    wrefresh(win);

    mvprintw(3, 4, "ARCADE");

    mvprintw(8, 3, "Nibbler");
    printw("\n");


    mvprintw(10, 3, "Pacman");
    printw("\n");

    mvprintw(8, 2, "-");
    mvprintw(10, 2, "-");

    mvprintw(10, 3, "[N] to use ncurses library (default)");
    mvprintw(12, 3, "[S] to use SDL library");
    mvprintw(14, 3, "[C] to use SFML library");

    int ch = getch();

    switch(ch)
    {
    case KEY_UP:
        mvprintw(10, 2, " ");
        mvprintw(8, 2, "-");
        break;
    case KEY_DOWN:      
        mvprintw(8, 2, " ");
        mvprintw(10, 2, "-");
        //printw("\nDown Arrow");
        break;
    case KEY_ENTER:
        printw("\nEnter Key");
        break;

    case 'n':
        mvprintw(14, 2, " ");
        mvprintw(12, 2, " ");
        mvprintw(10, 2, "-");

    case 's':
        mvprintw(10, 2, " ");
        mvprintw(14, 2, " ");
        mvprintw(12, 2, "-");

    case 'c':
        mvprintw(10, 2, " ");
        mvprintw(12, 2, " ");
        mvprintw(14, 2, "-");
    default:    
        printw("\nThe pressed key is %c",ch);

    }

    refresh();
    //}
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