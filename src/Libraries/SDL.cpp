/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SDL
*/

#include "SDL.hpp"

SDL::SDL()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    this->_gameName = "NIBBLER";
    this->_bgSize = std::make_pair(600, 600);
    this->_font = TTF_OpenFont("./assets/Arcade.ttf", 35);
    if ( !_font ) {
	    std::cout << TTF_GetError() << std::endl;
    }
}

SDL::~SDL() {}

void SDL::startWindow()
{
    this->_window = SDL_CreateWindow("Arcade sdl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 1080, 0);
    this->_image = SDL_LoadBMP("./assets/bg.bmp");
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_image);
}

void SDL::drawMenu()
{
    SDL_Color White = {255, 255, 255, 0};

    SDL_Surface* surfaceCurrentlib_text = TTF_RenderText_Solid(_font, "Current lib : SDL", White);
    SDL_Texture* Currentlib_text = SDL_CreateTextureFromSurface(this->_renderer, surfaceCurrentlib_text);
    SDL_Rect Text_currentlib = {380, 50, surfaceCurrentlib_text->w, surfaceCurrentlib_text->h};


    SDL_Surface* surfaceNibbler_text = TTF_RenderText_Solid(_font, "Nibbler", White);
    SDL_Texture* Nibbler_text = SDL_CreateTextureFromSurface(this->_renderer, surfaceNibbler_text);
    SDL_Rect Text_rect2_pacman = {450, 360, surfaceNibbler_text->w, surfaceNibbler_text->h};

    SDL_Surface* surfacePacman_text = TTF_RenderText_Solid(_font, "Pacman", White);
    SDL_Texture* Pacman_text = SDL_CreateTextureFromSurface(this->_renderer, surfacePacman_text);
    SDL_Rect Text_rect1 = {450, 300, surfacePacman_text->w, surfacePacman_text->h};

    SDL_Surface* surfaceTiret_text = TTF_RenderText_Solid(_font, "*-------*", White);
    SDL_Texture* Tiret_text = SDL_CreateTextureFromSurface(this->_renderer, surfaceTiret_text);
    SDL_Rect Text_tiret_rect = {435, pos_bar_y, surfaceTiret_text->w, surfaceTiret_text->h};

    SDL_Surface* surfaceNextLib_text = TTF_RenderText_Solid(_font, "[F1] next graphical library", White);
    SDL_Texture* NextLib_text = SDL_CreateTextureFromSurface(this->_renderer, surfaceNextLib_text);
    SDL_Rect Text_NextLib_rect = {50, 580, surfaceNextLib_text->w, surfaceNextLib_text->h};

    SDL_Surface* surfacePrevLib_text = TTF_RenderText_Solid(_font, "[F2] previous graphical library", White);
    SDL_Texture* PrevLib_text = SDL_CreateTextureFromSurface(this->_renderer, surfacePrevLib_text);
    SDL_Rect Text_PrevLib_rect = {50, 640, surfacePrevLib_text->w, surfacePrevLib_text->h};

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

    SDL_RenderCopy(_renderer, _texture, NULL, NULL); //render bg
    SDL_RenderCopy(this->_renderer, Nibbler_text, NULL, &Text_rect1);
    SDL_RenderCopy(this->_renderer, Pacman_text, NULL, &Text_rect2_pacman);
    SDL_RenderCopy(this->_renderer, Currentlib_text, NULL, &Text_currentlib); //current lib
    SDL_RenderCopy(this->_renderer, Tiret_text, NULL, &Text_tiret_rect); // -----
    SDL_RenderCopy(this->_renderer, NextLib_text, NULL, &Text_NextLib_rect); // F1
    SDL_RenderCopy(this->_renderer, PrevLib_text, NULL, &Text_PrevLib_rect); // F2

    SDL_RenderPresent(_renderer);
}

void SDL::drawGame()
{
}

