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
    unsigned int x;
    unsigned int y;
    std::string text;
    // bool underline;
} Text;

// class Pixel {
//     public:
//         Pixel();
//         ~Pixel();

//     protected:
//     private:
// };

#endif /* !PIXEL_HPP_ */
