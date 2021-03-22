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
    this->_currentPath = realpath(lib_name.c_str(), nullptr);

    if (this->_currentPath.empty()) {
        perror(lib_name.c_str());
        exit(84);
    }
    std::cout << "lib name :" << lib_name << std::endl;
    this->getGraphicLib();

    this->getAllGraphicLibs(this->_currentPath);
    this->mainLoop();
}

void Core::getGraphicLib()
{
    this->_currentLib = _LibLoad->loadlibrary(this->_currentPath); //dlopen()
    // std::cout << "la current lib :" << this->_currentLib << std::endl;
    auto createLibraryFunction = (IGraphic* (*)())_LibLoad->exec_function(this->_currentLib, "createLibrary");
    this->_IGraphicLib = (*createLibraryFunction)();

}

void Core::getAllGraphicLibs(const std::string &lib_name)
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

void Core::nextLibrary()
{
    if (this->_listLib.size() <= 1) return; //si 1 seule lib dispo

    auto iterator = std::find(this->_listLib.begin(), this->_listLib.end(), this->_currentPath);

    if (iterator + 1 == this->_listLib.end()) {
        this->_currentPath = this->_listLib.front();
        getGraphicLib();
    } else {
        this->_currentPath = *(iterator + 1);
        getGraphicLib();
    }
    mainLoop();
}

void Core::prevLibrary()
{
    if (this->_listLib.size() <= 1) return; //si 1 seule lib dispo

    auto iterator = std::find(this->_listLib.begin(), this->_listLib.end(), this->_currentPath);

    if (iterator == this->_listLib.begin()) {
        this->_currentPath = this->_listLib.back();
        getGraphicLib();
    } else {
        this->_currentPath = *(iterator - 1);
        getGraphicLib();
    }
    mainLoop();
}

void Core::mainLoop()
{
    this->_IGraphicLib->startWindow();
    for (;1;) {
        int Input = this->_IGraphicLib->getEvent();

        if (Input == MonEnum::F1) {
            std::cout << "MonEnum::F1 next lib" << std::endl;
            this->_IGraphicLib->destroyWindow();
            nextLibrary();
        }
        if (Input == MonEnum::F2) {
            this->_IGraphicLib->destroyWindow();
            std::cout << "MonEnum::F2 prev lib" << std::endl;
            prevLibrary();
        }
        if (Input == MonEnum::ENTER) {
            this->_stateMenu = false;
            std::cout << "le jeu lancé :" << this->_IGraphicLib->getNameGame() << std::endl;
        }

        if (this->_stateMenu == true) {
            loopMenu(Input);
        } else {
            loopGame(Input);
        }
    }

}

void Core::loopMenu(int Input)
{
    this->_IGraphicLib->drawMenu();

}

void Core::loopGame(int Input)
{
    this->_IGraphicLib->drawGame();
}


Core::~Core()
{
    // std::cout << "je suis le destructor" << std::endl;
}
