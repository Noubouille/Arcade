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
#include <unistd.h>
#include <bits/stdc++.h>

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
    _Timer = new Timer();

    this->getGraphicLib();
    this->getAllLibs();
    this->getFirstGameLib();
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

void Core::getFirstGameLib()
{
    std::cout << "La premiere game :" << this->_listGames.front() << std::endl;
    this->_currentPathGame = this->_listGames.front();
    std::pair<int ,int> pair_ = this->_IGraphicLib->sendBgSize();

    this->_currentGame = _LibLoad->loadlibrary(this->_listGames.front()); //dlopen()
    if (_LibLoad->checkifGame(this->_currentGame) == true) {
        auto createGameFunction = (IGames* (*)(std::pair<int, int>))_LibLoad->exec_function(this->_currentGame, "createGame");
        this->_IGamesLib = (*createGameFunction)(pair_);

    } else {
        std::cout << "No lib games inside ./lib ?!" << std::endl;
        exit(84);
    }
}

void Core::getGameLib()
{
    std::pair<int ,int> pair_ = this->_IGraphicLib->sendBgSize();

    this->_currentGame = _LibLoad->loadlibrary(this->_currentPathGame); //dlopen()
    if (_LibLoad->checkifGame(this->_currentGame) == true) {
        auto createGameFunction = (IGames* (*)(std::pair<int, int>))_LibLoad->exec_function(this->_currentGame, "createGame");
        this->_IGamesLib = (*createGameFunction)(pair_);

    } else {
        std::cout << "No lib games inside ./lib ?!" << std::endl;
        exit(84);
    }
}

void Core::getNextGameLib(bool loop)
{
    if (this->_listGames.size() <= 1) return; //si 1 seule lib dispo
    // std::cout << "je getNextGameLib" << std::endl;

    auto iterator = std::find(this->_listGames.begin(), this->_listGames.end(), this->_currentPathGame);

    if (iterator + 1 == this->_listGames.end()) {
        this->_currentPathGame = this->_listGames.front();
        getGameLib();
    } else {
        this->_currentPathGame = *(iterator + 1);
        getGameLib();
    }

    if (loop == true) {
    std::cout << "je getNextGameLib la fin dans le loop" << std::endl;
        this->_stateMenu = false;
        mainLoop();

    }
}

void Core::getPrevGameLib()
{
    if (this->_listGames.size() <= 1) return; //si 1 seule lib dispo

    auto iterator = std::find(this->_listGames.begin(), this->_listGames.end(), this->_currentPathGame);

    if (iterator == this->_listGames.begin()) {
        this->_currentPathGame = this->_listGames.back();
        getGraphicLib();
    } else {
        this->_currentPathGame = *(iterator - 1);
        getGraphicLib();
    }

    // if (loop == true) {
    // std::cout << "je getNextGameLib la fin dans le loop" << std::endl;
        this->_stateMenu = false;
        mainLoop();

    // }
}

