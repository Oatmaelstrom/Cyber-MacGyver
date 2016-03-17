#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>

class GameModel;

namespace Ui {
class MainWindow;
}

//Golbal
static int background_scroll_speed = 2;
static int scroll_speed = 15;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void timerHit();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *ev) {

        if (ev->key() == Qt::Key_Up) {
            on_jumpButton_clicked();
        }
        if (ev->key() == Qt::Key_Down) {
            on_slideBtn_clicked();
        }
    }

    void on_slideBtn_clicked();
    void on_jumpButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    //QLabel *dude;
    QMovie *running;
    bool jumping = false;

        const int gravity = 1;
        int jumpSpeed = 14;
        int pos;
        int slideLength = 20;

    GameModel* mover;

public:
    bool sliding = false;

};

#endif // MAINWINDOW_H
