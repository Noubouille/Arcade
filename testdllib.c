/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** testdllib
*/
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
    void *handle;
    double (*cosine)(void);
    char *error;

   handle = dlopen("./lib/arcade_sfml.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

   dlerror();    /* Clear any existing error */

   *(void **) (&cosine) = dlsym(handle, "startWindow");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    (*cosine)();

   printf("%f\n", (*cosine)());
    dlclose(handle);
    exit(EXIT_SUCCESS);
}