void Core::getAllLibs()
{
    // recuperer les libs dans ./lib
	std::regex r("/arcade_(.+)\\.so$");
	std::smatch m;

    for (const auto & entry : fs::directory_iterator(realpath("./lib", nullptr))) {
        std::string path = entry.path().c_str();

        if (std::find(this->_listLib.begin(), this->_listLib.end(), path) == this->_listLib.end() && std::regex_search(path, m, r)) {
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
    for (; _EndGame; ) {
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
        if (Input == MonEnum::F3) {
            std::cout << "MonEnum::F3 next game" << std::endl;
            this->_IGraphicLib->destroyWindow();

            getNextGameLib(true);
        // this->_IGraphicLib->clearWindow();


        }
        if (Input == MonEnum::F4) {
            this->_IGraphicLib->destroyWindow();

            getPrevGameLib();
            std::cout << "MonEnum::F4 prev game" << std::endl;
        // this->_IGraphicLib->clearWindow();

        }

        if (Input == MonEnum::ENTER) {
            // std::cout << "le getName" << this->_IGamesLib->getName() << std::endl;
            // std::cout << "le this->_IGraphicLib->getNameGame()" << this->_IGraphicLib->getNameGame() << std::endl;
            if (this->_IGraphicLib->getNameGame() == this->_IGamesLib->getName()) {
                this->_stateMenu = false;
            } else {
                // std::cout << "je suis dans le else " << std::endl;
                getNextGameLib(false);
                // std::cout << "le getName apres" << this->_IGamesLib->getName() << std::endl;
                // std::cout << "le this->_IGraphicLib->getNameGame() apres" << this->_IGraphicLib->getNameGame() << std::endl;
                this->_stateMenu = false;
            }
        }

        if (this->_stateMenu == true) {
            loopMenu(Input);
        } else {
            loopGame(Input);
        }
    }
    // this->_IGraphicLib->destroyWindow();
    // exit(0);

}

void Core::loopMenu(MonEnum Input)
{
    Input = Input;
    this->_IGraphicLib->drawMenu();

}

void Core::loopGame(MonEnum Input)
{
    if (m_bRunning == false && this->_IGamesLib->isGameStart()) {
        m_bRunning = true;
        _Timer->start();
    }

    this->_IGraphicLib->clearWindow();
    this->_IGraphicLib->getMusic(this->_IGamesLib->sendMusic());
    this->_IGraphicLib->drawBackground(this->_IGamesLib->getBg());

    this->_IGraphicLib->putText({320, 800, std::string("You are playing at ") + this->_IGamesLib->getName()});
    this->_IGraphicLib->putText({730, 20, std::string("Score : ") + std::to_string(this->_IGamesLib->getScore())});
    if (this->_IGamesLib->getName() == "NIBBLER") {
        this->_IGraphicLib->putText({660, 80, std::string("Time : ") + std::to_string(returnSecondsLeft(_Timer->elapsedSeconds()))+ " Seconds"});
    }

    this->_IGamesLib->getLibName(this->_IGraphicLib->getLibName());
    this->_IGamesLib->getInput(Input);
    if (_pause && Input != MonEnum::NO_INPUT) {
        _pause = false;
    }
    if (Input == MonEnum::P_KEY) {
        if (_pause == true) {
            _pause = false;
        } else {
            _timeLeftIsPaused = _Timer->elapsedSeconds();
            _time = ifGamePausedInt(_timeLeftIsPaused);
            _pause = true;
        }
    }
    if (_pause) {
        this->_IGraphicLib->putText({500, 500, std::string("Pause !")});

        _Timer->start();
    }

    this->_IGraphicLib->utilityGame();
    // this->_IGraphicLib->drawSprite(this->_IGamesLib->getSprite());
    this->_IGraphicLib->drawSprites(this->_IGamesLib->getSprites());

    this->_IGraphicLib->drawMain(this->_IGamesLib->getMain());
    this->_IGraphicLib->updateWindow();

    if (Input == MonEnum::R_KEY) {
        std::cout << "Je reset" << std::endl;

        this->_IGamesLib->reset();
        _Timer->start();
        _time = 25;
    }

    if ( _Timer->elapsedSeconds() > _time && this->_IGamesLib->getName() == "NIBBLER") {
        this->getScores();
        this->_IGamesLib->reset();
        this->_IGraphicLib->reset();
        this->_stateMenu = true;
        m_bRunning = false;
        _time = 25;
    }

    if (this->_IGamesLib->isGameOver() || Input == MonEnum::M_KEY) {
        this->getScores();
        this->_IGamesLib->reset();
        this->_IGraphicLib->reset();
        this->_stateMenu = true;
        m_bRunning = false;
        _time = 25;
    }
    this->_IGamesLib->updateGame();
}

int Core::returnSecondsLeft(double time)
{
    return _time - (int)round(time);
}

int Core::ifGamePausedInt(double time)
{
    auto tmp = _time - (int)round(time);
    return tmp;
}


void Core::getScores()
{
    std::string score = std::to_string(this->_IGamesLib->getScore());
    std::string username = this->_IGraphicLib->getUsername();
    if (!score.empty()) {
        score.insert(score.length() - 1, "\n");
    }

    std::fstream scores;
    scores.open("scores.txt", std::fstream::app);

    if (!scores) {
        std::cout << "Scores file not found" << std::endl;
    } else {
        scores << username << score;
        scores.close();
    }

	scores.open("scores.txt",std::ios::in);
    if (scores.is_open()) {
        std::string line;
        while(getline(scores, line)){
        std::cout << line << "\n";
    }
      scores.close();
    }
}

Core::~Core() {}