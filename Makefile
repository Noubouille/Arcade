##
## EPITECH PROJECT, 2018
## ArcadeApplication
## File description:
## Makefile
##

CXX		=	g++ -g3

INC		=	-I src/

CXXFLAGS	+=	-Wall -Wextra -pedantic -std=c++17 -fPIC $(INC)

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

# NAME_SDL	=	lib/lib_arcade_sdl.so

# SRC_SDL		=	$(SRC_DIR)Libraries/SDL.cpp

# OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

# LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image

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

core:			$(NAME)

games:			$(NAME_PACMAN)  $(NAME_NIBBLER)

graphicals:		$(NAME_SFML) $(NAME_SDL) $(NAME_NCURSES) $(NAME_ALLEGRO)

$(NAME_SFML):		$(OBJ_SFML)
			$(CXX) $(OBJ_SFML) -o $(NAME_SFML) $(LDFLAGS_SFML)
	 		# $(RM) $(OBJ_SFML)

# $(NAME_SDL):		$(OBJ_SDL)
# 			$(CXX) $(OBJ_SDL) -o $(NAME_SDL) $(LDFLAGS_SDL)

$(NAME_NCURSES):		$(OBJ_NCURSES)
			$(CXX) $(OBJ_NCURSES) -o $(NAME_NCURSES) $(LDFLAGS_NCURSES)
	 		# $(RM) $(OBJ_NCURSES)

# $(NAME_ALLEGRO):	$(OBJ_ALLEGRO)
# 			$(CXX) $(OBJ_ALLEGRO) -o $(NAME_ALLEGRO) $(LDFLAGS_ALLEGRO)

# $(NAME_PACMAN):		$(OBJ_PACMAN)
# 			$(CXX) $(OBJ_PACMAN) -o $(NAME_PACMAN) $(LDFLAGS_PACMAN)

$(NAME_NIBBLER):		$(OBJ_NIBBLER)
			$(CXX) $(OBJ_NIBBLER) -o $(NAME_NIBBLER) $(LDFLAGS_NIBBLER)
	 		$(RM) $(OBJ_NIBBLER)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS) $(FLGS)
			$(RM) $(OBJ)

clean:
			$(RM) $(OBJ_SFML) $(OBJ_SDL) $(OBJ_CACA) $(OBJ_PACMAN) $(OBJ_NIBBLER) $(OBJ) $(OBJ_ALLEGRO)

fclean:			clean
			$(RM) $(NAME_SFML) $(NAME_SDL) $(NAME_CACA) $(NAME_PACMAN) $(NAME_NIBBLER) $(NAME) $(NAME_ALLEGRO)

re:			fclean all

.PHONY:			clean fclean re all
