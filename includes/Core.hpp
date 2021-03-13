/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Core
*/

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../includes/Igraphic.hpp"

#ifndef CORE_HPP_
#define CORE_HPP_

class Core {
    public:
        Igraphic *graphic;

        Core(const std::string &lib_name);
        ~Core();
    void gameMenu();
    void getGraphicLib(const std::string &lib_name);
	// struct Lib {
	// 	std::string _currentPath;
	// 	std::vector<std::string> _listLib;
	// 	void *_currentLib;
	// 	// void *_currentObject;
	// };
    protected:
    private:
    std::vector<std::string> _listLib;


};

#endif /* !CORE_HPP_ */
