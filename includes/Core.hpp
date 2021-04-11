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
#include "Timer.hpp"
#include "Pixel.hpp"
#include <utility>
#include <ctime>
#include <chrono>
#include <time.h>
using namespace std::chrono;

class Core {
    public:
        Timer *_Timer;
        IGames *_IGamesLib;
        IGraphic *_IGraphicLib;
        LibLoad *_LibLoad;
        Core(const std::string &lib_name);
        ~Core();
		void mainLoop();

        void loopMenu(MonEnum Input);
        void loopGame(MonEnum Input);
        void getAllLibs();
        void getScores();
        void getGraphicLib();
        void getFristGameLib();
        void getGameLib();
        void nextLibrary();
        void prevLibrary();
        void getNextGameLib(bool);
        void getPrevGameLib();
        int returnSecondsLeft(double);
        int ifGamePausedInt(double);

        // struct Lib {
        std::string _currentPath;
        std::string _currentPathGame;
        // 	std::vector<std::string> _listLib;
        void *_currentLib;
        void *_currentGame;

        bool _stateMenu = true;
        bool _pause = false;
        std::vector<std::string> _listLib;
        std::vector<std::string> _listGames;


    protected:
    private:
        bool m_bRunning = false;
        bool _EndGame = true;
        double _time = 5;
        double _timeLeftIsPaused = 0;

};

#endif /* !CORE_HPP_ */
