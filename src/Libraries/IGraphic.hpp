/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Igraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

class IGraphic
{
    public:
        IGraphic();
        virtual ~IGraphic();

        virtual void startWindow() = 0;
        virtual void getEvent() = 0;
        virtual void drawMenu() = 0;
        virtual void drawGame() = 0;
};

#endif /* !IGRAPHIC_HPP_ */
