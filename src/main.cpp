/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** main
*/

#include <vector>
#include <cstring>
#include <iostream>

#include "../includes/Core.hpp"

int help()
{
    std::cerr << "USAGE: ./arcade ./lib/lib_arcade_example.so" << std::endl;
    return 84;
}

int main(int ac, char **av)
{
    if (ac == 2 && !std::strcmp(av[1], "-h")) {
        return help();
    }
    if (ac < 2 || ac >= 3) {
        return help();
    }
    Core core(av[1]);
    // core.gameMenu();
    return 0;
}