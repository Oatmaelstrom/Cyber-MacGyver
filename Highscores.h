#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QObject>
#include <vector>
#include <QString>
#include <string>

using namespace std;

class Score : public QObject{

    vector<string> HighScoresNames;
    vector<int> HighScoresValues;
    int currentScore;

public:

    Score() { currentScore = 0; }

    vector<string> getHighScoresNames() {return HighScoresNames; }
    vector<int> getHighScoresValues() {return HighScoresValues;}

    void setScore(int newScore) { currentScore = newScore; }
    int getScore() { return currentScore; }
    void incScore() { currentScore++; }
    //saves currentScore to HighScores. Executed upon player death.
    void saveScore(QString name);

    //saves HighScores to a file
    void saveHighScores();
    //loads HighScores from file
    void loadHighScores();
    QString printHighScores();
    void resetHighScores();
    //returns true if successfully removes score. false if did not remove score.
    bool removeByName(string name);
    bool Scoretest();
    void sortScores();
};


#endif // HIGHSCORES_H
