/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SDL
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "IGraphic.hpp"
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class SDL : public IGraphic {
    public:
        SDL();
        ~SDL();


        void startWindow();

        MonEnum getEvent();
        void drawMenu();
        void drawGame();
        std::string getNameGame();
        void destroyWindow();
        std::string getLibName();
        void drawBackground(const std::string &Background);
        std::pair<int, int> sendBgSize() override;

        void clearWindow();
        void updateWindow();
        void drawMain(std::vector<Pixel>);
        void drawSprite(std::vector<Pixel> sprite);

        void putText(const Text &text) override;

    protected:
    private:
    TTF_Font *_font = NULL;
    SDL_Surface *_image;
    SDL_Texture *_texture;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    std::string _gameName;
    Uint32 _time = SDL_GetTicks();
    Uint32 _startTime = 0;
    Uint32 _endTime = 0;
    short _fps = 0;
    Uint32 _delta = 0;

    std::pair<int, int> _bgSize;

    int pos_bar_y = 320;
    int bar_nb = 1;
};

extern "C" IGraphic *createLibrary();

#endif /* !SDL_HPP_ */
