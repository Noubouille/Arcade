/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include <sys/ioctl.h>

Ncurses::Ncurses()
{
    _input = (char *)malloc(32);

    getmaxyx(window, _win_y, _win_x);
    printf ("lines x %d\n", _win_x);
    printf ("columns y %d\n",_win_y);

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
    this->_bgSize = std::make_pair((strlen(buffer) / lines) - 6, lines - 1);

    wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);
}

Ncurses::~Ncurses()
{
    
}

void Ncurses::startWindow()
{
    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(10);
}

void Ncurses::drawMenu()
{
    wborder(window, 0, 0, 0, 0, 0, 0, 0, 0);

    WINDOW *win = newwin(4, 15, 1, 1);

    mvprintw(5, 4, "Username : ");
    mvprintw(5, 15, _input.c_str());

    box(win, 0, 0);
    wrefresh(win);

    selectedGame(_pacman_selected, _nibbler_selected);

    mvprintw(3, 4, "ARCADE");

    mvprintw(8, 3, "Nibbler");
    printw("\n");


    mvprintw(10, 3, "Pacman");
    printw("\n");

    mvprintw(14, 3, "[F1] next graphical library");
    mvprintw(16, 3, "[F2] previous graphical library");
    mvprintw(18, 3, "[F3] Switch between games");

    mvprintw(22, 3, "Current library is Ncurses");

    refresh();
}

MonEnum Ncurses::getEvent()
{
    int ch = getch();
    
    mvprintw(8, 2, "-");

    switch(ch)
    {
    case KEY_UP:
    _gameName = "NIBBLER";
    _nibbler_selected = true;
    _pacman_selected = false;
        return MonEnum::UP_ARROW;
        break;
    case KEY_DOWN:
        _gameName = "PACMAN";
        _pacman_selected = true;
        _nibbler_selected = false;
        return MonEnum::DOWN_ARROW;
        break;
    case KEY_LEFT:
        return MonEnum::LEFT_ARROW;
        break;
    case KEY_RIGHT:
        return MonEnum::RIGHT_ARROW;
        break;
    case 10:
        _state_ncurses_menu = false;
        return MonEnum::ENTER;
        break;
    case KEY_BACKSPACE:
        _input = _input.substr(0, _input.size()-1);
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
    if (_state_ncurses_menu == true) {
        _input.append("a");
    }
        return MonEnum::A_KEY;
        break;
    case 'b':
        if (_state_ncurses_menu == true) {
        _input.append("b");
    }
        return MonEnum::B_KEY;
        break;
    case 'c':
        if (_state_ncurses_menu == true) {
        _input.append("c");
    }
        return MonEnum::C_KEY;
        break;
    case 'd':
        if (_state_ncurses_menu == true) {
        _input.append("d");
    }
        return MonEnum::D_KEY;
        break;
    case 'e':
        if (_state_ncurses_menu == true) {
        _input.append("e");
    }
        return MonEnum::E_KEY;
        break;
    case 'f':
        if (_state_ncurses_menu == true) {
        _input.append("f");
    }
        return MonEnum::F_KEY;
        break;
    case 'g':
        if (_state_ncurses_menu == true) {
        _input.append("g");
    }
        return MonEnum::G_KEY;
        break;
    case 'h':
        if (_state_ncurses_menu == true) {
        _input.append("h");
    }
        return MonEnum::H_KEY;
        break;
    case 'i':
        if (_state_ncurses_menu == true) {
        _input.append("i");
    }
        return MonEnum::I_KEY;
        break;
    case 'j':
        if (_state_ncurses_menu == true) {
        _input.append("j");
    }
        return MonEnum::J_KEY;
        break;
    case 'k':
        if (_state_ncurses_menu == true) {
        _input.append("k");
    }
        return MonEnum::K_KEY;
        break;
    case 'l':
        if (_state_ncurses_menu == true) {
        _input.append("l");
    }
        return MonEnum::L_KEY;
        break;
    case 'm':
        if (_state_ncurses_menu == true) {
        _input.append("m");
    }
        return MonEnum::M_KEY;
        break;
    case 'n':
        if (_state_ncurses_menu == true) {
        _input.append("n");
    }
        return MonEnum::N_KEY;
        break;
    case 'o':
        if (_state_ncurses_menu == true) {
        _input.append("o");
    }
        return MonEnum::O_KEY;
        break;
    case 'p':
        if (_state_ncurses_menu == true) {
        _input.append("p");
    }
        return MonEnum::P_KEY;
        break;
    case 'q':
        if (_state_ncurses_menu == true) {
        _input.append("q");
    }
        return MonEnum::Q_KEY;
        break;
    case 'r':
        if (_state_ncurses_menu == true) {
        _input.append("r");
    }
        return MonEnum::R_KEY;
        break;
    case 's':
        if (_state_ncurses_menu == true) {
        _input.append("s");
    }
        return MonEnum::S_KEY;
        break;
    case 't':
        if (_state_ncurses_menu == true) {
        _input.append("t");
    }
        return MonEnum::T_KEY;
        break;
    case 'u':
        if (_state_ncurses_menu == true) {
        _input.append("u");
    }
        return MonEnum::U_KEY;
        break;
    case 'v':
        if (_state_ncurses_menu == true) {
        _input.append("v");
    }
        return MonEnum::V_KEY;
        break;
    case 'w':
        if (_state_ncurses_menu == true) {
        _input.append("w");
    }
        return MonEnum::W_KEY;
        break;
    case 'x':
    if (_state_ncurses_menu == true) {
        _input.append("x");
    }
        return MonEnum::X_KEY;
        break;
    case 'y':
        if (_state_ncurses_menu == true) {
        _input.append("y");
    }
        return MonEnum::Y_KEY;
        break;
    case 'z':
        if (_state_ncurses_menu == true) {
        _input.append("z");
    }
        return MonEnum::Z_KEY;
        break;
    default:
        return MonEnum::NO_INPUT;

    }
    return MonEnum::NO_INPUT;
}

