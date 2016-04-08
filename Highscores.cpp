#include "Highscores.h"
#include <fstream>
#include <QMessageBox>
#include <mainwindow.h>
#include <QString>
#include <cassert>
#include <iostream>

using namespace std;


void Score::saveScore(QString name) {
        HighScoresNames.push_back(name.toStdString());
        HighScoresValues.push_back(currentScore);
        this->sortScores();
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

QString Score::printHighScores() {
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
        if (i >= 10) {
            return text;    //return top 10 scores
        }
    }
    return text;
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
    assert(scorbject->getHighScoresNames().at(0) == "Unferth");
    assert(scorbject->getHighScoresValues().at(0) == 26);
    QString output = scorbject->printHighScores();
    cout << output.toStdString() << endl;
    if(scorbject->removeByName("Bobaloo")) {
        output = scorbject->printHighScores();
        cout << output.toStdString() << endl;
    }
    delete scorbject;
    return true;
}

void Score::sortScores() {
    for (int j = 0; j < HighScoresValues.size(); j++) {
        for (int i = j; i < HighScoresValues.size(); i++) {
            if (HighScoresValues.at(j) < HighScoresValues.at(i)) {
                swap(HighScoresValues.at(j), HighScoresValues.at(i));
                swap(HighScoresNames.at(j), HighScoresNames.at(i));
            }
        }
    }
}
