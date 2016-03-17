#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameModel.h"
#include "mainwindow.h"

class Background
{

    QLabel *display;
    QString image;


public:

    Background(MainWindow *parent, QString picture, QRect rect)
    {
        image = picture;
        display = new QLabel(parent);
        display->setScaledContents(true);
        display->setGeometry(rect);
        display->setPixmap(QPixmap(image));
    }

    QLabel* getLabel() {return display;}

};

//class Backdrop : Background
//{
//    Q_OBJECT

//    QLabel * display;
//    QString image;
//    MainWindow * m;

//public:

//    Backdrop(MainWindow * parent, QString picture, QRect rect): Background()
//    {
//        m->parent();

//        display->setPixmap(QPixmap(image);
//    }



//};

#endif // BACKGROUND_H
