#ifndef P_H
#define P_H

#include"PlayAsGuest.hh"
#include<conio.h>

void BingoGuest::pressAnyKeyToContinue()
{
    cout << "Press any key to continue...";
    _getch();  
    cout << endl;  
}

int BingoGuest::integerValidation(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number>=1 && number<=25)
                validInput = true;
            else
            cout << "Please Enter number from (1-25)" << endl;
                
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


// Colors
void BingoGuest::colorPurple(){
    cout << "\033[38;5;129m"; 
}

void BingoGuest::colorRed(){
    cout << "\033[1;31m"; 
}

void BingoGuest::colorGreen(){
    cout << "\033[1;32m"; 
}

void BingoGuest::colorYellow(){
    cout << "\033[1;33m"; 
}

void BingoGuest::colorBlue(){
    cout << "\033[1;34m"; 
}

void BingoGuest::colorMagenta(){
    cout << "\033[1;35m"; 
}

void BingoGuest::colorCyan(){
    cout << "\033[1;36m"; 
}

void BingoGuest::colorPink(){
    cout << "\033[38;5;206m";
}


void BingoGuest::colorBurgundy(){
    cout << "\033[38;5;52m"; 
}

void BingoGuest::colorWHITE(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
}



// Functions
void BingoGuest::RandomNumberGenerator(int* arr)
{
    srand(time(0));
    const int size = 25;
    for(int i=0; i<size; i++){
        int j = rand() % size;
        swap(arr[i], arr[j]);
    }
}


void BingoGuest::displayC(int arr[][5])
{
    for(int i=0; i<5; i++) {
        cout << "\t\t\t\t\t";
        for(int j=0; j<5; j++){
            if(arr[i][j] == 0){
                colorRed();
                cout << setw(4) << right << "X";
                colorWHITE();
            }
            
            else{
                colorCyan();
                cout << setw(4) << right << arr[i][j];
                colorWHITE();
            } 
        }
        cout << endl << endl;
    }
}

void BingoGuest::display(int arr[][5])
{
    for(int i=0; i<5; i++) {
        cout << "\t\t\t\t\t";
        for(int j=0; j<5; j++){
            if(arr[i][j] == 0){
                colorRed();
                cout << setw(4) << right << "X";
                colorWHITE();
            }
            else{
                colorCyan();
                cout << setw(4) << right << arr[i][j];
                colorWHITE();
            } 
        }
        cout << endl << endl;
    }
}

void BingoGuest::delay()
{
    cout << "Loading";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
}

void BingoGuest::beepDelay(){
    Beep(900, 800);
    Beep(800, 500);
    Beep(600, 600);
}


// Bingo checking
int BingoGuest::checkBingo(int arr[][5])
{
    int rowC = 0; 
    int colC = 0; 

    for(int i=0; i<5; i++)
    {
        int rowZC = 0;
        int colZC = 0;
        
        for(int j=0; j<5; j++)
        {
            if(arr[i][j] == 0){
                rowZC++;
            } 
            if (arr[j][i] == 0){
                colZC++;
            } 
        }
        if(rowZC == 5){
            rowC++;
        } 
        if(colZC == 5){
            colC++;
        }
    }
    if(rowC + colC == 5 || rowC + colC == 6 || rowC + colC == 7 ) return 5;
    else if(rowC + colC == 1) return 1;
    else if(rowC + colC == 2) return 2;
    else if(rowC + colC == 3) return 3;
    else if(rowC + colC == 4) return 4;
    else return 0; 
}




// Constructor
BingoGuest::BingoGuest()
{   
    displayLoadingBar();

    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +-------+" << endl; 
    colorBurgundy();
    cout << "\t\t\t\t\t\t   |"; colorGreen(); cout <<" START "; colorBurgundy(); cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +-------+" << endl << endl;
    colorYellow();
    pressAnyKeyToContinue();
    colorWHITE();

    system("cls");
    colorGreen();
    cout << "\t\t\t   ----------------WELCOME TO BINGO----------------" << endl << endl << endl; 

    PlayGame();


}



