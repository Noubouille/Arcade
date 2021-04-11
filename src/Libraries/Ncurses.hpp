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
#include <sys/stat.h>
#include <fstream>
#include <cstring>
#include <unistd.h>
class Ncurses : public IGraphic
{
    public:
        Ncurses();

        ~Ncurses();
        void startWindow();

        MonEnum getEvent();

        void drawMenu();
        void utilityGame();
        std::string getNameGame();
        std::string getUsername() override;
        void destroyWindow();
        void drawBackground(const std::string &Background) override;
        void drawMain(std::vector<Pixel> snake) override;
        void drawSprite(Pixel sprite) override;
        void drawSprites(std::vector<Pixel> sprites) override;



        std::string getLibName() override;
		void clearWindow() override;
		void updateWindow() override;
        std::pair<int, int> sendBgSize() override;
        void putText(const Text &text) override;
        std::string _gameName = "NIBBLER";
        void getMusic(const std::string &Background) override;
        void reset() override;


        WINDOW *window = initscr();
        int _win_y = 0;
        int _win_x = 0;
        private:
        char** _tab;
        std::string _input;
        std::pair<int, int> _bgSize;
        bool _nibbler_selected = true;
        bool _pacman_selected;
        void selectedGame(bool _nibber_selected, bool _pacman_selected);
        void chooseUsername();
        //etc
};
extern "C" IGraphic *createLibrary();
#endif /* !NCURSES_HPP_ */
