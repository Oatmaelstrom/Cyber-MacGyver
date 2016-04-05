#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include <QLineEdit>
#include <QPushButton>

#include "Highscores.h"

namespace Ui
{
class MainWindow;
}

class GameModel;
class View;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void timerHit();
    void restart_clicked();
    void endgame_clicked();
    void scorebutton_clicked();
    void savescorebutton_clicked();

private: //methods
    void Load();
    void Print();

    void resizeEvent(QResizeEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *ev);

    bool get_j() {return j;}
    bool get_s() {return s;}
    bool get_c() {return c;}
    int getDeathTicker() {return deathTicker;}

    void set_j(bool y_n) {j = y_n;}
    void set_s(bool y_n) {s = y_n;}
    void deathTick() {deathTicker--;}

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    GameModel *game;
    View *label;

    bool j, s, c;
    int deathTicker = 15;

    Score scoresheet;
    QLineEdit *nameline;

    QLabel *scorelabel;

    QPushButton *endgame;
    QPushButton *newgame;
    QPushButton *scorebutton;
};

#endif // MAINWINDOW_H
