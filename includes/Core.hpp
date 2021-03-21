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
#include "../src/LibLoad.hpp"

class Core {
    public:
        IGraphic *_IGraphicLib;
        LibLoad *_LibLoad;
        Core(const std::string &lib_name);
        ~Core();
		void mainLoop();

        void loopMenu(int Input);
        void loopGame(int Input);
        void getAllGraphicLibs(const std::string &lib_name);
        void getGraphicLib();
        void nextLibrary();
        void prevLibrary();
        // struct Lib {
        std::string _currentPath;
        // 	std::vector<std::string> _listLib;
        void *_currentLib;
        // 	// void *_currentObject;
        // };
        bool _stateMenu = true;
        std::vector<std::string> _listLib;


    protected:
    private:

};

#endif /* !CORE_HPP_ */
