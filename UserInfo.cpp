#include"UserInfo.hh"



void UserManager::colorPurple()
{
    cout << "\033[38;5;129m";
}

void UserManager::colorRed()
{
    cout << "\033[1;31m";
}

void UserManager::colorGreen()
{
    cout << "\033[1;32m";
}

void UserManager::colorYellow()
{
    cout << "\033[1;33m";
}

void UserManager::colorBlue()
{
    cout << "\033[1;34m";
}

void UserManager::colorMagenta()
{
    cout << "\033[1;35m";
}

void UserManager::colorCyan()
{
    cout << "\033[1;36m";
}

void UserManager::colorPink()
{
    cout << "\033[38;5;206m";
}

void UserManager::colorBurgundy()
{
    cout << "\033[38;5;52m";
}

void UserManager::colorWHITE()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to default color
}

bool UserManager::checkUserExists(const string &username) const
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        if (line == username)
        {
            return true;
        }
        // Skip the next three lines, ensuring the file structure is intact
        for (int i = 0; i < 3; i++)
        {
            if (!getline(file, line))
                break;
        }
    }
    file.close();
    return false;
}




void UserManager::ensureFileExists(const string &filename) const
{
    // Try to open the file in read mode.
    ifstream file(filename);
    if (!file.is_open())
    {
        // File does not exist, so create it by opening in write mode.
        ofstream createFile(filename);
        createFile.close();
    }
    else
    {
        // File exists, close the opened file.
        file.close();
    }
}

bool UserManager::validateUser(const string &username, const string &password) const
{
    ifstream file(filename);
    string u, p;
    while (getline(file, u))
    {
        getline(file, p); // Read the password
        if (u == username && p == password)
        {
            file.close();
            return true;
        }
        // Skip score line and blank line
        getline(file, p); // Skip score
        getline(file, p); // Skip blank line
    }
    file.close();
    return false;
}


int UserManager::getUserScore(const string &username) const
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return -1;
    }

    string u, p;
    int score;
    while (getline(file, u))
    {
        getline(file, p); // Read the password
        file >> score;    // Read the score
        file.ignore();    // Skip to the next line after reading the score
        getline(file, p); // Read the blank line

        if (u == username)
        {
            file.close();
            return score;
        }
    }
    file.close();
    return -1; // User not found
}



void UserManager::updateScore(const string &username, int pointsToAdd) const
{
    // Define a temporary file name.
    string tempFileName = "temp.txt";
    ofstream tempFile(tempFileName, ios::app);
    ifstream file(filename);

    if (!file.is_open() || !tempFile.is_open())
    {
        cerr << "Failed to open file(s)." << endl;
        return;
    }

    string u, p;
    int score;
    bool found = false;

    while (getline(file, u))
    {
        getline(file, p); // Read the password
        if (!(file >> score)) // Properly read the score
        {
            cerr << "Error reading score for user " << u << endl;
            continue; // Skip this record if the score is not readable
        }
        file.ignore(); // Skip to the next line after reading the score
        string blank;
        getline(file, blank); // Read the blank line to maintain format

        if (u == username)
        {
            score += pointsToAdd; // Increment the score by pointsToAdd
            found = true;
        }

        // Write updated data to temp file
        tempFile << u << endl
                    << p << endl
                    << score << endl
                    << endl; // Maintain the blank line for separation
    }

    file.close();
    tempFile.close();

    // Replace the old file with the new file
    remove(filename.c_str());
    rename(tempFileName.c_str(), filename.c_str());

    if (found)
        
        cout << "Score updated successfully for " << username << "." << endl;
    else
        cout << "User not found." << endl;
}



void UserManager::displayLoadingBar()
{
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


void UserManager::signUp()
{
    string username, password;
    colorGreen();
    cout << "\t\t\t\t\tUsername: ";
    colorCyan();
    cin >> username;
    colorWHITE();
    if (checkUserExists(username))
    {
        system("cls");
        displayLoadingBar();
        colorRed();
        cout << "Username already exists. Try logging in." << endl;
        colorWHITE();
        return;
    }
    colorGreen();
    cout << "\t\t\t\t\tPassword: ";
    colorRed();
    cin >> password;
    system("cls");
    displayLoadingBar();
    saveUser(username, password);
    colorGreen();
    cout << "User registered successfully!" << endl;
    colorWHITE();
}


void UserManager::loadAndDisplayLeaderboard()
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    vector<UserData> users;
    string username, password;
    int score;

    while (getline(file, username))
    {
        getline(file, password);
        file >> score;
        file.ignore();           // Skip to the next line after reading the score
        getline(file, password); // Read the blank line
        users.emplace_back(username, score);
    }
    file.close();

    // Sort users by score in descending order
    sort(users.begin(), users.end());

    // Display the top 3 scores
    colorRed();
    cout << "\t\t\t\t\tT o p   3  S c o r e s" << endl << endl;
    colorGreen();
    for (int i = 0; i < 3 && i < users.size(); ++i)
    {
        cout << "\t\t\t\t\t" << i + 1 << ". " << users[i].username << " - " << users[i].score << endl << endl;
    }
    colorWHITE();
}
