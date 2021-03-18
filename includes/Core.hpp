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
// class ILibrary;
// class LibLoad;

namespace Input
{
    
} // namespace name


	typedef enum {
		NO_INPUT = -1,
		ENTER,
		BACKSPACE,
		SPACE,
		ESCAPE,
		UP_ARROW,
		DOWN_ARROW,
		LEFT_ARROW,
		RIGHT_ARROW,
		A_KEY,
		B_KEY,
		C_KEY,
		D_KEY,
		E_KEY,
		F_KEY,
		G_KEY,
		H_KEY,
		I_KEY,
		J_KEY,
		K_KEY,
		L_KEY,
		M_KEY,
		N_KEY,
		O_KEY,
		P_KEY,
		Q_KEY,
		R_KEY,
		S_KEY,
		T_KEY,
		U_KEY,
		V_KEY,
		W_KEY,
		X_KEY,
		Y_KEY,
		Z_KEY,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		QUIT_EVENT
	} _Input;

class Core {
    public:
        IGraphic *_IGraphicLib;
        LibLoad *_LibLoad;
        Core(const std::string &lib_name);
        ~Core();
        void loopMenu();
        void getGraphicLib(const std::string &lib_name);
        // struct Lib {
        // 	std::string _currentPath;
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
