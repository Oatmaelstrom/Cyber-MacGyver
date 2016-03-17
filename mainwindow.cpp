#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameModel.h"

#include <QLabel>
#include <QMovie>
#include <QPixmap>

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    running = new QMovie(":/stuff/running.gif");
    mover = new GameModel(this);
    mover->Load();
    mover->print();

    pos = 720;

    timer = new QTimer(this);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHit()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}




//void MainWindow::on_playButton_clicked()
//{

//    auto label_width = 100, label_height = 100;

//    auto label_top = (720);
//    auto label_left = (this->width()/2);


//    // Create label
//    dude = new QLabel(this);

//    //create animation
//    dude->setGeometry(QRect(label_left, label_top, label_width, label_height));
//    running = new QMovie(":/background_scroll_speedpics/Runner/running.gif");
//    QPixmap slide1(":/background_scroll_speedpics/Runner/slide1.png");
//    QPixmap slide2(":/background_scroll_speedpics/Runner/slide2.png");
//    QPixmap slide3(":/background_scroll_speedpics/Runner/slide3.png");
//    QPixmap slide4(":/background_scroll_speedpics/Runner/slide4.png");

//    //slideMovie = new QMovie(":/background_scroll_speedpics/Runner/sliding.gif");
//    dude->setScaledContents(true);
//    dude->setMovie(running);
//    dude->show();
//    running->start();
//    qDebug("clicked");
//    pos = dude->y();
//}

void MainWindow::on_jumpButton_clicked()
{
    /*auto label_width = 100, label_height = 100;
    auto label_top = (80);
    auto label_left = (80);

    QPixmap jumper(":/background_scroll_speedpics/Runner/slide1.png");
    dude->setScaledContents(true);
    dude->setPixmap(jumper);
    //dude->setGeometry(QRect(label_left, label_top, label_width, label_height));
    dude->move(80, 50);
    dude->show();
    */
    if (!sliding) {
        jumping = true;
    }
}



void MainWindow::timerHit() {
    mover->move();



    if (jumping) {

        mover->dude->move(mover->dude->x(), mover->dude->y() - jumpSpeed);
        jumpSpeed -= gravity;

        if (mover->dude->y() >= pos) {
            jumping = false;
            jumpSpeed = 14;
            mover->dude->move(mover->dude->x(), pos);
        }
    }
    if (sliding) {

        if (slideLength == 20) {
            QPixmap slide1(":/stuff/slide1.png");
            mover->dude->setPixmap(slide1);
        } else if (slideLength == 19){
            QPixmap slide2(":/stuff/slide2.png");
            mover->dude->setPixmap(slide2);
        } else if (slideLength == 18) {
            QPixmap slide3(":/stuff/slide3.png");
            mover->dude->setPixmap(slide3);
        } else if (slideLength <= 17 && slideLength >= 4) {
            QPixmap slide4(":/stuff/slide4.png");
            mover->dude->setPixmap(slide4);
        } else if (slideLength == 3) {
            QPixmap slide3(":/stuff/slide3.png");
            mover->dude->setPixmap(slide3);
        } else if (slideLength == 2) {
            QPixmap slide2(":/stuff/slide2.png");
            mover->dude->setPixmap(slide2);
        } else if (slideLength == 1) {
            QPixmap slide1(":/stuff/slide1.png");
            mover->dude->setPixmap(slide1);
        } else if (slideLength == 0) {
            sliding = false;
            slideLength = 21;
//            if (!sliding)
//            {
//            mover->dude->setMovie(running);
//            mover->dude->move(mover->dude->x(), 720);
//            }
        }
        slideLength --;
    }
}

void MainWindow::on_slideBtn_clicked()
{
    if(!jumping) {
        sliding = true;
    }
}

