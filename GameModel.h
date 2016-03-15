#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QMainWindow>
#include <iostream>
#include <string>

using namespace std;

namespace Ui{
class MainWindow;
}

class GameModel
{
    int x, y;
    string image;

    public:
    GameModel(int initX, int initY, string initImage): x(initX), y(initY), image(initImage)
    {}

    virtual void Running();

    virtual void Jump();

    virtual void Slide();

    virtual void Load();

    virtual void Save();

};

class Player : public GameModel
{

};
#endif // GAMEMODEL_H
