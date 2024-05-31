// #ifndef PLAYASGUEST_H
// #define PLAYASGUEST_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<Windows.h>
#include<vector>
using namespace std;


class BingoGuest{
protected:
    void pressAnyKeyToContinue();
    int integerValidation(int &number);

    void colorPurple();

    void colorRed();

    void colorGreen();

    void colorYellow();

    void colorBlue();

    void colorMagenta();

    void colorCyan();

    void colorPink();

    // void colorPurple(){
    //     cout << "\033[38;5;129m"; 
    // }

    void colorBurgundy();

    

    void colorWHITE();

    // void colorBlue(){
    //     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //     SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    // }

    // void colorRed(){
    //     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //     SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    // }


    void RandomNumberGenerator(int* arr);

    void displayC(int arr[][5]);

    void display(int arr[][5]);
    void delay();

    void beepDelay();
    int checkBingo(int arr[][5]);
    void displayLoadingBar();


public:

// Constructor
    BingoGuest();

    void PlayGame();
   
    

};






// #endif