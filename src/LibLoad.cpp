/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** LibLoad
*/

#include "LibLoad.hpp"

LibLoad::LibLoad()
{
}

LibLoad::~LibLoad()
{
}

void *LibLoad::loadlibrary(std::string librarypath)
{

    void *handle = dlopen(librarypath.c_str(), RTLD_NOW);
	if (handle == nullptr) {
		std::cerr << dlerror() << std::endl;
        std::cout << "une erreur est survenue" << std::endl;
		exit(84);
	}
    return handle;
}

void LibLoad::closeLibrary(void *handle)
{
	dlclose(handle);
}

void *LibLoad::exec_function(void *handle, std::string functionName)
{
	return dlsym(handle, functionName.c_str());
}

bool LibLoad::checkifGame(void *handle)
{
	if (exec_function(handle, "createGame") != NULL) {
		return true;
	} else {
		return false;
	}
}
