/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    _gameName = "NIBBLER";

    struct stat buf;
    stat("map.txt", &buf);

    char *buffer = (char *)malloc(sizeof(char) * buf.st_size);

    std::ifstream myfile;
    myfile.open("./map.txt");
    myfile.read(buffer,buf.st_size);
    myfile.close();

    int lines = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '\n') {
            lines++;
        }
    }

    char **tab = (char **)malloc(sizeof(char *) * lines + 1);

    int thei = 0;

    for (; thei <= lines; thei++)
    {
        tab[thei] = (char *)malloc(sizeof(char) * (strlen(buffer) / lines) + 1);
    }
    tab[thei] = NULL;

    for (int i = 0, x = 0, y = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '\n')
        {
            tab[y][x] = '\0';
            i++;
            y++;
            x = 0;
        }
        tab[y][x] = buffer[i];
        x++;
    }

    _tab = tab;

    this->_bgSize = std::make_pair(lines, strlen(buffer) / lines);

    wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);

    //this->_bgSize = std::make_pair(99, 34);
}

Ncurses::~Ncurses()
{
    
}

void Ncurses::startWindow()
{
    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    noecho();
    timeout(10);
}

void Ncurses::drawMenu()
{
    wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);
    int start_y, start_x;
    start_y = start_x = 10;

    WINDOW *win = newwin(4, 15, 1, 1);
    refresh();

    box(win, 0, 0);
    wrefresh(win);

    mvprintw(3, 4, "ARCADE");

    mvprintw(8, 3, "Nibbler");
    printw("\n");


    mvprintw(10, 3, "Pacman");
    printw("\n");

    mvprintw(14, 3, "[F1] next graphical library");
    mvprintw(16, 3, "[F2] previous graphical library");

    refresh();
}

MonEnum Ncurses::getEvent()
{
    int ch = getch();

    switch(ch)
    {
    case KEY_UP:
        mvprintw(10, 2, " ");
        mvprintw(8, 2, "-");
        return MonEnum::UP_ARROW;
        break;
    case KEY_DOWN:   
        mvprintw(8, 2, " ");
        mvprintw(10, 2, "-");
        return MonEnum::DOWN_ARROW;
        break;
    case 10:
        return MonEnum::ENTER;
        break;
    case KEY_BACKSPACE:
        return MonEnum::BACKSPACE;
        break;
    case 27:
        return MonEnum::ESCAPE;
        break;
    case ' ':
        return MonEnum::SPACE;
        break;

    case KEY_F(1):
        return MonEnum::F1;
        break;
    case KEY_F(2):
        return MonEnum::F2;
        break;
    case KEY_F(3):
        return MonEnum::F3;
        break;
    case KEY_F(4):
        return MonEnum::F4;
        break;
    case KEY_F(5):
        return MonEnum::F5;
        break;
    case KEY_F(6):
        return MonEnum::F6;
        break;
    case KEY_F(7):
        return MonEnum::F7;
        break;
    case KEY_F(8):
        return MonEnum::F8;
        break;
    case KEY_F(9):
        return MonEnum::F9;
        break;
    case KEY_F(10):
        return MonEnum::F10;
        break;
    case KEY_F(11):
        return MonEnum::F11;
        break;
    case KEY_F(12):
        return MonEnum::F12;
        break;
    case 'a':
        return MonEnum::A_KEY;
        break;
    case 'b':
        return MonEnum::B_KEY;
        break;
    case 'c':
        return MonEnum::C_KEY;
        break;
    case 'd':
        return MonEnum::D_KEY;
        break;
    case 'e':
        return MonEnum::E_KEY;
        break;
    case 'f':
        return MonEnum::F_KEY;
        break;
    case 'g':
        return MonEnum::G_KEY;
        break;
    case 'h':
        return MonEnum::H_KEY;
        break;
    case 'i':
        return MonEnum::I_KEY;
        break;
    case 'j':
        return MonEnum::J_KEY;
        break;
    case 'k':
        return MonEnum::K_KEY;
        break;
    case 'l':
        return MonEnum::L_KEY;
        break;
    case 'm':
        return MonEnum::M_KEY;
        break;
    case 'n':
        return MonEnum::N_KEY;
        break;
    case 'o':
        return MonEnum::O_KEY;
        break;
    case 'p':
        return MonEnum::P_KEY;
        break;
    case 'q':
        return MonEnum::Q_KEY;
        break;
    case 'r':
        return MonEnum::R_KEY;
        break;
    case 's':
        return MonEnum::S_KEY;
        break;
    case 't':
        return MonEnum::T_KEY;
        break;
    case 'u':
        return MonEnum::U_KEY;
        break;
    case 'v':
        return MonEnum::V_KEY;
        break;
    case 'w':
        return MonEnum::W_KEY;
        break;
    case 'x':
        return MonEnum::X_KEY;
        break;
    case 'y':
        return MonEnum::Y_KEY;
        break;
    case 'z':
        return MonEnum::Z_KEY;
        break;
    default:    
        return MonEnum::NO_INPUT;

    }
}

void Ncurses::drawGame()
{

}

std::string Ncurses::getNameGame()
{
    return _gameName;
}

void Ncurses::drawBackground(const std::string &Background)
{

    for (int i = 0, y = 0, x = 0; _tab[y]; y++)
    {
        mvprintw(y, x, _tab[y]);

    }
    // map et bordure
}


void Ncurses::destroyWindow()
{
    endwin();
}


void Ncurses::clearWindow()
{

}

void Ncurses::updateWindow()
{
    refresh();
    usleep(40000);
}

void Ncurses::drawSprite(std::vector<Pixel> sprite)
{
    // le fruit
}

void Ncurses::drawMain(std::vector<Pixel> snake)
{
    for (auto it = std::next(snake.begin()); it != snake.end(); it++) {
        // printf("x: %d", it->x);
        // printf("y: %d", it->y);
        mvprintw(it->x, it->y, ">");
        //refresh();
    }
    // le snake
}

std::pair<int, int> Ncurses::sendBgSize()
{
    return _bgSize;
    // taille de la fenetre de jeu
}

void Ncurses::putText(const Text &text)
{

}


extern "C" IGraphic *createLibrary()
{
    std::cout << "CREATE LIBRARY NCURSES" << std::endl;
	return new Ncurses();
}