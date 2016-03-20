#ifndef RUNNER_H
#define RUNNER_H

#include "GameModel.h"
#include "mainwindow.h"
#include <QMovie>

class Runner : public GameObject
{

public:
     Runner(QRect *par, int ex, int num) : GameObject(par, ex, num)
     {
         x += par->width();
         y += par->height();

         image = ":/stuff/running.gif";

         this->size();
     }

     void size()
     {
         x = x/6;
         y = h / 6 *4;
         w = w /10;
         h= h/6;
     }

    void Update(){}

    void setSize(QRect *new_, QRect * old)
    {
        x = new_->width();
        y = new_->height();
        w = new_->width();
        h = new_->height();

        size();
    }


};


#endif // RUNNER_H
