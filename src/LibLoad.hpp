/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** LibLoad
*/

#ifndef LIBLOAD_HPP_
#define LIBLOAD_HPP_

#include <dlfcn.h>
#include <iostream>
#include <string>

class LibLoad {
    public:
        LibLoad();
        ~LibLoad();
        void *loadlibrary(std::string librarypath);
        void closeLibrary(void *handle);
        void *exec_function(void *handle, std::string functionName);
        bool checkifGame(void *handle);

    protected:
    private:
};

#endif /* !LIBLOAD_HPP_ */
