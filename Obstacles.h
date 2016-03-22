#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "GameModel.h"
#include "mainwindow.h"

class Obstacles  : public GameObject
{


public:

    Obstacles(QRect *par, int ex, int num) : GameObject(par , ex, num)
    {
        isActive = false;
    }

    void Update(){}

    void setSize(QRect *new_, QRect *old){}
    void size(){}
    void setActive(bool state) { isActive = state; }
};

class highob :public Obstacles
{

public:

     highob(QRect *par, int ex, int num) : Obstacles(par, ex, num)
    {
//        x
//        y
//        w
//        h
            this->size();
    }

    void size(){}

};

class midob :public Obstacles
{


public:

     midob(QRect *par, int ex, int num) : Obstacles(par, ex, num)
    {
         x += par->width();
         y += par->height();
         w += ex;
         image = ":/stuff/crate.png";
         this->size();
    }

     void size()
     {
         x = x / 7*pos;
         y = h / 6 *4;
         w = w /7;
         h = h/6;
     }
};

class lowob :public Obstacles
{


public:

     lowob(QRect *par, int ex, int num) : Obstacles(par, ex, num)
    {
        x += par->width();
        y += par->height();
        w += ex;
        image = ":/stuff/ground.png";
        this->size();
    }

    void size()
    {
       x = x / 7*pos;
       y = h / 6 *5;
       w = w /7;
       h = h/6;
    }

    void setSize(QRect *new_, QRect *old)
    {
        x = new_->width();
        y = new_->height();
        w = new_->width() + extra;
        h = new_->height();

        size();
    }
};

#endif // OBSTACLES_H
