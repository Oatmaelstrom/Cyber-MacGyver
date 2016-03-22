#include "HighScores.h"
#include <fstream>
#include <QMessageBox>
#include <mainwindow.h>
#include <QString>
#include <cassert>
#include <iostream>

using namespace std;

void Score::saveScore(string name) {
        HighScoresNames.push_back(name);
        HighScoresValues.push_back(currentScore);
}

void Score::saveHighScores() {
    ofstream file;
    file.open("highscores.txt");
    for (size_t i = 0; i < HighScoresNames.size(); i++) {
        file << HighScoresNames.at(i) << endl;
        file << HighScoresValues.at(i) << endl;
    }
    file.close();
}

void Score::loadHighScores() {
    ifstream file;
    file.open("highscores.txt");
    string input;
    bool flip = true;
    while (getline(file, input)) {
        if(flip) {
            HighScoresNames.push_back(input);
            flip = false;
        } else {
            int num = stoi(input);
            HighScoresValues.push_back(num);
            flip = true;
        }
    }
}

string Score::printHighScores() {
    QString text;
    QString num;
    QString from;

    for(size_t i = 0; i < HighScoresNames.size(); i++) {
        num = "";
        text += num.number((i + 1), 10);
        text += ": ";
        from = "";
        text += from.fromStdString(HighScoresNames.at(i));
        text += " - ";
        num = "";
        text += num.number(HighScoresValues.at(i), 10);
        text += "\n";

    }
    return text.toStdString();
    //QMessageBox Scorebox;
    //Scorebox.setWindowTitle("High Scores");
    //Scorebox.setText(text);
    //Scorebox.show();
}

bool Score::removeByName(string name) {

    for(size_t i = 0; i < HighScoresNames.size(); i++) {
        if(HighScoresNames.at(i) == name) {
            HighScoresValues.erase(HighScoresValues.begin() + i);
            HighScoresNames.erase(HighScoresNames.begin() + i);
            return true;
        }
    }
    return false;
}

void Score::resetHighScores() {
        HighScoresNames.clear();
        HighScoresValues.clear();
}

bool Score::Scoretest() {
    Score* scorbject = new Score;
    scorbject->setScore(25);
    scorbject->saveScore("Bobaloo");
    assert(scorbject->getHighScoresNames().at(0) == "Bobaloo");
    assert(scorbject->getHighScoresValues().at(0) == 25);
    scorbject->incScore();
    scorbject->saveScore("Unferth");
    scorbject->saveHighScores();
    scorbject->resetHighScores();
    scorbject->loadHighScores();
    assert(scorbject->getHighScoresNames().at(1) == "Unferth");
    assert(scorbject->getHighScoresValues().at(1) == 26);
    string output = scorbject->printHighScores();
    cout << output << endl;
    if(scorbject->removeByName("Bobaloo")) {
        output = scorbject->printHighScores();
        cout << output << endl;
    }
    delete scorbject;
    return true;
}
