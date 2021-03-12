/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** main
*/

#include <vector>
#include <cstring>
#include <iostream>

void help()
{
    std::cerr << "USAGE: ./arcade ./lib/lib_arcade_example.so" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && !std::strcmp(av[1], "-h"))
    {
	    help();
	    return (0);
    }
    if (ac < 2 || ac >= 3) {
        help();
        return 0;
    }


    return 0;
}