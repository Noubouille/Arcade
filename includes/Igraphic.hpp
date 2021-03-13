/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Igraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

class Igraphic
{
    public:
        Igraphic();
        ~Igraphic();

        virtual int startWindow() = 0;

        virtual int getEvent() = 0;
        virtual int drawMenu() = 0;
        virtual int drawGame() = 0;
};

#endif /* !IGRAPHIC_HPP_ */
