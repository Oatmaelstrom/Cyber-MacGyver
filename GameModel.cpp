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

bool GameModel::Collision()
{
    for (auto i = 0; i < objs.size(); ++i)
    {

        if (dynamic_cast<Runner*>(objs.at(i)) != 0)
        {
            for (int j = 0; j < objs.size(); j++) {

                if (dynamic_cast<Obstacles*>(objs.at(j)) != 0) {

                    if (dynamic_cast<Obstacles*>(objs.at(j))->getActive()) {
                        /*double guyRadius = guy->get_h() / 2;
                        double obRadius = sqrt((obstacle->get_w() * obstacle->get_w()) + (obstacle->get_h() * obstacle->get_h())) / 2;
                        double minimumDistance = guyRadius + obRadius;
                        double actualDistance = sqrt((((obstacle->get_y() + (obstacle->get_h()/2)) - (guy->get_y() + (guy->get_h()/2)))^2) +
                                                (((obstacle->get_x() + (obstacle->get_w()/2)) - (guy->get_x() + (guy->get_w()/2)))^2));*/ // CENTER of runner distance
                                                                                                                                      // from CENTER of obstacle
//                        if (actualDistance < minimumDistance) {
//                            cout << "collision";
//                        }

                        if(objs.at(i)->get_x() + objs.at(i)->get_w() >= objs.at(j)->get_x())
                        {
                            return true;
                        }
                    }
                }
            }
        }

    }

}


