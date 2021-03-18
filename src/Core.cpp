/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Core
*/

#include "../includes/Core.hpp"
#include <filesystem>
#include <experimental/filesystem>
#include <regex>

namespace fs = std::experimental::filesystem;

Core::Core(const std::string &lib_name)
{
    const auto libpath = realpath(lib_name.c_str(), nullptr);

    if (libpath == nullptr) {
        perror(lib_name.c_str());
        exit(84);
    }
    std::cout << "lib name :" << lib_name << std::endl;


	// std::cout << "le libpath :" << libpath << std::endl;

    this->_currentLib = _LibLoad->loadlibrary(libpath); //dlopen()
    // std::cout << "la current lib :" << this->_currentLib << std::endl;
    auto createLibraryFunction = (IGraphic* (*)())_LibLoad->exec_function(this->_currentLib, "createLibrary");
    this->_IGraphicLib = (*createLibraryFunction)();

    this->getGraphicLib(libpath);
    this->loopMenu();
}

void Core::getGraphicLib(const std::string &lib_name)
{
    // recuperer les libs dans ./lib
	std::regex r("/arcade_(.+)\\.so$");
	std::smatch m;

    for (const auto & entry : fs::directory_iterator(realpath("./lib", nullptr))) {
        std::string path = entry.path().c_str();

        if (std::find(this->_listLib.begin(), this->_listLib.end(), path) == this->_listLib.end() && std::regex_search(path, m, r)) {
            this->_listLib.push_back(entry.path().c_str());
        }
    }
    // affiches toutes les libs
    for (std::string str: this->_listLib)
        std::cout << "les libs : " << str << std::endl;
}


void Core::loopMenu()
{
    for (;1;) { //ou !exit

        // auto input = _IGraphicLib->getEvent();

        if (this->_stateMenu == true) {
            this->_IGraphicLib->drawMenu();
        } else {

        }
    }
}

Core::~Core()
{
    // std::cout << "je suis le destructor" << std::endl;
}
