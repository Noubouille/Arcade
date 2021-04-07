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
	    std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
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
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_image);


    SDL_Color White = {255, 255, 255, 0};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(_font, "Nibbler", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    SDL_Texture* Message = SDL_CreateTextureFromSurface(this->_renderer, surfaceMessage); //now you can convert it into a texture

    SDL_Rect Text_rect1 = {0, 0, surfaceMessage->w, surfaceMessage->h};


    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_RenderCopy(this->_renderer, Message, NULL, &Text_rect1); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

    SDL_RenderPresent(_renderer);


    // sf::Sprite bg_sprite(bg);
    // sf::Text bar_font("-------", _font, 35);
    // sf::Text Nibbler_font("Nibbler", _font, 35);
    // sf::Text Pacman_font("Pacman", _font, 35);
    // bar_font.setPosition(450, pos_bar_y);
    // Nibbler_font.setPosition(450, 300);
    // Pacman_font.setPosition(450, 360);

    // sf::Text next_font("[F1] next graphical library", _font, 35);
    // sf::Text prev_font("[F2] previous graphical library", _font, 35);
    // next_font.setPosition(50, 580);
    // prev_font.setPosition(50, 640);

    // bg_sprite.setTexture(bg);

    // this->_window.clear(sf::Color(0, 0, 0));
    // this->_window.draw(this->_bgSprite);
    // this->_window.draw(Pacman_font);
    // this->_window.draw(Nibbler_font);
    // this->_window.draw(bar_font);

    // this->_window.draw(next_font);
    // this->_window.draw(prev_font);

    // bar_font.setPosition(450, pos_bar_y);

    // this->_window.display();
}

void SDL::drawGame()
{
}

MonEnum SDL::getEvent()
{
    SDL_Event event;
	// sf::Event event;
    SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                std::cout << "sf::Event::CLOSE sdl" << std::endl;
                // quit = true;
                exit(0);
                break;
            case SDLK_ESCAPE:
                std::cout << "sf::Event::CLOSE sdl" << std::endl;
                // quit = true;
                exit(0);
                break;
            case SDLK_LEFT:
                return MonEnum::LEFT_ARROW;
                break;
            case SDLK_RIGHT:
                return MonEnum::RIGHT_ARROW;
                break;
            case SDLK_UP:
                return MonEnum::UP_ARROW;
                break;
            case SDLK_DOWN:
                return MonEnum::DOWN_ARROW;
                break;
            case SDLK_F1:
                return MonEnum::F1;
                break;
            case SDLK_F2:
                return MonEnum::F2;
                break;
            default :
                return MonEnum::NO_INPUT;
        }

    // while (_window.pollEvent(event)) {
    //     if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
    //         std::cout << "sf::Event::CLOSE" << std::endl;
    //         _window.close();
    //         exit(0);
    //         return MonEnum::CLOSE;
    //     }
    //     else if (event.type == sf::Event::KeyPressed) {
    //         switch (event.key.code) {
    //         case sf::Keyboard::Left :
    //             return MonEnum::LEFT_ARROW;
    //         case sf::Keyboard::Right :
    //             return MonEnum::RIGHT_ARROW;
    //         case sf::Keyboard::Up :
    //             if (this->bar_nb > 1) {
    //                 this->pos_bar_y -= 60;
    //                 this->bar_nb--;
    //                 this->_gameName = "NIBBLER";

    //             }
    //             return MonEnum::UP_ARROW;
    //         case sf::Keyboard::Down :
    //             if (this->bar_nb < 2) {
    //                 this->pos_bar_y += 60;
    //                 this->bar_nb++;
    //                 this->_gameName = "PACMAN";
    //             }
    //             return MonEnum::DOWN_ARROW;
    //         case sf::Keyboard::Space :
    //             return MonEnum::SPACE;
    //         case sf::Keyboard::BackSpace :
    //             return MonEnum::BACKSPACE;
    //         case sf::Keyboard::Return :
    //             return MonEnum::ENTER;
    //         case sf::Keyboard::Escape :
    //             return MonEnum::ESCAPE;
    //         case sf::Keyboard::A :
    //             return MonEnum::A_KEY;
    //         case sf::Keyboard::B :
    //             return MonEnum::B_KEY;
    //         case sf::Keyboard::C :
    //             return MonEnum::C_KEY;
    //         case sf::Keyboard::D :
    //             return MonEnum::D_KEY;
    //         case sf::Keyboard::E :
    //             return MonEnum::E_KEY;
    //         case sf::Keyboard::F :
    //             return MonEnum::F_KEY;
    //         case sf::Keyboard::G :
    //             return MonEnum::G_KEY;
    //         case sf::Keyboard::H :
    //             return MonEnum::H_KEY;
    //         case sf::Keyboard::I :
    //             return MonEnum::I_KEY;
    //         case sf::Keyboard::J :
    //             return MonEnum::J_KEY;
    //         case sf::Keyboard::K :
    //             return MonEnum::K_KEY;
    //         case sf::Keyboard::L :
    //             return MonEnum::L_KEY;
    //         case sf::Keyboard::M :
    //             return MonEnum::M_KEY;
    //         case sf::Keyboard::N :
    //             return MonEnum::N_KEY;
    //         case sf::Keyboard::O :
    //             return MonEnum::O_KEY;
    //         case sf::Keyboard::P :
    //             return MonEnum::P_KEY;
    //         case sf::Keyboard::Q :
    //             return MonEnum::Q_KEY;
    //         case sf::Keyboard::R :
    //             return MonEnum::R_KEY;
    //         case sf::Keyboard::S :
    //             return MonEnum::S_KEY;
    //         case sf::Keyboard::T :
    //             return MonEnum::T_KEY;
    //         case sf::Keyboard::U :
    //             return MonEnum::U_KEY;
    //         case sf::Keyboard::V :
    //             return MonEnum::V_KEY;
    //         case sf::Keyboard::W :
    //             return MonEnum::W_KEY;
    //         case sf::Keyboard::X :
    //             return MonEnum::X_KEY;
    //         case sf::Keyboard::Y :
    //             return MonEnum::Y_KEY;
    //         case sf::Keyboard::Z :
    //             return MonEnum::Z_KEY;
    //         case sf::Keyboard::F1 :
    //             return MonEnum::F1;
    //         case sf::Keyboard::F2 :
    //             return MonEnum::F2;
    //         case sf::Keyboard::F3 :
    //             return MonEnum::F3;
    //         case sf::Keyboard::F4 :
    //             return MonEnum::F4;
    //         case sf::Keyboard::F5 :
    //             return MonEnum::F5;
    //         case sf::Keyboard::F6 :
    //             return MonEnum::F6;
    //         case sf::Keyboard::F7 :
    //             return MonEnum::F7;
    //         case sf::Keyboard::F8 :
    //             return MonEnum::F8;
    //         case sf::Keyboard::F9 :
    //             return MonEnum::F9;
    //         case sf::Keyboard::F10 :
    //             return MonEnum::F10;
    //         case sf::Keyboard::F11 :
    //             return MonEnum::F11;
    //         case sf::Keyboard::F12 :
    //             return MonEnum::F12;
    //         default :
    //             return MonEnum::NO_INPUT;
    //         }
    //     }
    // }
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