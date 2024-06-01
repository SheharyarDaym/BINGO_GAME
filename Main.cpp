#include<iostream>
#include<conio.h>
#include<string>
#include<chrono>
#include<ctime>
#include<Windows.h>
#include<fstream>
// #include"Bingo.hh"
#include"Bingo.cpp"
// #include"PlayAsGuest.hh"
#include"PlayAsGuest.cpp"
// #include"UserInfo.hh"
#include"UserInfo.cpp"
using namespace std;


void readFileAndPrint(const string& filename);
void display();
void colorRed();
void colorGreen();
void colorYellow();
void colorBlue();
void colorMagenta();
void colorCyan();
void colorPink();
void colorPurple();
void colorBurgundy();
void resetTextColor();
void Time();
void pressAnyKeyToContinue();
int integerValidation(int &number);
bool AreYouSure();


int main()
{

    colorPurple();
    cout << "\t\t\t\t\tBBBBB   IIIIII  N    N   GGGGG   OOOO " << endl;
    colorRed();
    cout << "\t\t\t\t\tB   BB    II    NN   N  G       O    O" << endl;
    colorYellow();
    cout << "\t\t\t\t\tBBBB      II    N N  N  G   GG  O    O" << endl;
    colorPink();
    cout << "\t\t\t\t\tB   BB    II    N  N N  G    G  O    O" << endl;
    colorBurgundy();
    cout << "\t\t\t\t\tBBBBB   IIIIII  N   NN   GGGG    OOOO " << endl;
    resetTextColor();
    pressAnyKeyToContinue();
    system("cls");
    colorGreen();
    Time();
    UserManager userManager("users.txt");
    int choice;
    do
    {
        // cout << "1. Login\n"; // Login function should be implemented similarly to signUp
        // cout << "2. Signup\n";
        // cout << "3. View Leaderboard\n";
        // cout << "4. Exit\n";
        display();
        cout << "Enter choice: ";
        integerValidation(choice);

        if(choice == 1){
            system("cls");
            //userManager.logIn(); // Implement login functionality
            // Bingo b;
            Bingo b;
        }
        else if(choice == 2){
            system("cls");
            userManager.signUp();
        }
        else if(choice == 3){
            system("cls");
            userManager.loadAndDisplayLeaderboard();
            pressAnyKeyToContinue();
            system("cls");
        }
        else if(choice == 4){
            system("cls");
            readFileAndPrint("Play.txt"); 
            colorYellow();
            pressAnyKeyToContinue();
            resetTextColor();
            system("cls");
        }
        else if(choice == 5){ 
            system("cls");
            // cout << "Play As Guest" << endl;
            BingoGuest b;
        }
        else if(choice == 6){
            if(AreYouSure() == true){
                colorGreen();
                cout << "Exiting..." << endl;
                resetTextColor();
            }
            else
                choice = 7;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != 6);


    return 0;
}






void display(){
    // Login
    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +-------+" << endl; 
    colorGreen();
    cout << "\t\t\t\t\t  ["; resetTextColor(); cout << "1"; 
    colorGreen(); cout << "]";
    colorBurgundy();
    cout << "\t   |"; colorGreen(); cout <<" LOGIN "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +-------+" << endl << endl;

    // SignUp
    colorBurgundy();
    cout << "\t\t\t\t\t\t   +---------+" << endl; 
    colorGreen();
    cout << "\t\t\t\t\t  ["; resetTextColor(); cout << "2"; 
    colorGreen(); cout << "]";
    colorBurgundy();
    cout << "\t   |"; colorGreen(); cout <<" SIGN UP "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +---------+" << endl << endl;

    // View Leaderboard
    colorBurgundy();
    cout << "\t\t\t\t\t\t   +------------------+" << endl; 
    colorGreen();
    cout << "\t\t\t\t\t  ["; resetTextColor(); cout << "3"; 
    colorGreen(); cout << "]";
    colorBurgundy();
    cout << "\t   |"; colorBlue(); cout <<" VIEW LEADERBOARD "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +------------------+" << endl << endl;

     // How to Play
    colorBurgundy();
    cout << "\t\t\t\t\t\t   +--------------+" << endl; 
    colorGreen();
    cout << "\t\t\t\t\t  ["; resetTextColor(); cout << "4"; 
    colorGreen(); cout << "]";
    colorBurgundy();
    cout << "\t   |"; colorYellow(); cout <<" HOW TO PLAY  "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +--------------+" << endl << endl;

     // Play as Guest
    colorBurgundy();
    cout << "\t\t\t\t\t\t   +---------------+" << endl; 
    colorGreen();
    cout << "\t\t\t\t\t  ["; resetTextColor(); cout << "5"; 
    colorGreen(); cout << "]";
    colorBurgundy();
    cout << "\t   |"; colorCyan(); cout <<" PLAY AS GUEST "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +---------------+" << endl << endl;

    // Exit
    colorBurgundy();
    cout << "\t\t\t\t\t\t   +------+" << endl; 
    colorGreen();
    cout << "\t\t\t\t\t  ["; resetTextColor(); cout << "6"; 
    colorGreen(); cout << "]";
    colorBurgundy();
    cout << "\t   |"; colorRed(); cout <<" EXIT "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +------+" << endl << endl;

    resetTextColor();

}




void colorRed(){
    cout << "\033[1;31m"; 
}

void colorGreen(){
    cout << "\033[1;32m"; 
}

void colorYellow(){
    cout << "\033[1;33m"; 
}

void colorBlue(){
    cout << "\033[1;34m"; 
}

void colorMagenta(){
    cout << "\033[1;35m"; 
}

void colorCyan(){
    cout << "\033[1;36m"; 
}

void colorPink(){
    cout << "\033[38;5;206m";
}

void colorPurple(){
    cout << "\033[38;5;129m"; 
}

void colorBurgundy(){
    cout << "\033[38;5;52m"; 
}


void resetTextColor(){
    cout << "\033[0m"; 
}


void Time(){
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << asctime(localTime);
}


void pressAnyKeyToContinue() {
    colorYellow();
    cout << "Press any key to continue...";
    _getch();  
    cout << endl;  
    resetTextColor();
}

// Input Validation
int integerValidation(int &number)
    {
        bool validInput = false;
        while (!validInput)
        {
            if (cin >> number)
            {
                if (number>=1 && number<=6)
                    validInput = true;
                else
                cout << "Please Enter number from (1-6)" << endl;
                    
            }
            
            else
            {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Invalid input. Please enter a valid number." << endl;
            }
        }
        return number;
    }



void readFileAndPrint(const string& filename) {
    colorCyan();
    ifstream file(filename); 
    if (!file.is_open()) { 
        cerr << "Error: Could not open the file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) { 
        cout << line << endl; 
    }

    file.close(); 

    resetTextColor();
}

bool AreYouSure(){
    system("cls");
    cout << "\a";
    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +--------------+" << endl; 
    // colorGreen();
    cout << "\t\t\t\t\t  "; 
    // resetTextColor();
    // colorGreen(); 
    cout << "";
    // colorBurgundy();
    cout << "\t   |"; 
    colorGreen(); 
    cout <<" ARE YOU SURE ";
    colorBurgundy(); 
    cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +--------------+" << endl << endl;

    //----------------------------------------------

    // colorBurgundy();
    cout << "\n\t\t\t\t\t   +---------+"  << "\t\t+---------+"<< endl; 
    // colorGreen();
    cout << "\t\t\t\t  "; 
    cout << "\t   |"; 
    colorGreen();
    cout <<"   YES ";
    // resetTextColor();
    // colorGreen(); 
    // colorBurgundy();
    // colorGreen(); 
    colorBurgundy(); 
    cout << "  |";
    cout << "\t"; 
    cout << "\t|"; 
    colorGreen();
    cout <<"   NO   ";
    colorBurgundy(); 
    cout << " |";

    cout << "\n\t\t\t\t\t   +---------+";
    cout << "\t\t+---------+";
    resetTextColor();

    while(1){

        string check;
        colorBlue();
        cout << "\nEnter here: ";
        colorCyan();
        cin >> check;
        transform(check.begin(), check.end(), check.begin(), ::tolower);
        if(check == "yes"){
            system("cls");
            return true;
        }
        else if(check == "no"){
            system("cls");
            return false;
        }
        else{
            colorRed();
            cout << "Please write yes or no! " << endl;
        }
        resetTextColor();

    }

}
