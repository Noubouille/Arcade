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
	// std::cout << "le libpath inside loadlib :" << librarypath.c_str() << std::endl;
    void *handle = dlopen(librarypath.c_str(), RTLD_NOW);
	if (handle == nullptr) {
		std::cerr << dlerror() << std::endl;
        std::cout << "une erreur est survenu" << std::endl;
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
	// std::cout << "exec_function fdp functionName.c_str() :" << functionName.c_str() << std::endl;
	// std::cout << "exec_function fdp handle :" << handle << std::endl;

	return dlsym(handle, functionName.c_str());
}