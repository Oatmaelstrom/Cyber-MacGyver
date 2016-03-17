#ifndef SCENERY_H
#define SCENERY_H

#include "GameModel.h"

class Scenery : public QLabel
{
    Q_OBJECT

    QLabel * display;
    QString image;


public:

    Scenery(MainWindow * parent, QString picture, QRect rect): QLabel(parent)
    {
        image = picture;
        display = new QLabel(parent);
        display->setScaledContents(true);
        display->setGeometry(rect);
        display->setPixmap(QPixmap(image));
    }

};


#endif // SCENERY_H
