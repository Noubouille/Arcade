/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** test
*/

class Igraphic
{
    public:

        virtual int startWindow() = 0;

        virtual int getEvent() = 0;
        virtual int drawMenu() = 0;
        virtual int drawGame() = 0;

        //etc
};

class Ncurses : public Igraphic
{
    public:
        Ncurses()
        {
            //init ncurses
        }

        ~Ncurses()
        {
        }

        int startWindow()
        {
            //start window en ncurses
        }

        int getEvent()
        {
            //get event en ncurses
        }

        int drawMenu()
        {
            //draw menu en ncurses
        }

        int drawGame()
        {
            //draw game en ncurses
        }

        //etc
};

class Sfml : public Igraphic
{
    public:
        Sfml()
        {
            //init sfml
        }

        ~Sfml()
        {
        }

        int startWindow()
        {
            //start window en sfml
        }

        int getEvent()
        {
            //get event en sfml
        }

        int drawMenu()
        {
            //draw menu en sfml
        }

        int drawGame()
        {
            //draw game en sfml
        }

        //etc
};

class Core
{
    Igraphic *graphic;
    Igame *game;

    Core()
    {
        graphic = new Ncurses(); // start en ncurses par exemple
        std::vector<std::string> _map; //pour la map mieux vaut faire simple et faire un tableau de char que tu bougera

    }

    void startGame(newgame)
    {
        if (game){
            delete (game);
        }

        if (newgame == pacman){
            game = new Pacman(); // start pacman
        } else {
            game = new SNake(); // start pacman
        }
    }

    void changeLib(library)
    {
        //jte laisse tema pour la lib, regarde dlclose dlsym dlopen de la lib dlfcn.h

        delete (graphic);
        graphic = new Sfml();
    }

    void loop()
    {
        for (;;){

            if (state === menu){
                graphic->drawMenu()
            } else {
                if (game){
                    graphic->drawGame()
                }
            }

            if (graphic->getEvent()){
                // manage event et update _map si besoin
            }

            game->update();

        }
    }
}