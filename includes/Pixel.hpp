/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Pixel
*/

#ifndef PIXEL_HPP_
#define PIXEL_HPP_
#include <string>

typedef struct {
    int x;
    int y;
    std::string pathSprite;
} Pixel;

typedef struct {
    int x;
    int y;
    std::string text;
} Text;

#endif /* !PIXEL_HPP_ */
