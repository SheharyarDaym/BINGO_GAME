#include "Bingo.hh"
#include "UserInfo.hh"
#include <conio.h>
#include <windows.h>
#include <limits>

void Bingo::pressAnyKeyToContinue()
{
    colorYellow();
    cout << "Press any key to continue...";
    _getch();
    colorWHITE();
    cout << endl;
}

int Bingo::integerValidation(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number >= 1 && number <= 25)
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

int Bingo::integerValidation2(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number >= 1 && number <= 3)
                validInput = true;
            else
                cout << "Please Enter number from (1-2)" << endl;
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
void Bingo::colorPurple()
{
    cout << "\033[38;5;129m";
}

void Bingo::colorRed()
{
    cout << "\033[1;31m";
}

void Bingo::colorGreen()
{
    cout << "\033[1;32m";
}

void Bingo::colorYellow()
{
    cout << "\033[1;33m";
}

void Bingo::colorBlue()
{
    cout << "\033[1;34m";
}

void Bingo::colorMagenta()
{
    cout << "\033[1;35m";
}

void Bingo::colorCyan()
{
    cout << "\033[1;36m";
}

void Bingo::colorPink()
{
    cout << "\033[38;5;206m";
}

void Bingo::colorBurgundy()
{
    cout << "\033[38;5;52m";
}

void Bingo::colorWHITE()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
}

// Functions
void Bingo::RandomNumberGenerator(int *arr)
{
    srand(time(0));
    const int size = 25;
    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        swap(arr[i], arr[j]);
    }
}

void Bingo::Password(string& p){

    char ch;
    while ((ch = getch()) != '\r') {  // '\r' is the carriage return character
        if (ch == '\b') {  
            if (!p.empty()) {
                cout << "\b \b";  // Move cursor back, print space, and move back again
                p.pop_back();
            }
        } else {
            p.push_back(ch);
            cout << '*';
        }
    }
}

string Bingo::logIn()
{
    string username, password;
    colorCyan();
    colorGreen();
    cout << "\t\t\t\t\tUsername: ";
    colorCyan();
    cin >> username;
    colorGreen();
    cout << "\t\t\t\t\tPassword: ";
    colorRed();
    Password(password);
    cout << endl;
    colorWHITE();
    if (userManager.validateUser(username, password))
    {
        user = username; // Set the current user
        system("cls");
        displayLoadingBar();
        colorGreen();
        cout << "Login successful!" << endl;
        colorWHITE();
        return user;
    }
    else
    {
        displayLoadingBar();
        colorRed();
        cout << "Invalid username or password." << endl;
        colorWHITE();
        pressAnyKeyToContinue();
        system("cls");
        user.clear(); // Clear the current user on failed login
        return "0";
    }
    return "";
}
void Bingo::displayScore()
{
    if (!user.empty())
    {
        int score = userManager.getUserScore(user);
        if (score != -1)
        {
            colorPink();
            cout << "Score for " << user << ": " << score << endl;
            colorWHITE();
        }
        else
        {
            cout << "User not found." << endl;
        }
    }
    else
    {
        cout << "No user is currently logged in." << endl;
    }
}

// void Bingo::displayC(int arr[][5])
// {
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "\t\t\t\t\t";
//         for (int j = 0; j < 5; j++)
//         {
//             if (arr[i][j] == 0)
//             {
//                 colorRed();
//                 cout << setw(4) << right << "X";
//                 colorWHITE();
//             }

//             else
//             {
//                 colorCyan();
//                 cout << setw(4) << right << arr[i][j];
//                 colorWHITE();
//             }
//         }
//         cout << endl << endl;
//     }
// }

void Bingo::display(int arr[][5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\t\t\t\t\t";
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 0)
            {
                colorRed();
                cout << setw(4) << right << "X";
                colorWHITE();
            }
            else
            {
                colorCyan();
                cout << setw(4) << right << arr[i][j];
                colorWHITE();
            }
            // else cout << setw(4) << right << arr[i][j];
        }
        cout << endl << endl;
    }
}

void Bingo::delay()
{
    colorGreen();
    cout << "Loading";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;
    colorWHITE();
}

void Bingo::beepDelay()
{
    Beep(900, 800);
    Beep(800, 500);
    Beep(600, 600);
}

// Bingo checking
int Bingo::checkBingo(int arr[][5])
{
    int rowC = 0;
    int colC = 0;

    for (int i = 0; i < 5; i++)
    {
        int rowZC = 0;
        int colZC = 0;

        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 0)
            {
                rowZC++;
            }
            if (arr[j][i] == 0)
            {
                colZC++;
            }
        }
        if (rowZC == 5)
        {
            rowC++;
        }
        if (colZC == 5)
        {
            colC++;
        }
    }
    if (rowC + colC == 5 || rowC + colC == 6 || rowC + colC == 7)
        return 5;
    else if (rowC + colC == 1)
        return 1;
    else if (rowC + colC == 2)
        return 2;
    else if (rowC + colC == 3)
        return 3;
    else if (rowC + colC == 4)
        return 4;
    else
        return 0;
}

// For diplay
void Bingo::displayConstructor()
{
    // Start game
    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +-------+" << endl;
    colorGreen();
    cout << "\t\t\t\t\t  [";
    colorWHITE();
    cout << "1";
    colorGreen();
    cout << "]";
    colorBurgundy();
    cout << "\t   |";
    colorGreen();
    cout << " START ";
    colorBurgundy();
    cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +-------+" << endl
         << endl;

    // Score
    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +-------+" << endl;
    colorGreen();
    cout << "\t\t\t\t\t  [";
    colorWHITE();
    cout << "2";
    colorGreen();
    cout << "]";
    colorBurgundy();
    cout << "\t   |";
    colorGreen();
    cout << " SCORE ";
    colorBurgundy();
    cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +-------+" << endl
         << endl;

    // Exit
    colorBurgundy();
    cout << "\t\t\t\t\t\t   +------+" << endl;
    colorGreen();
    cout << "\t\t\t\t\t  [";
    colorWHITE();
    cout << "3";
    colorGreen();
    cout << "]";
    colorBurgundy();
    cout << "\t   |";
    colorRed();
    cout << " EXIT ";
    colorBurgundy();
    cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +------+" << endl
         << endl;
    colorWHITE();
}

