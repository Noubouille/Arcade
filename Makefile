##
## EPITECH PROJECT, 2018
## ArcadeApplication
## File description:
## Makefile
##

CXX		=	g++ -g3

INC		=	-I src/

CXXFLAGS	+=	-Wall -Wextra -pedantic -std=c++17 -fPIC $(shell sdl2-config --cflags --libs) $(INC)

FLGS		=	-std=c++17 -lstdc++fs

LDFLAGS		=	-ldl

## arcade

NAME		=	arcade

SRC_DIR		=	src/

SRC		=	$(SRC_DIR)main.cpp			\
			$(SRC_DIR)Core.cpp		\
			$(SRC_DIR)LibLoad.cpp		\
			# $(SRC_DIR)Core/HighScoreManager.cpp	\
			# $(SRC_DIR)LibraryLoader.cpp

OBJ		=	$(SRC:.cpp=.o)

## sfml :

NAME_SFML	=	lib/arcade_sfml.so

SRC_SFML	=	$(SRC_DIR)Libraries/SFML.cpp \

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

LDFLAGS_SFML	=	-shared -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

## plugin sdl

NAME_SDL	=	lib/arcade_sdl.so

SRC_SDL		=	$(SRC_DIR)Libraries/SDL.cpp

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image
# LDFLAGS_SDL	=	-shared -fPIC $(shell sdl2-config --cflags --libs) -lSDL2_ttf

## ncurses :

NAME_NCURSES	=	lib/arcade_ncurses.so

SRC_NCURSES	=	$(SRC_DIR)Libraries/Ncurses.cpp	\

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

LDFLAGS_NCURSES	=	-shared -fPIC -lncurses

## pacman

# NAME_PACMAN	=	games/lib_arcade_pacman.so

# SRC_PACMAN	=	$(SRC_DIR)Games/Pacman/Pacman.cpp   \
# 			$(SRC_DIR)Games/Pacman/AIGhost.cpp

# OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

# LDFLAGS_PACMAN	=	-shared -fPIC

## nibbler

NAME_NIBBLER	=	lib/arcade_nibbler.so

SRC_NIBBLER	=	$(SRC_DIR)Games/Nibbler.cpp

OBJ_NIBBLER	=	$(SRC_NIBBLER:.cpp=.o)

LDFLAGS_NIBBLER	=	-shared -fPIC

all:			core games graphicals

core:			$(NAME) ## Compile core

games:			$(NAME_PACMAN)  $(NAME_NIBBLER) ## Compile games

graphicals:		$(NAME_SFML) $(NAME_SDL) $(NAME_NCURSES) $(NAME_ALLEGRO) ## Compile graphical libraries

$(NAME_SFML):		$(OBJ_SFML)
			$(CXX) $(OBJ_SFML) -o $(NAME_SFML) $(LDFLAGS_SFML)
	 		# $(RM) $(OBJ_SFML)

$(NAME_SDL):		$(OBJ_SDL)
			$(CXX) $(OBJ_SDL) -o $(NAME_SDL) $(LDFLAGS_SDL)

$(NAME_NCURSES):		$(OBJ_NCURSES)
			$(CXX) $(OBJ_NCURSES) -o $(NAME_NCURSES) $(LDFLAGS_NCURSES)
	 		# $(RM) $(OBJ_NCURSES)

# $(NAME_PACMAN):		$(OBJ_PACMAN)
# 			$(CXX) $(OBJ_PACMAN) -o $(NAME_PACMAN) $(LDFLAGS_PACMAN)

$(NAME_NIBBLER):		$(OBJ_NIBBLER)
			$(CXX) $(OBJ_NIBBLER) -o $(NAME_NIBBLER) $(LDFLAGS_NIBBLER)
	 		# $(RM) $(OBJ_NIBBLER)

$(NAME):		$(OBJ) ## Compile program
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS) $(FLGS)
			$(RM) $(OBJ)

clean: ## Clean directories
			$(RM) $(OBJ_SFML) $(OBJ_SDL) $(OBJ_CACA) $(OBJ_PACMAN) $(OBJ_NIBBLER) $(OBJ) $(OBJ_ALLEGRO)

fclean:			clean ## Clean directories & binary(s)
			$(RM) $(NAME_SFML) $(NAME_SDL) $(NAME_CACA) $(NAME_PACMAN) $(NAME_NIBBLER) $(NAME) $(NAME_ALLEGRO) $(NAME_SOLAR)
re:			fclean all ## Recompile program

.PHONY:			clean fclean re all

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
