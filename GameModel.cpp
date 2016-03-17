#include "GameModel.h"
#include "mainwindow.h"
#include <QString>

#include <iostream>

using namespace std;

void GameModel::Load()
{
    background.push_back(Background(main, ":/stuff/background.png", QRect(main->x(), main->y(),main->width() + background_scroll_speed,main->height())));
    background.push_back(Background(main, ":/stuff/background.png", QRect(main->width(), main->y(),main->width(),main->height())));

    background.push_back(Background(main, ":/stuff/castle.png", QRect(main->x(), main->y(), main->width() + scroll_speed,main->height())));
    background.push_back(Background(main, ":/stuff/castle.png", QRect(main->width(), main->y(), main->width() ,main->height())));

    for(auto i = 0; i < 14; ++i)
    {
       obs.push_back( new Obstacles(main, ":/stuff/ground.png", QRect(main->width()/7 * i, 820  , main->width()/7, main->height()/4)));
    }

    auto label_width = 100, label_height = 100;

    auto label_top = (720);
    auto label_left = (main->width()/2);


    // Create label
    dude = new QLabel(main);

    //create animation
    dude->setGeometry(QRect(label_left, label_top, label_width, label_height));
    running = new QMovie(":/stuff/running.gif");
//    QPixmap slide1(":/Game pics/Runner/slide1.png");
//    QPixmap slide2(":/Game pics/Runner/slide2.png");
//    QPixmap slide3(":/Game pics/Runner/slide3.png");
//    QPixmap slide4(":/Game pics/Runner/slide4.png");

    //slideMovie = new QMovie("://sliding.gif");
    dude->setScaledContents(true);
    dude->setMovie(running);

    running->start();
    qDebug("clicked");
    pos = dude->y();
}

void GameModel::print()
{
    for(auto i = 0; i < background.size(); ++i)
    {

      background.at(i).getLabel()->show();
    }
    for(auto i = 0; i < obs.size(); ++i)
    {
       obs.at(i)->getLabel()->show();
    }
    dude->show();
}

void GameModel::move()
{
    for(auto i = 0; i < 2; ++i)
    {

      background.at(i).getLabel()->move(background.at(i).getLabel()->x() - background_scroll_speed, background.at(i).getLabel()->y());
    }

    for(auto i = 2; i < background.size(); ++i)
    {
      //cout << "I am here 2 \n";
      background.at(i).getLabel()->move(background.at(i).getLabel()->x() - scroll_speed, background.at(i).getLabel()->y());
    }

    for(auto i = 0; i < obs.size(); ++i)
    {//cout << "I am here 3 \n";
       obs.at(i)->getLabel()->move(obs.at(i)->getLabel()->x() - scroll_speed, obs.at(i)->getLabel()->y());
    }


    for(auto i = 0; i < 2; ++i)
    {//cout << "I am here 3 \n";
        if(background.at(i).getLabel()->x() <= -main->width() + background_scroll_speed)
        {//cout << "I am here 4 \n";
            background.at(i).getLabel()->move(main->width(),main->y());
        }
    }

    for(auto i = 2; i < background.size(); ++i)
    {//cout << "I am here 5 \n";
      if(background.at(i).getLabel()->x() <= -main->width() + scroll_speed)
      {//cout << "I am here 6 \n";
          background.at(i).getLabel()->move(main->width(),main->y());
      }
    }

    for(auto i = 0; i < obs.size(); ++i)
    {//cout << "I am here 7 \n";
       if(obs.at(i)->getLabel()->x() <= -obs.at(i)->getLabel()->width() + scroll_speed)
       {//cout << "I am here 8 \n";
           obs.at(i)->getLabel()->move(main->width()/7 * 13, 820 );
       }
    }


    if (main->sliding)
    {
    dude->setMovie(running);
    dude->move(dude->x(), 720);
    }

}


