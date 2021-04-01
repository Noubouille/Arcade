/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Igraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <string>
#include <vector>

#include "../../includes/Pixel.hpp"

enum MonEnum {
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
	CLOSE,
	PACMAN,
	NIBBLER
};

class IGraphic
{
    public:

        virtual MonEnum getEvent() = 0;

        virtual void startWindow() = 0;
        virtual void drawMenu() = 0;
        virtual void drawGame() = 0;
		virtual void destroyWindow() = 0;
		virtual void clearWindow() = 0;
		virtual void updateWindow() = 0;
        virtual std::string getNameGame() = 0;
        virtual void drawBackground(const std::string &Background) = 0;
		virtual std::pair<int, int> sendBgSize() = 0;
        virtual void drawMain(std::vector<Pixel> snake) = 0;
        virtual void drawSprite(std::vector<Pixel> sprite) = 0;

		std::pair<int, int> _bgSize;
};

#endif /* !IGRAPHIC_HPP_ */