void Ncurses::selectedGame(bool pacman_selected, bool nibbler_selected)
{

    if (pacman_selected == true)
    {
        mvprintw(8, 2, " ");
        mvprintw(10, 2, "-");
    }

    if (nibbler_selected == true)
    {
        mvprintw(10, 2, " ");
        mvprintw(8, 2, "-");
    }
}

void Ncurses::utilityGame()
{

}

void Ncurses::getMusic(const std::string &music)
{
    auto tmp = music;
}

void Ncurses::reset()
{
    _state_ncurses_menu = true;
}


std::string Ncurses::getNameGame()
{
    return _gameName;
}

std::string Ncurses::getUsername()
{
    return _input;
}

void Ncurses::drawBackground(const std::string &Background)
{
    std::string tmp = Background;
    for (int y = 0, x = 0; _tab[y]; y++)
    {
        mvprintw(y, x, _tab[y]);
    }
}


void Ncurses::destroyWindow()
{
    endwin();
}


void Ncurses::clearWindow()
{
    erase();
}

void Ncurses::updateWindow()
{
    refresh();
    usleep(50000);
}

void Ncurses::drawSprite(Pixel sprite)
{
    auto it = sprite;
        mvprintw(it.y, it.x, "o");
}

void Ncurses::drawSprites(std::vector<Pixel> sprites)
{
    for (auto it = std::next(sprites.begin()); it != sprites.end(); it++) {
        mvprintw(it->y, it->x, "o");
    }
}


void Ncurses::drawMain(std::vector<Pixel> snake)
{
    for (auto it = std::next(snake.begin()); it != snake.end(); it++) {
        mvprintw(it->y, it->x, it->pathSprite.c_str());
    }
}

bool Ncurses::getUsernameloop()
{
    return true;
}

void Ncurses::drawPause(const std::string &Background)
{
    if (Background.empty()) {
        return;
    }
}


std::pair<int, int> Ncurses::sendBgSize()
{
    return _bgSize;
}

std::string Ncurses::getLibName()
{
    return "NCURSES";
}

void Ncurses::putText(const Text &text)
{
    int tmp_y = text.y;
    int tmp_x = text.x;
    getmaxyx(window, _win_y, _win_x);
    mvprintw(tmp_y, tmp_x, text.text.c_str());
}

extern "C" IGraphic *createLibrary()
{
	return new Ncurses();
}