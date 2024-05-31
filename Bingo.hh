#ifndef PLAYASGUEST_H
#define PLAYASGUEST_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<Windows.h>
#include<vector>
#include"UserInfo.hh" 
using namespace std;


class Bingo{
private:
    UserManager userManager;
    int score=0;
    string user;

protected:
    void pressAnyKeyToContinue();
    int integerValidation(int &number);
    int integerValidation2(int &number);

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

    void RandomNumberGenerator(int* arr);

    void displayC(int arr[][5]);

    void display(int arr[][5]);

    void delay();

    void beepDelay();

    int checkBingo(int arr[][5]);


    string logIn();
    void displayScore();
    void displayLoadingBar();
    void displayConstructor();
    void playAgain();
    void Password(string& p);

public:
    Bingo();
    void PlayGame();

};


#endif