#include "GameModel.h"
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <iostream>

using namespace std;

void GameModel::Load()
{
    //background and wall generation
    objs.push_back(new Background(screen, b_s_speed, 0));
    objs.push_back(new Background(screen, 0, 1));
    objs.push_back(new Backdrop(screen, s_speed, 0));
    objs.push_back(new Backdrop(screen, 0, 1));

    //lowob generation aka just the ground
    for(auto i = 0; i < 14; ++i)
    {
       if(i%2 == 0)
       {
         objs.push_back(new lowob(screen, s_speed /2, i));
       }
       else
       {
         objs.push_back(new lowob(screen, 0, i));
       }
    }

//    //midob aka a crate that requires jumping.
//    for(auto i = 0; i < 14; ++i)
//    {
//       if(i%2 == 0)
//       {
//         objs.push_back(new midob(screen, s_speed /4, i));
//       }
//       else
//       {
//         objs.push_back(new midob(screen, 0, i));
//       }
//    }
//    objs.push_back(new cheatob(screen, 0, 5));
//    dynamic_cast<cheatob*>(objs.back())->setActive(true);

    objs.push_back(new midob(screen, 0, 7));
    dynamic_cast<midob*>(objs.back())->setActive(true);
    objs.push_back(new midob(screen, 0, 14));
    dynamic_cast<midob*>(objs.back())->setActive(true);

    //Runner generation
    objs.push_back(new Runner(screen, 0, 0));


//    running = new QMovie(":/stuff/running.gif");
//    QPixmap slide1(":/Game pics/Runner/slide1.png");
//    QPixmap slide2(":/Game pics/Runner/slide2.png");
//    QPixmap slide3(":/Game pics/Runner/slide3.png");
//    QPixmap slide4(":/Game pics/Runner/slide4.png");

//    //slideMovie = new QMovie("://sliding.gif");
//    dude->setScaledContents(true);
//    dude->setMovie(running);


    //qDebug("clicked");
//    pos = dude->y();
}

void GameModel::print()
{
    for(auto i = 0; i < objs.size(); ++i)
    {
        //sets only the non obstical objects to viewed.
        if (!dynamic_cast<midob*>(objs.at(i)) != 0 )
        {
             objs.at(i)->setVisible(true);
        }
    }
}



//void GameModel::reposition(int new_x, int new_y)
//{
//    for(auto i = 0; i < objs.size(); ++i)
//    {
//        objs.at(i)->setSize(screen);
//    }

//    if (main->sliding)
//    {
//    dude->setMovie(running);
//    dude->move(dude->x(), 720);
//    }

//}

void GameModel::ReSize()
{
    for(auto i = 0; i < objs.size(); ++i)
    {
        objs.at(i)->setSize(screen, window);
    }
}

bool GameModel::Collision(bool jump, bool slide, int height)
{

    for (int i = 0; i < objs.size(); ++i)
    {
        if(dynamic_cast<Obstacles*>(objs.at(i)) != 0 && objs.at(i)->getActive())
        {
            if (objs.back()->get_x() >= objs.at(i)->get_x() + objs.at(i)->get_w())
            {
                objs.at(i)->setActive(false);
            }

            else if (objs.back()->get_x() + objs.back()->get_w() >= objs.at(i)->get_x() &&
              objs.back()->get_y() + objs.back()->get_h() >= objs.at(i)->get_y())
            {
                return true;
            }
        }
    }
        return false;
}

void GameModel::Restart()
{
    for(int i = 0; i < objs.size(); ++i)
    {
        delete objs.at(i);
    }

}
