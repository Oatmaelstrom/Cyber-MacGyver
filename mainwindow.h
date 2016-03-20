#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>


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

    void set_j(bool y_n) {j = y_n;}
    void set_s(bool y_n) {s = y_n;}

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    GameModel *game;
    View *label;

    bool j, s;

};

#endif // MAINWINDOW_H
