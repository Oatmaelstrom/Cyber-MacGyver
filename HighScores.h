#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QObject>
#include <vector>
#include <string>

using namespace std;

class Score : public QObject{

    vector<string> HighScoresNames;
    vector<int> HighScoresValues;
    int currentScore;

public:

    void setScore(int newScore) { currentScore = newScore; }
    int getScore() { return currentScore; }
    void incScore() { currentScore++; }
    //saves currentScore to HighScores. Executed upon player death.
    void saveScore(string name);

    //saves HighScores to a file
    void saveHighScores();
    //loads HighScores from file
    void loadHighScores();
    void printHighScores();
    void resetHighScores();
    //returns true if successfully removes score. false if did not remove score.
    bool removeByName(string name);
};


#endif // HIGHSCORES_H
