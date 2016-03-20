#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "mainwindow.h"
#include "GameModel.h"
#include "GameObject.h"


class Background : public GameObject
{

public:

    Background(QRect *par, int ex, int num) : GameObject(par, ex, num)
    {
        x += par->width();
        w += ex;
        image = ":/stuff/background.png";
        this->size();
    }

    void size()
    {
        x = x * pos;
    } 

    void setSize(QRect *new_, QRect* old )
    {
        x = new_->x() ;
        y = new_->y();
        w = new_->width() + extra;
        h = new_->height();

        size();
    }



    void Update(){}
};

class Backdrop : public Background
{

public:
    Backdrop(QRect *par, int ex, int num) : Background(par, ex, num)
    {
        image = ":/stuff/castle.png";
    }
};

#endif // BACKGROUND_H
