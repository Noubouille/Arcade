/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Core
*/


#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../src/Libraries/IGraphic.hpp"
#include "../src/Games/IGames.hpp"
#include "../src/LibLoad.hpp"
#include "Pixel.hpp"

// typedef struct {
//     unsigned int x;
//     unsigned int y;
//     std::string pathSprite;
// } Pixel;

class Core {
    public:
        IGames *_IGamesLib;
        IGraphic *_IGraphicLib;
        LibLoad *_LibLoad;
        Core(const std::string &lib_name);
        ~Core();
		void mainLoop();

        void loopMenu(MonEnum Input);
        void loopGame(MonEnum Input);
        void getAllLibs();
        void getGraphicLib();
        void getGameLib();
        void nextLibrary();
        void prevLibrary();
        // struct Lib {
        std::string _currentPath;
        // 	std::vector<std::string> _listLib;
        void *_currentLib;
        void *_currentGame;
        // 	// void *_currentObject;
        // };
        bool _stateMenu = true;
        bool _pause = false;
        std::vector<std::string> _listLib;
        std::vector<std::string> _listGames;


    protected:
    private:

};

#endif /* !CORE_HPP_ */
