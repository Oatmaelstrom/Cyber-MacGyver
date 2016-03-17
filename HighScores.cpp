#include "HighScores.h"
#include <fstream>
#include <QMessageBox>
#include <mainwindow.h>
#include <QString>

using namespace std;

void Score::saveScore(string name) {

    for(size_t i = 0; i < HighScoresValues.size(); i++) {
        if(currentScore >= HighScoresValues.at(i)) {
            HighScoresValues.insert (HighScoresValues.begin() + i, currentScore);
            HighScoresNames.insert (HighScoresNames.begin() + i, name);
        }
    }
}

void Score::saveHighScores() {
    ofstream file;
    file.open("highscores.txt");
    for (size_t i = 0; i < HighScoresNames.size(); i++) {
        file << HighScoresNames.at(i);
        file << HighScoresValues.at(i);
    }
    file.close();
}

void Score::loadHighScores() {
    ifstream file;
    file.open("highscores.txt");
    file.seekg(0,file.end);
    long size = file.tellg();
    file.seekg(0);
    char* buffer = new char[size];
    file.read (buffer, size);
    string input;
    vector<string> lines;
    for(size_t i = 0; i < size; i++) {
        if(buffer[i] != '\n') {
            input += buffer[i];
        } else {
            lines.push_back(input);
            input = "";
        }
    }
    bool flip = true;
    for(size_t i = 0; i < lines.size(); i++) {
        if(flip) {
            HighScoresNames.push_back(lines.at(i));
            flip = false;
        } else {
            QString numstr;
            numstr.fromStdString(lines.at(i));
            int num = numstr.toInt();
            HighScoresValues.push_back(num);
            flip = true;
        }
    }
}

void Score::printHighScores() {
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
    QMessageBox Scorebox;
    Scorebox.setWindowTitle("High Scores");
    Scorebox.setText(text);
    Scorebox.show();

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
