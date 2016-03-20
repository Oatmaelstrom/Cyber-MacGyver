#ifndef VIEW_H
#define VIEW_H

#include <QLabel>
#include <QMovie>
#include "GameModel.h" //May not need this.
#include "GameObject.h"

class MainWindow;

class View : public QLabel
{
    Q_OBJECT

    const int gravity = 1;
    int jumpSpeed;
    int pos;
    int slideLength;

    GameObject* obj;
    MainWindow *main;

public:
    explicit View(MainWindow *parent, GameObject *obj_type) : QLabel(parent)
    {
        obj = obj_type;
        main = parent;

        jumpSpeed = 18;
        pos;
        slideLength = 20;
    }

    void format();

    void Update(QRect *par, int BSS, int SS);

    void ReSize();

    void jump();

    void slide();

};


#endif // VIEW_H