void Bingo::playAgain()
{
    // Play Again?
    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +------------+" << endl;
    colorGreen();
    cout << "\t\t\t\t\t  [";
    colorWHITE();
    cout << "1";
    colorGreen();
    cout << "]";
    colorBurgundy();
    cout << "\t   |";
    colorGreen();
    cout << " PLAY AGAIN ";
    colorBurgundy();
    cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +------------+" << endl
         << endl;
    // EXIT
    colorBurgundy();
    cout << "\n\t\t\t\t\t\t   +------+" << endl;
    colorGreen();
    cout << "\t\t\t\t\t  [";
    colorWHITE();
    cout << "2";
    colorGreen();
    cout << "]";
    colorBurgundy();
    cout << "\t   |";
    colorGreen();
    cout << " EXIT ";
    colorBurgundy();
    cout << "|" << endl;
    cout << "\t\t\t\t\t\t   +------+" << endl
         << endl;
}



// Constructor
Bingo::Bingo() : userManager("users.txt")
{
    user = logIn();

    if (user != "0")
    {
        int n;
        do
        {
            displayConstructor();
            colorCyan();
            cout << "Choose: ";
            colorWHITE();
            integerValidation2(n);

            if (n == 1)
            {
                system("cls");
                colorMagenta();
                string name2;
                for (size_t i = 0; i < user.size(); i++)
                {
                    name2 += user[i];
                    if (i != user.size() - 1)
                    {
                        name2 += ' ';
                    }
                }

                cout << "\t\t\t\t\tW e l c o m e\t" << name2 << endl
                     << endl
                     << endl;
                colorWHITE();
                PlayGame();
                int i;
                do
                {
                    system("cls");
                    playAgain();
                    colorBlue();
                    cout << "Select: ";
                    integerValidation2(i);
                    colorWHITE();
                    if (i == 1)
                    {
                        system("cls");
                        displayLoadingBar();
                        system("cls");
                        colorMagenta();
                        cout << "\t\t\t\tW e l c o m e   B a c k   " << name2 << endl
                             << endl;
                        colorWHITE();
                        PlayGame();
                    }
                    else if (i == 2 || i == 3)
                    {
                        system("cls");
                        return;
                    }
                } while (i != 2 || i != 3);
            }
            else if (n == 2)
            {
                system("cls");
                displayScore();
                pressAnyKeyToContinue();
                system("cls");
            }
            else if (n == 3)
            {
                system("cls");
                return;
            }

        } while (n != 3);
    }
}

// Play Game Bingo
void Bingo::PlayGame()
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

    // For input random numbers by computer...
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
            cout << "Your Call number: ";
            colorWHITE();
            int index;
            while (1)
            {
                // cin >> calling;
                integerValidation(calling);

                // Finding the index of called number
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
            if (checkBingo(matrix1) == 2)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X ";
                colorGreen();
                cout << "\t N \t G \t O" << endl
                     << endl;
                check = 1;
            }
            if (checkBingo(matrix1) == 3)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X ";
                colorGreen();
                cout << "\t G \t O" << endl
                     << endl;
                check = 1;
            }
            if (check == 0)
            {
                colorGreen();
                cout << "\t\t\t\t  B ";
                cout << "\t I \t N \t G \t O" << endl
                     << endl;
                colorWHITE();
            }
            if (checkBingo(matrix1) == 4)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X \t X ";
                colorGreen();
                cout << "\t O" << endl
                     << endl;
            }
            display(matrix1);

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
            auto it2 = find(calledNumbers.begin(), calledNumbers.end(), calling);
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
                cout << "Computer: " << calledNumber << " called!" << endl;
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
            if (checkBingo(matrix1) == 2)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X ";
                colorGreen();
                cout << "\t N \t G \t O" << endl
                     << endl;
                check = 1;
            }
            if (checkBingo(matrix1) == 3)
            {
                check = 1;
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X ";
                colorGreen();
                cout << "\t G \t O" << endl
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
            if (checkBingo(matrix1) == 4)
            {
                colorBurgundy();
                cout << "\t\t\t\t  X \t X \t X \t X ";
                colorGreen();
                cout << "\t O" << endl
                     << endl;
            }
            display(matrix1);

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
            score += 1;
            userManager.updateScore(user, score);
            displayScore();
            score -= 1;
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
            score += 2;
            // cout << "Updating score for user: " << user << endl;
            userManager.updateScore(user, score);
            // userManager.getUserScore("user");
            displayScore();
            score -= 2; 
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

            displayScore();
            pressAnyKeyToContinue();
            system("cls");
            break;
        }

    }
}

void Bingo::displayLoadingBar()
{
    int totalSteps = 100;
    int width = 20;

    for (int progress = 0; progress <= totalSteps; progress++)
    {
        int pos = width * progress / totalSteps;
        string bar = "\033[32m" + string(pos, '=') + "\033[0m" + string(width - pos, ' ');
        cout << "\r[Loading] [" << bar << "] " << (progress * 100 / totalSteps) << "%";
        if (progress != totalSteps)
        {
            Sleep(100);

            cout << "\r[Loading] [" << string(20, ' ') << "] ";
            cout.flush();
        }
        progress += 3;
    }
    cout << endl;
}




