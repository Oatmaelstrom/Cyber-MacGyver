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

    const int gravity = 2;
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

        jumpSpeed = 35;
        pos;
        slideLength = 20;
    }

    void format();

    void Update(QRect *par, int BSS, int SS);

    void ReSize();

    void jump();

    void slide();

    GameObject *getObj() { return obj; }

    bool Test(GameModel *stuff);

};


#endif // VIEW_H
