
#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

class UserManager
{
private:
    string filename;

private:
    void colorPurple();
    void colorRed();
    void colorGreen();
    void colorYellow();
    void colorBlue();
    void colorMagenta();
    void colorCyan();
    void colorPink();
    void colorBurgundy();
    void colorWHITE();
    struct UserData
    {
        string username;
        int score;
        UserData(string u, int s) : username(u), score(s) {}
        bool operator<(const UserData &other) const{
            return score > other.score;
        }
    };

    bool checkUserExists(const string &username) const;
    void saveUser(const string &username, const string &password, int score = 0) const
    {
        ofstream file(filename, ios::app);
        file << username << endl;
        file << password << endl;
        file << score << endl;
        file << endl; // Blank line to separate entries
        file.close();
    }
    void ensureFileExists(const string &filename) const;


public:
    UserManager(const string &filename) : filename(filename){
        ensureFileExists(filename);
    }
    bool validateUser(const string &username, const string &password) const;
    int getUserScore(const string &username) const;
    void updateScore(const string &username, int pointsToAdd) const;
    void displayLoadingBar();
    void signUp();
    friend string logIn();
    void loadAndDisplayLeaderboard();
    friend void displayScore();
   
};

#endif
