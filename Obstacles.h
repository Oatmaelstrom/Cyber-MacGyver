#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "GameModel.h"

class Obstacles
{

    QLabel * display;
    QString image;


public:

    Obstacles(MainWindow *parent, QString picture, QRect rect)
    {
        image = picture;
        display = new QLabel(parent);
        display->setScaledContents(true);
        display->setGeometry(rect);
        display->setPixmap(QPixmap(image));
    }

    QLabel *getLabel() {return display;}
};

#endif // OBSTACLES_H