MonEnum SDL::getEvent()
{
    SDL_Event event;
	// sf::Event event;

    while (SDL_PollEvent(&event) != 0) {
    // SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                std::cout << "sf::Event::CLOSE sdl" << std::endl;
                exit(0);
                break;
            default :
                break;
        }
        switch (event.key.keysym.sym) {
            case SDLK_q:
                std::cout << "sf::Event::CLOSE sdl" << std::endl;
                exit(0);
                break;
            case SDLK_LEFT:
                std::cout << "left arrow" << std::endl;
                return MonEnum::LEFT_ARROW;
                break;
            case SDLK_RIGHT:
                std::cout << "right arrow" << std::endl;
                return MonEnum::RIGHT_ARROW;
                break;
            case SDLK_UP:
                if (this->bar_nb > 1) {
                    this->pos_bar_y -= 60;
                    this->bar_nb--;
                    this->_gameName = "NIBBLER";

                }
                return MonEnum::UP_ARROW;
                break;
            case SDLK_DOWN:
                if (this->bar_nb < 2) {
                    this->pos_bar_y += 60;
                    this->bar_nb++;
                    this->_gameName = "PACMAN";
                }
                return MonEnum::DOWN_ARROW;
                break;
            case SDLK_F1:
                return MonEnum::F1;
                break;
            case SDLK_F2:
                return MonEnum::F2;
                break;
            case SDLK_RETURN:
                return MonEnum::ENTER;
                break;

            default :
                return MonEnum::NO_INPUT;
        }
    }
    return MonEnum::NO_INPUT;

}

std::string SDL::getNameGame()
{
    return _gameName;
}

void SDL::destroyWindow()
{
    // this->_window.close();
    SDL_Quit();
}

void SDL::clearWindow()
{
    SDL_RenderClear(this->_renderer);
}

void SDL::updateWindow()
{
    SDL_RenderPresent(this->_renderer);
    // this->_window.display();
}

std::string SDL::getLibName()
{
    return "SDL";
}

void SDL::drawBackground(const std::string &Background)
{
    if (Background.empty()) {
        return;
    }

	// sf::Texture texture;
	// texture.loadFromFile(Background);
	// sf::Sprite sprite;
	// sprite.setTexture(texture);
	// sprite.setPosition(sf::Vector2f(0 ,0));
	// _window.draw(sprite);
}

void SDL::drawMain(std::vector<Pixel> snake)
{
    // if (m_elapsedTime.asSeconds() > 0.1) {

        for (auto it = std::next(snake.begin()); it != snake.end(); it++) {

            // sf::Texture texture;
            // if (!texture.loadFromFile(it->pathSprite)) {
            //     return ;
            // }

            // sf::Sprite sprite;
            // sprite.setTexture(texture);
            // sprite.setPosition(sf::Vector2f(it->x, it->y));
            // _window.draw(sprite);
            // std::cout << "le snake pos x : " << it->x << std::endl;
            // std::cout << "le snake pos y : " << it->y << std::endl;
        }
    //     m_elapsedTime = sf::Time::Zero;
    // }
}

void SDL::drawSprite(std::vector<Pixel> sprite) {
    for (auto it = std::next(sprite.begin()); it != sprite.end(); it++) {

        // sf::Texture texture;
        // texture.loadFromFile(it->pathSprite);
        // sf::Sprite sprite;
        // sprite.setTexture(texture);
        // sprite.setPosition(sf::Vector2f(it->x, it->y));
        // _window.draw(sprite);
    }
}

std::pair<int, int> SDL::sendBgSize()
{
    return _bgSize;
}

void SDL::putText(const Text &some_text)
{
    // std::cout << "le text :" << some_text.text << std::endl;
    // sf::Text text(some_text.text, _font);
	// text.setPosition(some_text.x, some_text.y);
	// text.setCharacterSize(32);
	// text.setFillColor(sf::Color::White);
	// _window.draw(text);
}


extern "C" IGraphic *createLibrary()
{
	return new SDL();
}