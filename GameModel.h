#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "Background.h"
#include "Scenery.h"
#include "Obstacles.h"
#include <QMovie>
#include <QDebug>


using namespace std;

class MainWindow;

class GameModel
{

    vector<Background> background;
    vector<Obstacles*> obs;
    //vector<Scenery> some;
    MainWindow *main;

public:
    GameModel(MainWindow *parent)
    {
        main = parent;
    }

    void Load();

    void Save();

    void print();

    void move();

    QLabel* dude;
    QMovie *running;
int pos;

};



#endif // GAMEMODEL_H
