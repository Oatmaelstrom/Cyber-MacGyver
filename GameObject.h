#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameModel.h"

class GameObject
{

protected:
    int x;
    int y;
    int w;
    int h;
    QString image;

    int extra;
    int pos;
    bool isShown;
    bool isActive;
public:

    GameObject(QRect *par, int ex, int num)
    {
        pos = num;
        extra = ex;
        x = par->x();
        y = par->y();
        w = par->width();
        h = par->height();
        isShown = false;
    }

    QRect format()
    {
       return  QRect(x,y,w,h);
    }

    virtual void size() = 0;

    virtual void Update() = 0;

    void setImage(QString pic_url) {image = pic_url;}

    bool getVisible() {return isShown;}

    QString getImage() {return image;}

    void setVisible(bool maybe) { isShown = maybe;}

    virtual void setSize(QRect *new_, QRect *old) = 0;

    int get_x() {return x;}
    int get_y() {return y;}
    int get_h() {return h;}
    int get_w() {return w;}

    void set_x(int new_x) {x = new_x;}
    void set_y(int new_y) {y = new_y;}

    int getEx() {return extra;}

    bool getActive() {return isActive;}




};

#endif // GAMEOBJECT_H
