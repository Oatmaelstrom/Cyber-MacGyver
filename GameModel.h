#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "Background.h"
#include "Scenery.h"
#include "Obstacles.h"
#include "Runner.h"

#include "mainwindow.h"

#include "GameObject.h"

#include <QDebug>

using namespace std;

class MainWindow;

class GameModel
{
    //Renndering paramiters.
    int b_s_speed;
    int s_speed;

    //All game objects i.e. backgrond, obstacles, runner...
    vector<GameObject*> objs;

    //MainWindow paramiters
    QRect *screen;
    //This is used for window resising
    QRect* window;

public:
    GameModel(MainWindow *main)
    {
        screen = new QRect(main->geometry());
        b_s_speed = 2;
        s_speed = 20;
    }

    void Load();

    void Save();

    void print();

    vector<GameObject*> getObjects() {return objs;}

    //does the math for window resize
    void ReSize();
    int getH() {return  screen->height();}
    int getW() {return  screen->width();}

    void setScreen(QRect * par)
    {   window = screen;
        screen = par;
    }
    QRect* getScreen() { return screen;}

    int getBBS() {return  b_s_speed;}
    int getSS() {return s_speed;}

    bool Collision(bool jump, bool slide);



};



#endif // GAMEMODEL_H