// Play Game Bingo
void BingoGuest::PlayGame()
{
    srand(time(0));
    // colorWHITE();
    // random number for input data in matrix1
    int randomNumber[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    RandomNumberGenerator(randomNumber);
    // random number for input data in matrix2
    int randomComputer[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                              15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    // Calling function 2 times for better shuffle :)
    RandomNumberGenerator(randomComputer);
    RandomNumberGenerator(randomComputer);

    // For input random numbers by computer..
    int random[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                      15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    // Calling function 2 times for better shuffle :)
    RandomNumberGenerator(random);
    RandomNumberGenerator(random);

    int matrix1[5][5];
    int matrix2[5][5];

    // Input data
    // User
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix1[i][j] = randomNumber[k];
            k++;
        }
    }
    // Computer
    int s = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix2[i][j] = randomComputer[s];
            s++;
        }
    }
    display(matrix1);

    // numbers range 1-25
    vector<int> calledNumbers;
    for (int i = 0; i < 25; i++)
    {
        calledNumbers.push_back(i + 1);
    }

    int check = 0; // for BINGO  --> XINGO ..
                   // Results
    for (int i = 0; i < 35; i++)
    {

        if (i % 2 == 0)
        {
            int calling;
            colorPink();
            cout << "Call number: ";
            colorWHITE();
            int index;
            while (1)
            {
                // cin >> calling;
                integerValidation(calling);

                // Finding the index of the called numbers
                auto it1 = find(calledNumbers.begin(), calledNumbers.end(), calling);

                if (it1 != calledNumbers.end())
                {
                    int ind = distance(calledNumbers.begin(), it1);
                    index = ind;
                    break;
                }
                else
                {
                    cout << "This number is already called" << endl;
                    cout << "Enter number again from the matrix: ";
                }
            }

            // User
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (matrix1[j][k] == calledNumbers[index])
                    {
                        matrix1[j][k] = 0;
                    }
                }
            }
            // pressAnyKeyToContinue();
            // system("cls");
            colorPink();
            cout << "Your BINGO card! " << endl;
            colorWHITE();
            if (checkBingo(matrix1) == 1)
            {
                check = 1;
                colorBurgundy();
                cout << "\t\t\t\t  X ";
                colorGreen();
                cout << "\t I \t N \t G \t O" << endl
                     << endl;
            }
            if (check == 0)
            {
                colorGreen();
                cout << "\t\t\t\t  B ";
                cout << "\t I \t N \t G \t O" << endl
                     << endl;
                colorWHITE();
            }
            if (checkBingo(matrix1) == 2)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X ";
                colorGreen();
                cout << "\t N \t G \t O" << endl
                     << endl;
            }
            if (checkBingo(matrix1) == 3)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X ";
                colorGreen();
                cout << "\t G \t O" << endl
                     << endl;
            }
            if (checkBingo(matrix1) == 4)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X \t X ";
                colorGreen();
                cout << "\t O" << endl
                     << endl;
            }
            displayC(matrix1);

            // Computer --> HIDDEN
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (matrix2[j][k] == calling)
                    {
                        matrix2[j][k] = 0;
                    }
                }
            }
            // cout << "Computer matrix: " << endl;
            // display(matrix2);

            // Deleting the called number so that it cannot be called again..
            auto it2 = std::find(calledNumbers.begin(), calledNumbers.end(), calling);
            if (it2 != calledNumbers.end())
            {
                calledNumbers.erase(it2);
            }
        }

        else if (i % 2 != 0) // Computer's turn
        {
            int calledNumber;
            // Loop until a valid, uncalled number is generated
            while (true)
            {
                int ranIndex = rand() % calledNumbers.size(); // Generate a random index based on remaining numbers
                calledNumber = calledNumbers[ranIndex];       // Select a number from the remaining valid options

                delay();
                colorPink();
                cout << "Number: " << calledNumber << " called!" << endl;
                colorWHITE();

                // Now handle the called number as usual
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (matrix1[j][k] == calledNumber)
                        {
                            matrix1[j][k] = 0; // Mark the number in user's matrix
                        }
                        if (matrix2[j][k] == calledNumber)
                        {
                            matrix2[j][k] = 0; // Mark the number in computer's matrix
                        }
                    }
                }

                // Delete the called number
                calledNumbers.erase(calledNumbers.begin() + ranIndex);
                break; 
            }
            Beep(1000, 250);
            pressAnyKeyToContinue();
            system("cls");
            colorYellow();
            if (checkBingo(matrix1) == 1)
            {
                check = 1;
                colorBurgundy();
                cout << "\t\t\t\t  X ";
                colorGreen();
                cout << "\t I \t N \t G \t O" << endl
                     << endl;
            }
            if (check == 0)
            {
                colorGreen();
                cout << "\t\t\t\t  B ";
                cout << "\t I \t N \t G \t O" << endl
                     << endl;
                colorWHITE();
            }
            if (checkBingo(matrix1) == 2)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X ";
                colorGreen();
                cout << "\t N \t G \t O" << endl
                     << endl;
            }
            if (checkBingo(matrix1) == 3)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X ";
                colorGreen();
                cout << "\t G \t O" << endl
                     << endl;
            }
            if (checkBingo(matrix1) == 4)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X \t X ";
                colorGreen();
                cout << "\t O" << endl
                     << endl;
            }
            displayC(matrix1);

            // Computer --> HIDDEN
            // for(int j=0; j<5; j++){
            //     for(int k=0; k<5; k++){
            //         if(matrix2[j][k] == random[index]){
            //             matrix2[j][k] = 0;
            //         }
            //     }
            // }
            // cout << "Computer matrix: " << endl;
            // display(matrix2);

            // Deleting the called number so that it cannot be called again..
            // auto it2 = find(calledNumbers.begin(), calledNumbers.end(), random[index]);
            // if(it2 != calledNumbers.end()){
            //     calledNumbers.erase(it2);
            // }
        }

        // For display
        if (checkBingo(matrix1) == 5 && checkBingo(matrix2) == 5)
        {
            beepDelay();
            beepDelay();
            // cout << "BINGO STOP" << endl;
            cout << endl
                 << endl;
            system("cls");
            colorGreen();

            cout << "YOUR'S BINGO CARD " << endl;
            display(matrix1);
            colorYellow();
            cout << "COMPUTER'S BINGO CARD" << endl;
            display(matrix2);

            colorGreen();
            cout << "GAME DRAW" << endl;
            cout << "\t\t\t\t\tBBBBB   IIIIII  N    N   GGGGG   OOOO " << endl
                 << "\t\t\t\t\tB   BB    II    NN   N  G       O    O" << endl
                 << "\t\t\t\t\tBBBB      II    N N  N  G   GG  O    O" << endl
                 << "\t\t\t\t\tB   BB    II    N  N N  G    G  O    O" << endl
                 << "\t\t\t\t\tBBBBB   IIIIII  N   NN   GGGG    OOOO " << endl
                 << endl;
            colorWHITE();
            pressAnyKeyToContinue();
            system("cls");
            break;
        }

        else if (checkBingo(matrix1) == 5)
        {
            beepDelay();
            beepDelay();
            // cout << "BINGO STOP" << endl;
            cout << endl
                 << endl;
            system("cls");
            colorGreen();

            cout << "YOUR'S BINGO CARD " << endl;
            display(matrix1);
            colorYellow();
            cout << "COMPUTER'S BINGO CARD" << endl;
            display(matrix2);

            colorGreen();
            cout << "You WON:" << endl;
            cout << "\t\t\t\t\tBBBBB   IIIIII  N    N   GGGGG   OOOO " << endl
                 << "\t\t\t\t\tB   BB    II    NN   N  G       O    O" << endl
                 << "\t\t\t\t\tBBBB      II    N N  N  G   GG  O    O" << endl
                 << "\t\t\t\t\tB   BB    II    N  N N  G    G  O    O" << endl
                 << "\t\t\t\t\tBBBBB   IIIIII  N   NN   GGGG    OOOO " << endl
                 << endl;
            colorWHITE();
            pressAnyKeyToContinue();
            system("cls");
            break;
        }

        else if (checkBingo(matrix2) == 5)
        {
            beepDelay();
            beepDelay();
            // cout << "BINGO STOP" << endl;
            cout << endl
                 << endl;
            system("cls");
            colorGreen();

            cout << "YOUR'S BINGO CARD " << endl;
            display(matrix1);
            colorYellow();
            cout << "COMPUTER'S BINGO CARD" << endl;
            display(matrix2);

            colorGreen();
            cout << "Computer WON:" << endl;
            cout << "\t\t\t\t\tBBBBB   IIIIII  N    N   GGGGG   OOOO " << endl
                 << "\t\t\t\t\tB   BB    II    NN   N  G       O    O" << endl
                 << "\t\t\t\t\tBBBB      II    N N  N  G   GG  O    O" << endl
                 << "\t\t\t\t\tB   BB    II    N  N N  G    G  O    O" << endl
                 << "\t\t\t\t\tBBBBB   IIIIII  N   NN   GGGG    OOOO " << endl
                 << endl;
            colorWHITE();
            pressAnyKeyToContinue();
            system("cls");
            break;
        }

    }
}


void BingoGuest::displayLoadingBar(){
    int totalSteps = 100;
    int width = 20; 

    for(int progress = 0; progress <= totalSteps; progress++){
        int pos = width * progress / totalSteps;
        string bar = "\033[32m" + string(pos, '=') + "\033[0m" + string(width - pos, ' ');
        cout << "\r[Loading] [" << bar << "] " << (progress * 100 / totalSteps) << "%";
        if(progress != totalSteps){
            Sleep(100); 
            
            cout << "\r[Loading] [" << string(20, ' ') << "] ";
            cout.flush(); 
        }
        progress +=3;
    }
    cout << endl;
}

#endif
