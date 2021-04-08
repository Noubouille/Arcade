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
#include <sys/stat.h>

namespace fs = std::experimental::filesystem;

Core::Core(const std::string &lib_name)
{
    struct stat st;
    if(stat(lib_name.c_str(), &st) != 0) {
        std::cout << "la lib n'existe pas" << std::endl;
        exit(84);

    }
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

void Core::getGameLib()
{
    std::cout << "La premiere game :" << this->_listGames.front() << std::endl;

    std::pair<int ,int> pair_ = this->_IGraphicLib->sendBgSize();
    // std::cout << "le _bgSiz e pair :" << this->_IGraphicLib->sendBgSize().first << std::endl;

    this->_currentGame = _LibLoad->loadlibrary(this->_listGames.front()); //dlopen()
    if (_LibLoad->checkifGame(this->_currentGame) == true) {
        auto createGameFunction = (IGames* (*)(std::pair<int, int>))_LibLoad->exec_function(this->_currentGame, "createGame");
        this->_IGamesLib = (*createGameFunction)(pair_);

    } else {
        std::cout << "No lib games inside ./lib ?!" << std::endl;
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
            // std::cout << "le jeu lancé grphic lib :" << this->_IGraphicLib->getNameGame() << std::endl;
            // std::cout << "le jeu lancé lib :" << this->_IGamesLib->getName() << std::endl;
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
    this->_IGraphicLib->clearWindow();
    this->_IGraphicLib->drawBackground(this->_IGamesLib->getBg());

    // this->_IGraphicLib->putText({320, 800, std::string("You are playing at ") + this->_IGamesLib->getName()});
    // this->_IGraphicLib->putText({730, 20, std::string("Your score is : ") + std::to_string(this->_IGamesLib->getScore())});
    //this->_IGamesLib->bgSize(this->_IGraphicLib->sendBgSize());
    this->_IGamesLib->getLibName(this->_IGraphicLib->getLibName());
    this->_IGamesLib->getInput(Input);
    // std::cout << "input :" << Input << std::endl;
    // if (Input == MonEnum::P_KEY) {
    //     if (_pause == true)_pause = false;
    //     else _pause = true;
    // }
    // if (_pause) {
    //     this->_IGraphicLib->putText({500, 500, std::string("Pause !")});
    // }
    // // this->_IGraphicLib->drawGame();
    this->_IGraphicLib->drawSprite(this->_IGamesLib->getSprite());

    this->_IGraphicLib->drawMain(this->_IGamesLib->getMain());
    this->_IGraphicLib->updateWindow();
    //this->_IGamesLib->updateGame();
}

Core::~Core() {}