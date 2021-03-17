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
class ILibrary;
// class LibLoad;

class Core {
    public:
        IGraphic *_IGraphic;
        LibLoad *_LibLoad;
        Core(const std::string &lib_name);
        ~Core();
        void gameMenu();
        void getGraphicLib(const std::string &lib_name);
        // struct Lib {
        // 	std::string _currentPath;
        // 	std::vector<std::string> _listLib;
        void *_currentLib;
        // 	// void *_currentObject;
        // };
        std::vector<std::string> _listLib;
    protected:
    private:

};

#endif /* !CORE_HPP_ */
