#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameModel.h"
#include "Highscores.h"

#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QLineEdit>
#include <QMovie>
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QString>
#include <QSizePolicy>
#include "View.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s = false;
    j = false;
    c = false;

    game = new GameModel(this);

    //Makes the model objects and
    //then the view objects with the
    //models logic.
    Load();

    //sets all the model objects to
    // "visible" as well as the show format
    //funciton for all the labels.
    game->print();
    Print();


    timer = new QTimer(this);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHit()));
    timer->start();

    scoresheet.loadHighScores();
    scorelabel = new QLabel(this);
    scorelabel->setStyleSheet("background-color: white");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Load()
{
    //Creates all the model objects
    game->Load();

    //Gets the now created model objects.
    vector<GameObject*> objs = game->getObjects();

    //Creates View objects "MainWindow labels with the GameObjects paramiters
    for(auto i = 0; i < objs.size(); ++i)
    {
        label = new View(this, objs.at(i));
        label->format();
    }

//I think we are going to need to delete all the objects in the new GameObject vector.
}

void MainWindow::Print()
{
    game->print();

    QObjectList objList = this->children();
    for(auto i = 0; i < objList.size(); i++)
    {
        if (dynamic_cast<View*>(objList.at(i)) != 0)
        {
            dynamic_cast<View*>(objList.at(i))->show();
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
//    if (width() > game->getW() || height() > game->getH())
//    {
//        QRect *temp = new QRect(ui->centralWidget->geometry());
//        game->setScreen(temp);
//        game->ReSize();

//        QObjectList objList = this->children();
//        for(auto i = 0; i < objList.size(); i++)
//        {
//            if (dynamic_cast<View*>(objList.at(i)) != 0)
//            {
//                dynamic_cast<View*>(objList.at(i))->ReSize();
//            }
//        }

//        delete temp;
//    }

//    if (width() < game->getW() || height() < game->getH())
//    {
//        QRect * temp = new QRect(ui->centralWidget->geometry());
//        game->setScreen(temp);
//        game->ReSize();

//        QObjectList objList = this->children();
//        for(auto i = 0; i < objList.size(); i++)
//        {
//            if (dynamic_cast<View*>(objList.at(i)) != 0)
//            {
//                dynamic_cast<View*>(objList.at(i))->ReSize();
//            }
//        }

//        delete temp;
//    }
}

void MainWindow::timerHit()
{
    QObjectList objList = this->children();
    for(int i = 0; i < objList.size(); i++)
    {
        if (dynamic_cast<View*>(objList.at(i)) != 0 )
        {
            dynamic_cast<View*>(objList.at(i))->Update(game->getScreen(), game->getBBS(), game->getSS());
        }

    }
    if (game->Collision(j,s, game->getObjects().back()->get_y()) && !c)
    {
        timer->stop();

        nameline = new QLineEdit(this);
        nameline->move(this->width()/2 - 50, this->height()/2 - 50);
        nameline->setPlaceholderText("Enter your name here.");
        nameline->show();

        scorebutton = new QPushButton("Save Scores", this);
        scorebutton->move(this->width()/2 - 50, this->height()/2 + 50);
        connect(scorebutton, SIGNAL(clicked()), this, SLOT(savescorebutton_clicked()));
        scorebutton->show();

        newgame = new QPushButton("Restart?", this);
        newgame->move(this->width()/2 - 150, this->height()/2);
        connect(newgame, SIGNAL(clicked()), this, SLOT(restart_clicked()));
        newgame->show();

        endgame = new QPushButton("End Game?", this);
        endgame->move(this->width()/2 + 50, this->height()/2);
        connect(endgame, SIGNAL(clicked()), this, SLOT(endgame_clicked()));
        endgame->show();
        //QMessageBox::critical(this, "Game Over...", "You have died!");

    }

    scoresheet.incScore();
    int score = scoresheet.getScore();
    QString scorey = QString::number(score);
    scorelabel->setText(scorey);
    scorelabel->show();
}


void MainWindow::keyPressEvent(QKeyEvent *ev) {

    if (ev->key() == Qt::Key_Up && !s)
    {
        j = true;
    }
    if (ev->key() == Qt::Key_Down && !j)
    {
        s = true;
    }
    if (ev->key() == Qt::Key_C)
    {
        if (c) { c = false; } else { c = true; }
    }
}

void MainWindow::restart_clicked() {
    QMessageBox::warning(this, "Uh oh...", "This has yet to be implemented. :(");
    //game->Restart();
}

void MainWindow::endgame_clicked() {
    scoresheet.saveHighScores();
    qApp->quit();
}

void MainWindow::savescorebutton_clicked() {
    if(nameline->text() == "") {
        QMessageBox::warning(this, "Invalid field", "Please enter a name");
    } else {
    scoresheet.saveScore(QString(nameline->text()));
    connect(scorebutton, SIGNAL(clicked()), this, SLOT(scorebutton_clicked()));
    disconnect(scorebutton, SIGNAL(clicked()), this, SLOT(savescorebutton_clicked()));
    scorebutton->setText("See Scores");
    }
}

void MainWindow::scorebutton_clicked() {
    //scoresheet.saveScore(QString(nameline->text()));
    QMessageBox::warning(this, "Scores", scoresheet.printHighScores());
}

//void MainWindow::on_slideBtn_clicked()
//{
//    //person->slide();
//}
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
//}//}

//void MainWindow::on_jumpButton_clicked()
//{
//    /*auto label_width = 100, label_height = 100;
//    auto label_top = (80);
//    auto label_left = (80);

//    QPixmap jumper(":/background_scroll_speedpics/Runner/slide1.png");
//    dude->setScaledContents(true);
//    dude->setPixmap(jumper);
//    //dude->setGeometry(QRect(label_left, label_top, label_width, label_height));
//    dude->move(80, 50);
//    dude->show();
//    */
//    //person->jump();
//}

//void MainWindow::timerHit()
//{
//    for(auto i = 0; i < objList.size(); i++)
//    {
//        if (dynamic_cast<View*>(objList.at(i)) != 0)
//        {
//            dynamic_cast<View*>(objList.at(i))->Update(game->getScreen());
//        }
//    }




//    if (jumping) {
//        mover->dude->move(mover->dude->x(), mover->dude->y() - jumpSpeed);
//        jumpSpeed -= gravity;
//        if (mover->dude->y() >= pos) {
//            jumping = false;
//            jumpSpeed = 14;
//            mover->dude->move(mover->dude->x(), pos);
//        }
//    }
//    if (sliding) {
//        if (slideLength == 20) {
//            QPixmap slide1(":/stuff/slide1.png");
//            mover->dude->setPixmap(slide1);
//        } else if (slideLength == 19){
//            QPixmap slide2(":/stuff/slide2.png");
//            mover->dude->setPixmap(slide2);
//        } else if (slideLength == 18) {
//            QPixmap slide3(":/stuff/slide3.png");
//            mover->dude->setPixmap(slide3);
//        } else if (slideLength <= 17 && slideLength >= 4) {
//            QPixmap slide4(":/stuff/slide4.png");
//            mover->dude->setPixmap(slide4);
//        } else if (slideLength == 3) {
//            QPixmap slide3(":/stuff/slide3.png");
//            mover->dude->setPixmap(slide3);
//        } else if (slideLength == 2) {
//            QPixmap slide2(":/stuff/slide2.png");
//            mover->dude->setPixmap(slide2);
//        } else if (slideLength == 1) {
//            QPixmap slide1(":/stuff/slide1.png");
//            mover->dude->setPixmap(slide1);
//        } else if (slideLength == 0) {
//            sliding = false;
//            slideLength = 21;
//            if (!sliding)
//            {
//            mover->dude->setMovie(running);
//            mover->dude->move(mover->dude->x(), 720);
//            }
//        }
//        slideLength --;
//    }
//}

