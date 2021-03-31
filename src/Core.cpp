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

    this->getAllLibs();
    this->getGameLib();
    this->mainLoop();
}

void Core::getGameLib()
{
    std::cout << "La premiere game :" << this->_listGames.front() << std::endl;

    this->_currentGame = _LibLoad->loadlibrary(this->_listGames.front()); //dlopen()
    if (_LibLoad->checkifGame(this->_currentGame) == true) {
        auto createGameFunction = (IGames* (*)())_LibLoad->exec_function(this->_currentGame, "createGame");
        this->_IGamesLib = (*createGameFunction)();

    } else {
        std::cout << "No lib games inside ./lib ?!" << std::endl;
        exit(84);
    }
}

void Core::getGraphicLib()
{
    this->_currentLib = _LibLoad->loadlibrary(this->_currentPath); //dlopen()
    if (_LibLoad->checkifGame(this->_currentLib) == false) {
        auto createLibraryFunction = (IGraphic* (*)())_LibLoad->exec_function(this->_currentLib, "createLibrary");
        this->_IGraphicLib = (*createLibraryFunction)();

    } else {
        std::cout << "You must give a library and not a game !" << std::endl;
        exit(84);
    }
}

void Core::getAllLibs()
{
    // recuperer les libs dans ./lib
	std::regex r("/arcade_(.+)\\.so$");
	std::smatch m;

    for (const auto & entry : fs::directory_iterator(realpath("./lib", nullptr))) {
        std::string path = entry.path().c_str();

        if (std::find(this->_listLib.begin(), this->_listLib.end(), path) == this->_listLib.end() && std::regex_search(path, m, r)) {
            // std::string tmp = entry.path();
            // std::size_t found = tmp.find_last_of("/\\");
            // tmp = tmp.substr(found + 1);
            void *tmp = _LibLoad->loadlibrary(entry.path().c_str()); //dlopen()
            if (_LibLoad->checkifGame(tmp) == false) {

                this->_listLib.push_back(entry.path().c_str());
            } else {
                this->_listGames.push_back(entry.path().c_str());
            }
        }
    }

    if (this->_listGames.empty()) {
        std::cout << "No lib games inside ./lib" << std::endl;
        exit(84);
    }
    // affiches toutes les libs
    for (std::string str: this->_listLib)
        std::cout << "les libs graphiques : " << str << std::endl;
    for (std::string str: this->_listGames) {
        std::cout << "les libs games : " << str << std::endl;
    }
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
        MonEnum Input = this->_IGraphicLib->getEvent();
        this->_IGraphicLib->clearWindow();
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
            std::cout << "le jeu lancé grphic lib :" << this->_IGraphicLib->getNameGame() << std::endl;
            std::cout << "le jeu lancé lib :" << this->_IGamesLib->getName() << std::endl;
            if (this->_IGraphicLib->getNameGame() == this->_IGamesLib->getName()) {
                this->_stateMenu = false;

            }
        }

        if (this->_stateMenu == true) {
            loopMenu(Input);
        } else {
            loopGame(Input);
        }
    }

}

void Core::loopMenu(MonEnum Input)
{
    this->_IGraphicLib->drawMenu();

}

void Core::loopGame(MonEnum Input)
{

    this->_IGraphicLib->drawBackground(this->_IGamesLib->getBg());
    this->_IGamesLib->getInput(Input);
    // this->_IGraphicLib->drawSprite("assets/Nibbler/body.png", 500, 500);
    // this->_IGraphicLib->drawGame();
    this->_IGraphicLib->drawSprite(this->_IGamesLib->getSprite());
    this->_IGraphicLib->drawMain(this->_IGamesLib->getMain());
    this->_IGamesLib->updateGame();
    this->_IGraphicLib->updateWindow();
}

Core::~Core()
{
    // std::cout << "je suis le destructor" << std::endl;
}
