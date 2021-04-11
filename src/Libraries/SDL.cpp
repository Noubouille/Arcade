/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SDL
*/

#include "SDL.hpp"

SDL::SDL()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVERYTHING);
    TTF_Init();
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        exit(84);
    }
    this->_gameName = "NIBBLER";
    this->_bgSize = std::make_pair(600, 600);
    this->_font = TTF_OpenFont("./assets/Arcade.ttf", 35);
    if ( !_font ) {
	    std::cout << TTF_GetError() << std::endl;
    }

    // Mix_FreeMusic(_menuMusic);
    // Mix_FreeMusic(_musicGame);
    _menuMusic = Mix_LoadMUS("./assets/menu_music.ogg");
    // _musicGame = Mix_LoadMUS("./assets/menu_music.ogg");
    Mix_PlayMusic(_menuMusic, -1); //Jouer infiniment la musique
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
}

SDL::~SDL() {}

void SDL::startWindow()
{
    this->_window = SDL_CreateWindow("Arcade sdl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 1080, 0);
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

void SDL::utilityGame()
{
    // if (music_on == false) {
    //     Mix_HaltMusic();
    //     music_on = true;
        // Mix_PlayMusic(_musicGame, -1); //Jouer infiniment la musique
        // Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    // }
}

MonEnum SDL::getEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
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
                return MonEnum::LEFT_ARROW;
                break;
            case SDLK_RIGHT:
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
            case SDLK_F3:
                return MonEnum::F3;
                break;
            case SDLK_F4:
                return MonEnum::F4;
                break;
            case SDLK_RETURN:
                return MonEnum::ENTER;
                break;
            case SDLK_p:
                return MonEnum::P_KEY;
                break;
            case SDLK_r:
                return MonEnum::R_KEY;
                break;
            case SDLK_m:
                return MonEnum::M_KEY;
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
    Mix_CloseAudio();
    SDL_Quit();
}

void SDL::clearWindow()
{
    if (!_startTime) {
        _startTime = SDL_GetTicks();
    } else {
        _delta = _endTime - _startTime;
    }
    SDL_RenderClear(this->_renderer);
}

void SDL::updateWindow()
{
    if (_delta < 16) {
        SDL_Delay(16 - _delta);
    }
    if (_delta > 16) {
        _fps = 1000 / _delta;
    }
    // printf("FPS is: %i \n", _fps);

    _startTime = _endTime;
    _endTime = SDL_GetTicks();
    SDL_RenderPresent(this->_renderer);
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
    std::string tmp = Background + ".bmp";

    SDL_Surface *bg = SDL_LoadBMP(tmp.c_str());
    SDL_Texture *bg_texture = SDL_CreateTextureFromSurface(this->_renderer, bg);
    SDL_Rect Text_bg_rect = {0, 0, bg->w, bg->h};
    SDL_RenderCopy(this->_renderer, bg_texture, NULL, &Text_bg_rect);
    SDL_FreeSurface(bg);

}

void SDL::drawMain(std::vector<Pixel> snake)
{
    // if (m_elapsedTime.asSeconds() > 0.1) {

        for (auto it = std::next(snake.begin()); it != snake.end(); it++) {
            if (it->pathSprite.empty()) {
                return;
            }
            std::string tmp = it->pathSprite + ".bmp";
            // std::cout << "tmp : " << tmp << std::endl;
            SDL_Surface *sprite_surf = SDL_LoadBMP(tmp.c_str());

            SDL_Texture* Sprite_text = SDL_CreateTextureFromSurface(this->_renderer, sprite_surf);
            SDL_Rect Sprite_rect = {it->x, it->y, sprite_surf->w, sprite_surf->h};
            SDL_RenderCopy(this->_renderer, Sprite_text, NULL, &Sprite_rect);
            SDL_FreeSurface(sprite_surf);

        }
    //     m_elapsedTime = sf::Time::Zero;
    // }
}

void SDL::drawSprite(Pixel sprite) {

    std::string tmp = sprite.pathSprite + ".bmp";

    SDL_Surface *sprite_surf = SDL_LoadBMP(tmp.c_str());
    SDL_Texture* Sprite_text = SDL_CreateTextureFromSurface(this->_renderer, sprite_surf);
    SDL_Rect Sprite_rect = {sprite.x, sprite.y, sprite_surf->w, sprite_surf->h};
    SDL_RenderCopy(this->_renderer, Sprite_text, NULL, &Sprite_rect);
    SDL_FreeSurface(sprite_surf);
}

void SDL::drawSprites(std::vector<Pixel> sprites)
{
    for (auto it = std::next(sprites.begin()); it != sprites.end(); it++) {
        std::string tmp = it->pathSprite + ".bmp";

        SDL_Surface *sprite_surf = SDL_LoadBMP(tmp.c_str());
        SDL_Texture* Sprite_text = SDL_CreateTextureFromSurface(this->_renderer, sprite_surf);
        SDL_Rect Sprite_rect = {it->x, it->y, sprite_surf->w, sprite_surf->h};
        SDL_RenderCopy(this->_renderer, Sprite_text, NULL, &Sprite_rect);
        SDL_FreeSurface(sprite_surf);
    }
}

std::pair<int, int> SDL::sendBgSize()
{
    return _bgSize;
}

void SDL::putText(const Text &some_text)
{
    SDL_Color White = {255, 255, 255, 0};

    SDL_Surface* surface_text = TTF_RenderText_Solid(_font, some_text.text.c_str(), White);
    SDL_Texture* _text = SDL_CreateTextureFromSurface(this->_renderer, surface_text);
    SDL_Rect Text__rect = {some_text.x, some_text.y, surface_text->w, surface_text->h};
    SDL_RenderCopy(this->_renderer, _text, NULL, &Text__rect);

}

void SDL::getMusic(const std::string &music)
{
    if (music_game_on == false) {
        _musicGame = Mix_LoadMUS(music.c_str());
        Mix_PlayMusic(_musicGame, -1); //Jouer infiniment la musique
        Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
        music_game_on = true;
    }
}

void SDL::reset() {
    music_game_on = false;
    Mix_PlayMusic(_menuMusic, -1); //Jouer infiniment la musique
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

}


extern "C" IGraphic *createLibrary()
{
	return new SDL();
}