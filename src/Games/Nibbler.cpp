/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

bool Nibbler::isGameOver()
{

}

void Nibbler::reset()
{

}

std::string Nibbler::getBg()
{
    return "../../assets/Nibbler/background.png";
}

extern "C" IGames *createGame()
{
	return new Nibbler();
}