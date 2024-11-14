#include <iostream> //  This library provides input and output stream functionality, including cin and cout, for reading from and writing to the console.
#include <conio.h> // This library provides functions for console input/output operations, including getch() which reads a single character directly from the console without echoing it.
#include <windows.h> // This library provides functions and constants for Windows operating system programming, including console manipulation, system calls, and various other Windows-specific features.
#include <string> // This library provides the string class and various functions for working with strings, such as concatenation, substring extraction, searching, and manipulation.
#include <vector> //  This library provides the vector container class, which represents a dynamic array, allowing you to store and manipulate sequences of objects.
#include <limits> // This library provides constants and functions for working with the limits of numeric types, such as the maximum and minimum values that can be stored.
#include <algorithm> // This library provides a collection of functions for performing common algorithms on sequences of elements, such as sorting, searching, and modifying.
#include <cctype>    // This library provides functions for character handling, such as converting characters to lowercase or uppercase using tolower and toupper functions.

using namespace std;

bool goBackToMenu = false; // Variable to control whether to go back to the menu

// Structure to store user information
struct User {
    string name;
    string age;
    string weight;
    string height;
};

// Structure to store exercise information
struct Exercise {
    string name;
    string description;
    double caloriesPerMinute;
};

// Function to remove leading and trailing whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == string::npos || last == string::npos)
        return "";
    return str.substr(first, (last - first + 1));
}


vector<User> users; // Vector to store user data
vector<Exercise> exercises; // Vector to store exercise data

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any remaining characters in the input buffer
}

void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void AddExercise() {
    Exercise exercise;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t      ,---.  ,------.  ,------.      ,------.,--.   ,--.,------.,------.  ,-----.,--. ,---.  ,------. \n";
    cout << "\t\t\t\t\t\t\t     /  O  \\ |  .-.  \\ |  .-.  \\     |  .---' \\  `.'  / |  .---'|  .--. ''  .--./|  |'   .-' |  .---' \n";
    cout << "\t\t\t\t\t\t\t    |  .-.  ||  |  \\  :|  |  \\  :    |  `--,   .'    \\  |  `--, |  '--'.'|  |    |  |`.  `-. |  `--,  \n";
    cout << "\t\t\t\t\t\t\t    |  | |  ||  '--'  /|  '--'  /    |  `---. /  .'.  \\ |  `---.|  |\\  \\ '  '--'\\|  |.-'    ||  `---. \n";
    cout << "\t\t\t\t\t\t\t    `--' `--'`-------' `-------'     `------''--'   '--'`------'`--' '--' `-----'`--'`-----' `------' \n";
    cout << "\n\n\n\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t\tEnter exercise name: ";
    getline(cin, exercise.name);

    cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter exercise description for  " << exercise.name << ": ";
    getline(cin, exercise.description);

    cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter calories burned per minute: ";
    cin >> exercise.caloriesPerMinute;

    exercises.push_back(exercise);
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise added successfully!" << endl;

    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAdd another exercise? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cin.ignore(); // Ignore the remaining newline character
        AddExercise();
    } else {
    }
}

void UpdateExercise() {
    string exerciseName;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t,--. ,--.,------. ,------.    ,---. ,--------.,------.    ,------.,--.   ,--.,------.,------.  ,-----.,--. ,---.  ,------. \n";
    cout << "\t\t\t\t\t\t|  | |  ||  .--. '|  .-.  \\  /  O  \\'--.  .--'|  .---'    |  .---' \\  `.'  / |  .---'|  .--. ''  .--./|  |'   .-' |  .---' \n";
    cout << "\t\t\t\t\t\t|  | |  ||  '--' ||  |  \\  :|  .-.  |  |  |   |  `--,     |  `--,   .'    \\  |  `--, |  '--'.'|  |    |  |`.  `-. |  `--,  \n";
    cout << "\t\t\t\t\t\t'  '-'  '|  | --' |  '--'  /|  | |  |  |  |   |  `---.    |  `---. /  .'.  \\ |  `---.|  |\\  \\ '  '--'\\|  |.-'    ||  `---. \n";
    cout << "\t\t\t\t\t\t `-----' `--'     `-------' `--' `--'  `--'   `------'    `------''--'   '--'`------'`--' '--' `-----'`--'`-----' `------' \n";
    cout << "\n\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter exercise name to update: ";
    getline(cin, exerciseName);

    // Search for the exercise by name
    int index = -1;
    for (int i = 0; i < exercises.size(); i++) {
        if (exercises[i].name == exerciseName) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        Exercise& exercise = exercises[index];
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new exercise name: ";
        getline(cin, exercise.name);

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new exercise description: ";
        getline(cin, exercise.description);

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new calories burned per minute: ";
        cin >> exercise.caloriesPerMinute;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise updated successfully!" << endl;
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise not found!" << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    char choice;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tDo you want to update another exercise? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining newline character
        UpdateExercise(); // Recursive call to update another exercise
    } else {
        // Exit the function
    }
}

void GetExercise() {
    string exerciseName;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t ,----.   ,------.,--------.    ,------.,--.   ,--.,------.,------.  ,-----.,--. ,---.  ,------. \n";
    cout << "\t\t\t\t\t\t\t'  .-./   |  .---''--.  .--'    |  .---' \\  `.'  / |  .---'|  .--. ''  .--./|  |'   .-' |  .---' \n";
    cout << "\t\t\t\t\t\t\t|  | .---.|  `--,    |  |       |  `--,   .'    \\  |  `--, |  '--'.'|  |    |  |`.  `-. |  `--,  \n";
    cout << "\t\t\t\t\t\t\t'  '--'  ||  `---.   |  |       |  `---. /  .''.  \\|  `---.|  |\\  \\ '  '--'\\|  |.-'    ||  `---. \n";
    cout << "\t\t\t\t\t\t\t `------' `------'   `--'       `------''--'   '--'`------'`--' '--' `-----'`--'`-----' `------' \n";
    cout << "\n\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter exercise name to get: ";
    getline(cin, exerciseName);

    // Search for the exercise by name
    int index = -1;
    for (int i = 0; i < exercises.size(); i++) {
        if (exercises[i].name == exerciseName) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        Exercise exercise = exercises[index];

        // Prompt for new exercise details
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise Name: " << exercise.name << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDescription: " << exercise.description << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tCalories burned per minute: " << exercise.caloriesPerMinute << endl;
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise not found!" << endl;
    }
       char choice;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tDo you want to get another exercise? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cin.ignore(); // Ignore the remaining newline character
        GetExercise(); // Recursive call to start another workout
    } else {
    }
}


void CountCalorieIntake() {
    system("cls");
    int calorieIntake = 0;
    int foodCount = 0;
    cout << "\n\n\n\n\n";
    cout << "\t\t\t ,-----.        ,--.              ,--.           ,--.          ,--.          ,--.               ,-----.        ,--.              ,--.          ,--.                 \n";
    cout << "\t\t\t'  .--./ ,--,--.|  | ,---. ,--.--.`--' ,---.     |  |,--,--, ,-'  '-. ,--,--.|  |,-. ,---.     '  .--./ ,--,--.|  | ,---.,--.,--.|  | ,--,--.,-'  '-. ,---. ,--.--. \n";
    cout << "\t\t\t|  |    ' ,-.  ||  || .-. ||  .--',--.| .-. :    |  ||      \\'-.  .-'' ,-.  ||     /| .-. :    |  |    ' ,-.  ||  || .--'|  ||  ||  |' ,-.  |'-.  .-'| .-. ||  .--' \n";
    cout << "\t\t\t'  '--'\\\\ '-'  ||  |' '-' '|  |   |  |\\   --.    |  ||  ||  |  |  |  \\ '-'  ||  \\|  \\   --.    '  '--'\\ '-'   ||  |\\ `--.'  ''  '|  |\\ '-'  |  |  |  ' '-' '|  |    \n";
    cout << "\t\t\t `-----' `--`--'`--' `---' `--'   `--' `----'    `--'`--''--'  `--'   `--`--'`--'`--'`----'     `-----' `--`--'`--' `---' `----' `--' `--`--'  `--'   `---' `--'    \n";
    cout << "\n\n\n\n";

    cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter the number of food items: ";
    cin >> foodCount;

    while (foodCount <= 0) {
        cout << "\n\t\t\t\t\t\t\t\t\t\tInvalid input! Enter a positive number: ";
        cin >> foodCount;
    }

    for (int i = 1; i <= foodCount; ++i) {
        int calories;

        cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter the calories for food item " << i << ": ";
        cin >> calories;

        while (calories < 0) {
            cout << "\n\t\t\t\t\t\t\t\t\t\tInvalid input! Enter a non-negative number: ";
            cin >> calories;
        }

        calorieIntake += calories;
    }

    cout << "\n\n\t\t\t\t\t\t\t\t\t\tTotal calorie intake: " << calorieIntake << " calories" << endl;

    char choice;
    cout << "\n\n\t\t\t\t\t\t\t\t\tDo you want to count calorie intake again? (Y/N): ";
    cin >> choice;

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        cout << "\n\t\t\t\t\t\t\t\t\tInvalid input! Enter Y/y or N/n: ";
        cin >> choice;
    }

    if (choice == 'Y' || choice == 'y') {
        CountCalorieIntake(); // Repeat the calorie counting
    } else {
        // Exit the function
    }
}

void DeleteExercise() {
    bool deleteAnother = true;
    string exerciseName;

    while (deleteAnother) {
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t ,------.  ,------.,--.   ,------.,--------.,------.    ,------.,--.   ,--.,------.,------.  ,-----.,--. ,---.  ,------.\n";
        cout << "\t\t\t\t\t\t|  .-.  \\ |  .---'|  |   |  .---''--.  .--'|  .---'    |  .---' \\  `.'  / |  .---'|  .--. ''  .--./|  |'   .-' |  .---'\n";
        cout << "\t\t\t\t\t\t|  |  \\  :|  `--, |  |   |  `--,    |  |   |  `--,     |  `--,   .'    \\  |  `--, |  '--'.'|  |    |  |`.  `-. |  `--, \n";
        cout << "\t\t\t\t\t\t|  '--'  /|  `---.|  '--.|  `---.   |  |   |  `---.    |  `---. /  .'.  \\ |  `---.|  |\\  \\ '  '--'\\|  |.-'    ||  `---. \n";
        cout << "\t\t\t\t\t\t`-------' `------'`-----'`------'   `--'   `------'    `------''--'   '--'`------'`--' '--' `-----'`--'`-----' `------'\n";
        cout << "\n\n\n\n";


        cout << "\t\t\t\t\t\t\t\t\t\t\tEnter exercise name to delete: ";
        getline(cin, exerciseName);

        // Search for the exercise by name
        int index = -1;
        for (int i = 0; i < exercises.size(); i++) {
            if (exercises[i].name == exerciseName) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "\n\n\t\t\t\t\t\t\t\t\t\tAre you sure you want to delete the exercise \"" << exerciseName << "\"? (Y/N): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                exercises.erase(exercises.begin() + index);
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise deleted successfully!" << endl;
            } else {
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDeletion canceled." << endl;
            }
        } else {
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise not found!" << endl;
        }

        // Ask if the user wants to delete another exercise
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tDo you want to delete another exercise? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice != 'Y' && choice != 'y') {
            deleteAnother = false;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }

    // Clear the remaining newline character after the loop
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
}


void StartWorkout() {
    string userName;
    string exerciseName;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t ,---. ,--------. ,---.  ,------. ,--------.    ,--.   ,--. ,-----. ,------. ,--. ,--. ,-----. ,--. ,--.,--------. \n";
    cout << "\t\t\t\t\t\t'   .-''--.  .--'/  O  \\ |  .--. ''--.  .--'    |  |   |  |'  .-.  '|  .--. '|  .'   /'  .-.  '|  | |  |'--.  .--' \n";
    cout << "\t\t\t\t\t\t`.  `-.   |  |  |  .-.  ||  '--'.'   |  |       |  |.'.|  ||  | |  ||  '--'.'|  .   ' |  | |  ||  | |  |   |  |    \n";
    cout << "\t\t\t\t\t\t.-'    |  |  |  |  | |  ||  |\\  \\    |  |       |   ,'.   |'  '-'  '|  |\\  \\ |  |\\   \\'  '-'  ''  '-'  '   |  |    \n";
    cout << "\t\t\t\t\t\t`-----'   `--'  `--' `--'`--' '--'   `--'       '--'   '--' `-----' `--' '--'`--' '--' `-----'  `-----'    `--'    \n";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter your name: ";
    cin.ignore(); // Clear the input buffer before reading name
    getline(cin, userName);
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter exercise name: ";
    getline(cin, exerciseName);

    Exercise selectedExercise;
    bool exerciseFound = false;

       // Search for the exercise by name
    for (const Exercise& exercise : exercises) {
        if (exercise.name == exerciseName) {
            selectedExercise = exercise;
            exerciseFound = true;
            break;
        }
    }

    if (exerciseFound) {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tWorkout started for user: " << userName << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tExercise: " << selectedExercise.name << endl;

        double caloriesBurned = 0.0;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter exercise duration (in minutes): ";
        double duration;
        cin >> duration;

        cin.ignore(); // Ignore the remaining newline character

        caloriesBurned = selectedExercise.caloriesPerMinute * duration;

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tWorkout ended." << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tCalories burned: " << caloriesBurned << endl;
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tInvalid exercise name!" << endl;
    }

    char choice;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDo you want to start another workout? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cin.ignore(); // Ignore the remaining newline character
        StartWorkout(); // Recursive call to start another workout
    } else {
    }
}

void AddUser() {
    char choice;
    do {
        User user;
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t  ,---.  ,------.  ,------.      ,--. ,--. ,---.  ,------.,------.  \n";
        cout << "\t\t\t\t\t\t\t\t\t /  O  \\ |  .-.  \\ |  .-.  \\     |  | |  |'   .-' |  .---'|  .--. ' \n";
        cout << "\t\t\t\t\t\t\t\t\t|  .-.  ||  |  \\  :|  |  \\  :    |  | |  |`.  `-. |  `--, |  '--'.' \n";
        cout << "\t\t\t\t\t\t\t\t\t|  | |  ||  '--'  /|  '--'  /    '  '-'  '.-'    ||  `---.|  |\\  \\  \n";
        cout << "\t\t\t\t\t\t\t\t\t`--' `--'`-------' `-------'      `-----' `-----' `------'`--' '--' \n";
        cout << "\n\n\n\n\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t\tEnter Name: ";
        getline(cin, user.name);

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter user age: ";
        cin >> user.age;
        clearInputBuffer();

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter user weight (in kg): ";
        cin >> user.weight;
        clearInputBuffer();

        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter user height (in cm): ";
        cin >> user.height;
        clearInputBuffer();
        users.push_back(user);

        // Display the entered values
        system("cls");
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t ,--.   ,--.,------.,--.    ,-----. ,-----. ,--.   ,--.,------.    ,--.  ,--.,------.,--.   ,--.    ,--. ,--. ,---.  ,------.,------.  \n";
        cout << "\t\t\t\t\t |  |   |  ||  .---'|  |   '  .--./'  .-.  '|   `.'   ||  .---'    |  ,'.|  ||  .---'|  |   |  |    |  | |  |'   .-' |  .---'|  .--. ' \n";
        cout << "\t\t\t\t\t |  |.'.|  ||  `--, |  |   |  |    |  | |  ||  |'.'|  ||  `--,     |  |' '  ||  `--, |  |.'.|  |    |  | |  |`.  `-. |  `--, |  '--'.' \n";
        cout << "\t\t\t\t\t |   ,'.   ||  `---.|  '--.'  '--'\\\\  '-'  '|  |   |  ||  `---.    |  | `   ||  `---.|   ,'.   |    '  '-'  '.-'    ||  `---.|  |\\  \\  \n";
        cout << "\t\t\t\t\t '--'   '--'`------'`-----' `-----' `-----' `--'   `--'`------'    `--'  `--'`------''--'   '--'     `-----' `-----' `------'`--' '--' \n";
        cout << "\n\n\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t\tName: " << user.name << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAge: " << user.age << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tWeight: " << user.weight << " kg" << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tHeight: " << user.height << " cm" << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tUser added successfully!" << endl;

        // Prompt for going back to the menu
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tDo you want to add another User? (Y/N): ";
        cin >> choice;
        clearInputBuffer();

    } while (choice == 'Y' || choice == 'y');
}

void displayUserPage() {
    system("cls");
    int menuChoice = 1;
    char key;

    while (true) {
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t,--.   ,--.,------.,--.    ,-----. ,-----. ,--.   ,--.,------. " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|  |   |  ||  .---'|  |   '  .--./'  .-.  '|   `.'   ||  .---' " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|  |.'.|  ||  `--, |  |   |  |    |  | |  ||  |'.'|  ||  `--,  " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t|   ,'.   ||  `---.|  '--.'  '--'\\'  '-'  '|  |   |  ||  `---. " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t'--'   '--'`------'`-----' `-----' `-----' `--'   `--'`------' " << endl;
        cout << "\n\n\n";


        switch (menuChoice) {
            case 1:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 2:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 3:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 4:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 5:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 6:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 7:
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Add Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Get Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete Exercise" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Count Your Calorie Intake" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Start Workout" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Log out" << endl;
                break;
        }

        key = _getch();

        if (key == 7) { // Backspace key is pressed
            if (menuChoice > 1) {
                menuChoice--; // Decrement the menu choice
            }
        } else if (key == 13) { // Enter key is pressed
            switch (menuChoice) {
                case 1:
                    cin.ignore();
                    AddExercise();
                    break;
                case 2:
                    cin.ignore();
                    UpdateExercise();
                    break;
                case 3:
                    cin.ignore();
                    GetExercise();
                    break;
                case 4:
                    cin.ignore();
                    DeleteExercise();
                    break;
                case 5:
                    cin.ignore();
                    CountCalorieIntake();
                    break;
                case 6:
                    StartWorkout();
                    break;
                case 7:
                    break;
            }

            if (menuChoice != 7) {
                _getch();
            } else {
                break; // Exit the loop and go back to the main menu
            }
        } else if (key == 80 && menuChoice < 7) { // Down arrow key is pressed
            menuChoice++; // Increment the menu choice
        } else if (key == 72 && menuChoice > 1) { // Up arrow key is pressed
            menuChoice--; // Decrement the menu choice
        }
    }
    // Comment: This function displays the user page with menu options and allows the user to navigate through the options using arrow keys and make a selection by pressing Enter.
}

void LoginUser() {
    string name;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t ,--.    ,-----.  ,----.   ,--.,--.  ,--. " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t |  |   '  .-.  ''  .-./   |  ||  ,'.|  | " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t |  |   |  | |  ||  | .---.|  ||  |' '  | " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t |  '--.'  '-'  ''  '--'  ||  ||  | `   | " << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t `-----' `-----'  `------' `--'`--'  `--' " << endl;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tEnter Username: ";
    getline(cin, name);

    // Remove leading and trailing whitespace from the name
    name = trim(name);

    // Convert name to lowercase
    transform(name.begin(), name.end(), name.begin(), [](unsigned char c) {
        return tolower(c);
    });

    bool found = false;
    for (const auto& user : users) {
        string userName = user.name;

        // Remove leading and trailing whitespace from the userName
        userName = trim(userName);

        // Convert userName to lowercase
        transform(userName.begin(), userName.end(), userName.begin(), [](unsigned char c) {
            return tolower(c);
        });

        if (userName == name) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tUser logged in successfully!\n";
        // Call the function for the next page
        displayUserPage();
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t   User not found!\n";
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Try again? (Y/N): ";
        char choice;
        cin >> choice;
        clearInputBuffer();
        if (choice == 'Y' || choice == 'y') {
            LoginUser();
        } else {
            // Go back or perform other actions
        }
    }
}

void Login (){
     int menuChoice = 1;
    char key;

    while (true) {
        system("cls");

        // Display menu options
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t   ,--.   ,--.,------.,--.    ,-----. ,-----. ,--.   ,--.,------.   " << endl;
        cout << "\t\t\t\t\t\t\t\t\t   |  |   |  ||  .---'|  |   '  .--./'  .-.  '|   `.'   ||  .---'  " << endl;
        cout << "\t\t\t\t\t\t\t\t\t   |  |.'.|  ||  `--, |  |   |  |    |  | |  ||  |'.'|  ||  `--,   " << endl;
        cout << "\t\t\t\t\t\t\t\t\t   |   ,'.   ||  `---.|  '--.'  '--'\\'  '-'  '|  |   |  ||  `---. " << endl;
        cout << "\t\t\t\t\t\t\t\t\t   '--'   '--'`------'`-----' `-----' `-----' `--'   `--'`------'  " << endl;


        switch (menuChoice) {
            case 1:
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> LOGIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   CREATE ACCOUNT\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   BACK TO MENU\n";
                break;
            case 2:
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   LOGIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> CREATE ACCOUNT\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   BACK TO MENU\n";
                break;
            case 3:
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   LOGIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   CREATE ACCOUNT\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> BACK TO MENU\n";
                break;
                 }

        key = _getch();

        if (key == 13) { // Enter key is pressed
            switch (menuChoice) {
                case 1:
                    cin.ignore();
                    LoginUser();
                    break;
                case 2:
                    cin.ignore();
                    AddUser();
                    break;
                case 3:
                    goBackToMenu = true;
                    break;
            }

            if (menuChoice != 3) {
                _getch();
            } else {
                break; // Exit the loop and go back to the main menu
            }
                }
        else if (key == 80 && menuChoice < 3) { // Down arrow key is pressed
            menuChoice++; // Increment the menu choice
                    }
        else if (key == 72 && menuChoice > 1) { // Up arrow key is pressed
            menuChoice--; // Decrement the menu choice
        }
    }

}


void DeleteUser() {
    string username;
    system("cls");
    bool deleteAnother = true;

    while (deleteAnother) {
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t,------.  ,------.,--.   ,------.,--------.,------.    ,--. ,--. ,---.  ,------.,------.  \n";
    cout << "\t\t\t\t\t\t\t\t|  .-.  \\ |  .---'|  |   |  .---''--.  .--'|  .---'    |  | |  |'   .-' |  .---'|  .--. ' \n";
    cout << "\t\t\t\t\t\t\t\t|  |  \\  :|  `--, |  |   |  `--,    |  |   |  `--,     |  | |  |`.  `-. |  `--, |  '--'.' \n";
    cout << "\t\t\t\t\t\t\t\t|  '--'  /|  `---.|  '--.|  `---.   |  |   |  `---.    '  '-'  '.-'    ||  `---.|  |\\  \\  \n";
    cout << "\t\t\t\t\t\t\t\t`-------' `------'`-----'`------'   `--'   `------'     `-----' `-----' `------'`--' '--' \n";
    cout << "\n\n\n\n\n\n";


        cout << "\t\t\t\t\t\t\t\t\t\t\tEnter user name to delete: ";
        cin.ignore(); // Clear the input buffer before reading name
        getline(cin, username);

        // Search for the user by name
        bool found = false;
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->name == username) {
                // User found
                cout << "\n\n\t\t\t\t\t\t\t\t\t\tAre you sure you want to delete the user '" << it->name << "'? (y/n): ";
                char choice;
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    users.erase(it);
                    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tUser deleted successfully!" << endl;
                } else {
                    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tUser deletion canceled." << endl;
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tUser not found!" << endl;
        }

        // Ask if the user wants to delete another account
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDo you want to delete another user? (y/n): ";
        char choice;
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            deleteAnother = false;
        }


    }

}


void GetUser() {
    string username;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t ,----.   ,------.,--------.    ,--. ,--. ,---.  ,------.,------.  \n";
    cout << "\t\t\t\t\t\t\t\t\t'  .-./   |  .---''--.  .--'    |  | |  |'   .-' |  .---'|  .--. ' \n";
    cout << "\t\t\t\t\t\t\t\t\t|  | .---.|  `--,    |  |       |  | |  |`.  `-. |  `--, |  '--'.' \n";
    cout << "\t\t\t\t\t\t\t\t\t'  '--'  ||  `---.   |  |       '  '-'  '.-'    ||  `---.|  |\\  \\  \n";
    cout << "\t\t\t\t\t\t\t\t\t `------' `------'   `--'        `-----' `-----' `------'`--' '--' \n";
    cout << "\n\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter user name to get: ";
    cin.ignore(); // Clear the input buffer before reading name
    getline(cin, username);

    // Search for the user by name
    bool found = false;
    for (const User& user : users) {
        if (user.name == username) {
            // User found
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tUser Name: " << user.name << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAge: " << user.age << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tWeight: " << user.weight << " kg" << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tHeight: " << user.height << " cm" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tUser not found!" << endl;
    }

    char choice;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDo you want to search for another user? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cin.ignore(); // Ignore the remaining newline character
        GetUser(); // Recursive call
    } else {
    }
}

void UpdateUser() {
    string username;
    string art = "\n\n\n\n\n"
                "\t\t\t\t\t\t\t\t ,--. ,--.,------. ,------.    ,---. ,--------.,------.    ,--. ,--. ,---.  ,------.,------.  \n"
                "\t\t\t\t\t\t\t\t|  | |  ||  .--. '|  .-.  \\  /  O  \\'--.  .--'|  .---'    |  | |  |'   .-' |  .---'|  .--. ' \n"
                "\t\t\t\t\t\t\t\t|  | |  ||  '--' ||  |  \\  :|  .-.  |  |  |   |  `--,     |  | |  |`.  `-. |  `--, |  '--'.' \n"
                "\t\t\t\t\t\t\t\t'  '-'  '|  | --' |  '--'  /|  | |  |  |  |   |  `---.    '  '-'  '.-'    ||  `---.|  |\\  \\  \n"
                "\t\t\t\t\t\t\t\t `-----' `--'     `-------' `--' `--'  `--'   `------'     `-----' `-----' `------'`--' '--' \n"
                "\n\n\n\n";

    bool updateAnother = true;

    while (updateAnother) {
        system("cls");
        cout << art;

        cout << "\t\t\t\t\t\t\t\t\t\t\tEnter user name to update: ";
        cin.ignore(); // Clear the input buffer before reading name
        getline(cin, username);

        // Search for the user by name
        bool found = false;
        for (auto& user : users) {
            if (user.name == username) {
                // User found
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new user name: ";
                cin >> user.name;
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new user age: ";
                cin >> user.age;
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new user weight (in kg): ";
                cin >> user.weight;
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tEnter new user height (in cm): ";
                cin >> user.height;
                cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tUser updated successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tUser not found!" << endl;
        }

        // Ask if the user wants to update another user
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDo you want to update another user? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice != 'Y' && choice != 'y') {
            updateAnother = false;
        }

    }
}


void displayAdminPage() {
    system("cls");
      system("cls");
    int menuChoice = 1;
    char key;

    while (true) {
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t,--.   ,--.,------.,--.    ,-----. ,-----. ,--.   ,--.,------.      ,---.  ,------.  ,--.   ,--.,--.,--.  ,--." << endl;
        cout << "\t\t\t\t\t\t\t|  |   |  ||  .---'|  |   '  .--./'  .-.  '|   `.'   ||  .---'     /  O  \\ |  .-.  \\ |   `.'   ||  ||  ,'.|  |" << endl;
        cout << "\t\t\t\t\t\t\t|  |.'.|  ||  `--, |  |   |  |    |  | |  ||  |'.'|  ||  `--,     |  .-.  ||  |  \\  :|  |'.'|  ||  ||  |' '  |" << endl;
        cout << "\t\t\t\t\t\t\t|   ,'.   ||  `---.|  '--.'  '--'\\'  '-'  '|  |   |  ||  `---.    |  | |  ||  '--'  /|  |   |  ||  ||  | `   |" << endl;
        cout << "\t\t\t\t\t\t\t'--'   '--'`------'`-----' `-----' `-----' `--'   `--'`------'    `--' `--'`-------' `--'   `--'`--'`--'  `--'" << endl;
        cout << "\n\n\n\n";

        switch (menuChoice) {
            case 1:
                cout << "\t\t\t\t\t\t\t\t\t\t\t\t-> Get User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 2:
                cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Get User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Update User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 3:
                cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Get User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Delete User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Log out" << endl;
                break;
            case 4:
                cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Get User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Update User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Delete User" << endl;
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> Log out" << endl;
                break;

        }

        key = _getch();


        if (key == 13) { // Enter key is pressed
            switch (menuChoice) {
                case 1:
                    GetUser();
                    break;
                case 2:
                    UpdateUser();
                    break;
                case 3:
                    DeleteUser();
                    break;
                case 4:
                    goBackToMenu = true;
                    break;
                }
            if (menuChoice != 4) {
                _getch();
            } else {
                break; // Exit the loop and go back to the main menu
            }
        }
            if (key == 80 && menuChoice < 4) { // Down arrow key is pressed
            menuChoice++; // Increment the menu choice
        } else if (key == 72 && menuChoice > 1) { // Up arrow key is pressed
            menuChoice--; // Decrement the menu choice
        }
    }

}

void AdminLogin() {
    system("cls");
    string username;
    string password;
    bool isAdmin = false;
    char choice;

    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t   ,---.  ,------.  ,--.   ,--.,--.,--.  ,--.,--. ,---. ,--------.,------.   ,---. ,--------. ,-----. ,------.  " << endl;
    cout << "\t\t\t\t\t\t  /  O  \\ |  .-.  \\ |   `.'   ||  ||  ,'.|  ||  |'   .-''--.  .--'|  .--. ' /  O  \\ '--.  .--''  .-.  '|  .--. ' " << endl;
    cout << "\t\t\t\t\t\t |  .-.  ||  |  \\  :|  |'.'|  ||  ||  |' '  ||  |`.  `-.   |  |   |  '--'.'|  .-.  |   |  |   |  | |  ||  '--'.' " << endl;
    cout << "\t\t\t\t\t\t |  | |  ||  '--'  /|  |   |  ||  ||  | `   ||  |.-'    |  |  |   |  |\\  \\ |  | |  |   |  |   '  '-'  '|  |\\  \\  " << endl;
    cout << "\t\t\t\t\t\t `--' `--'`-------' `--'   `--'`--'`--'  `--'`--'`-----'   `--'   `--' '--'`--' `--'   `--'    `-----' `--' '--' " << endl;
    cout << "\n\n\n\n\n\n   \t\t\t\t\t\t\t\t\t\t\tEnter the username: ";
    cin >> username;

    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter the password: ";

    // Mask the input with asterisks
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password.push_back(ch);
        }
    }

    // Check if the username and password are correct
    if (username == "admin" && password == "admin") {
        isAdmin = true;
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\tAccess granted. You are logged in as admin." << endl;
        displayAdminPage();
    } else {
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tAccess denied. Incorrect username or password." << endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t   Try again? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            AdminLogin();
        } else {

        }
    }
}

void displayFitnessPage() {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t       ,------.,--.,--------.,--.  ,--.,------. ,---.   ,---." <<endl;
    cout << "\t\t\t\t\t\t\t\t\t       |  .---'|  |'--.  .--'|  ,'.|  ||  .---''   .-' '   .-'" <<endl;
    cout << "\t\t\t\t\t\t\t\t\t       |  `--, |  |   |  |   |  |' '  ||  `--, `.  `-. `.  `-." <<endl;
    cout << "\t\t\t\t\t\t\t\t\t       |  |`   |  |   |  |   |  | `   ||  `---..-'    |.-'    |" <<endl;
    cout << "\t\t\t\t\t\t\t\t\t       `--'    `--'   `--'   `--'  `--'`------'`-----' `-----'\n" <<endl;
    cout << "\t\t\t________________________________________________________________________________________________________________________________________________________________";
    cout << "\n\t\t\t|                                                                                                                                                               |";
    cout << "\n\t\t\t|                                                                             FITNESS                                                                           |";
    cout << "\n\t\t\t|                                                                                                                                                               |";
    cout << "\n\t\t\t| Fitness refers to the state of being physically and mentally healthy and well-conditioned. It involves the overall well-being and ability of an individual    |";
    cout << "\n\t\t\t| to perform physical activities and withstand various challenges. Fitness encompasses multiple components, including cardiovascular endurance, muscular        |";
    cout << "\n\t\t\t| strength and endurance, flexibility, and body composition.                                                                                                    |";
    cout << "\n\t\t\t|                                                                                                                                                               |";
    cout << "\n\t\t\t| Engaging in regular exercise and maintaining a balanced and nutritious diet are essential for achieving and maintaining fitness. Exercise activities can      |";
    cout << "\n\t\t\t| include aerobic exercises, strength training, flexibility exercises, and other forms of physical activity.                                                    |";
    cout << "\n\t\t\t|                                                                                                                                                               |";
    cout << "\n\t\t\t| Fitness offers numerous benefits, both physically and mentally. It helps improve cardiovascular health, strengthen muscles and bones, enhance flexibility,    |";
    cout << "\n\t\t\t| manage weight, boost energy levels, reduce the risk of chronic diseases, improve sleep quality, and enhance mental well-being.                                |";
    cout << "\n\t\t\t|                                                                                                                                                               |";
    cout << "\n\t\t\t| Individual fitness goals can vary depending on personal preferences, health objectives, and lifestyle factors. It's important to consult with healthcare      |";
    cout << "\n\t\t\t| professionals or fitness experts to develop appropriate exercise and nutrition plans based on specific needs and goals.                                       |";
    cout << "\n\t\t\t|                                                                                                                                                               |";
    cout << "\n\t\t\t|_______________________________________________________________________________________________________________________________________________________________|";

    cout << "\n\n\t\t\t\t\t\t\t\t\t\tPress Backspace to go back to the previous page.\n";

    while (true) {
        char key = _getch();

        if (key == 8) {
            goBackToMenu = true;
            break;
        }
    }
}


void displaySoftwareDevelopersPage() {
  int currentPage = 1;
            char key;

    while (true)
    {
        system("cls"); // Clear the console screen
        // Display the current developer page
        if (currentPage == 1)
        {
            setColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t,------.  ,------.,--.   ,--.,------.,--.    ,-----. ,------. ,------.,------.  ,---.";
    cout << "\n\t\t\t\t\t\t\t\t|  .-.  \\ |  .---' \\  `.'  / |  .---'|  |   '  .-.  '|  .--. '|  .---'|  .--. ''   .-'";
    cout << "\n\t\t\t\t\t\t\t\t|  |  \   :|  `--,   \\     /  |  `--, |  |   |  | |  ||  '--' ||  `--, |  '--'.'`.  `-.";
    cout << "\n\t\t\t\t\t\t\t\t|  '--'  /|  `---.   \\   /   |  `---.|  '--.'  '-'  '|  | --' |  `---.|  |\\  \\ .-'    |";
    cout << "\n\t\t\t\t\t\t\t\t`-------' `------'    `-'    `------'`-----' `-----' `--'     `------'`--' '--'`-----'";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t          NAME : ANTHONIE REYES COTANDA";
    cout << "\n\n\n\t\t\t\t\t\t\t          AGE : 20 ";
    cout << "\n\n\n\t\t\t\t\t\t\t          BIRTHDAY : JUNE 12, 2002";
    cout << "\n\n\n\t\t\t\t\t\t\t          ADDRESS : BLK 10 LOT 12 HINAYON COMPOUND, BARANGGAY MANGGAHAN, RODRIGUEZ, RIZAL ";
    cout << "\n\n\n\t\t\t\t\t\t\t          CONTACT NO. : 09633219716";
    cout << "\n\n\n\t\t\t\t\t\t\t          EMAIL : anthoniecotanda@gmail.com";
        }
        else if (currentPage == 2)
        {
            setColor( FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t,------.  ,------.,--.   ,--.,------.,--.    ,-----. ,------. ,------.,------.  ,---.";
    cout << "\n\t\t\t\t\t\t\t\t|  .-.  \\ |  .---' \\  `.'  / |  .---'|  |   '  .-.  '|  .--. '|  .---'|  .--. ''   .-'";
    cout << "\n\t\t\t\t\t\t\t\t|  |  \   :|  `--,   \\     /  |  `--, |  |   |  | |  ||  '--' ||  `--, |  '--'.'`.  `-.";
    cout << "\n\t\t\t\t\t\t\t\t|  '--'  /|  `---.   \\   /   |  `---.|  '--.'  '-'  '|  | --' |  `---.|  |\\  \\ .-'    |";
    cout << "\n\t\t\t\t\t\t\t\t`-------' `------'    `-'    `------'`-----' `-----' `--'     `------'`--' '--'`-----'";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t          NAME : TRISTAN DESAMPARADO CARINGAL";
    cout << "\n\n\n\t\t\t\t\t\t\t          AGE : 19 ";
    cout << "\n\n\n\t\t\t\t\t\t\t          BIRTHDAY : AUGUST 2, 2003";
    cout << "\n\n\n\t\t\t\t\t\t\t          ADDRESS : BLK 15 LOT 19 PH 1A KASIGLAHAN VILLAGE, RODRIGUEZ, RIZAL ";
    cout << "\n\n\n\t\t\t\t\t\t\t          CONTACT NO. : 09292679222";
    cout << "\n\n\n\t\t\t\t\t\t\t          EMAIL : caringaltristan63@gmail.com";
        }
        else if (currentPage == 3)
        {
              setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t,------.  ,------.,--.   ,--.,------.,--.    ,-----. ,------. ,------.,------.  ,---.";
    cout << "\n\t\t\t\t\t\t\t\t|  .-.  \\ |  .---' \\  `.'  / |  .---'|  |   '  .-.  '|  .--. '|  .---'|  .--. ''   .-'";
    cout << "\n\t\t\t\t\t\t\t\t|  |  \   :|  `--,   \\     /  |  `--, |  |   |  | |  ||  '--' ||  `--, |  '--'.'`.  `-.";
    cout << "\n\t\t\t\t\t\t\t\t|  '--'  /|  `---.   \\   /   |  `---.|  '--.'  '-'  '|  | --' |  `---.|  |\\  \\ .-'    |";
    cout << "\n\t\t\t\t\t\t\t\t`-------' `------'    `-'    `------'`-----' `-----' `--'     `------'`--' '--'`-----'";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t          NAME : ENGEL LAGUMBAY LLANTO";
    cout << "\n\n\n\t\t\t\t\t\t\t          AGE : 20 ";
    cout << "\n\n\n\t\t\t\t\t\t\t          BIRTHDAY : SEPTEMBER 26, 2002";
    cout << "\n\n\n\t\t\t\t\t\t\t          ADDRESS : BLK 14 LOT 87 PH 1D KASIGLAHAN VILLAGE, RODRIGUEZ, RIZAL ";
    cout << "\n\n\n\t\t\t\t\t\t\t          CONTACT NO. : 09389908879";
    cout << "\n\n\n\t\t\t\t\t\t\t          EMAIL : llantoengel15@gmail.com";
        }
        else if (currentPage == 4)
        {
            setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t,------.  ,------.,--.   ,--.,------.,--.    ,-----. ,------. ,------.,------.  ,---.";
    cout << "\n\t\t\t\t\t\t\t\t|  .-.  \\ |  .---' \\  `.'  / |  .---'|  |   '  .-.  '|  .--. '|  .---'|  .--. ''   .-'";
    cout << "\n\t\t\t\t\t\t\t\t|  |  \   :|  `--,   \\     /  |  `--, |  |   |  | |  ||  '--' ||  `--, |  '--'.'`.  `-.";
    cout << "\n\t\t\t\t\t\t\t\t|  '--'  /|  `---.   \\   /   |  `---.|  '--.'  '-'  '|  | --' |  `---.|  |\\  \\ .-'    |";
    cout << "\n\t\t\t\t\t\t\t\t`-------' `------'    `-'    `------'`-----' `-----' `--'     `------'`--' '--'`-----'";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t          NAME : MARC JAN VERIDIANO BANZAL";
    cout << "\n\n\n\t\t\t\t\t\t\t          AGE : 19 ";
    cout << "\n\n\n\t\t\t\t\t\t\t          BIRTHDAY : MARCH 30, 2004";
    cout << "\n\n\n\t\t\t\t\t\t\t          ADDRESS : BLK 92 LOT 5 INC COMPOUND, SAN JOSE, RODRIGUEZ, RIZAL ";
    cout << "\n\n\n\t\t\t\t\t\t\t          CONTACT NO. : 09514468787";
    cout << "\n\n\n\t\t\t\t\t\t\t          EMAIL : marcjanbanzal02@gmail.com";
        }
        else if (currentPage == 5)
        {
             setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t,------.  ,------.,--.   ,--.,------.,--.    ,-----. ,------. ,------.,------.  ,---.";
    cout << "\n\t\t\t\t\t\t\t\t|  .-.  \\ |  .---' \\  `.'  / |  .---'|  |   '  .-.  '|  .--. '|  .---'|  .--. ''   .-'";
    cout << "\n\t\t\t\t\t\t\t\t|  |  \   :|  `--,   \\     /  |  `--, |  |   |  | |  ||  '--' ||  `--, |  '--'.'`.  `-.";
    cout << "\n\t\t\t\t\t\t\t\t|  '--'  /|  `---.   \\   /   |  `---.|  '--.'  '-'  '|  | --' |  `---.|  |\\  \\ .-'    |";
    cout << "\n\t\t\t\t\t\t\t\t`-------' `------'    `-'    `------'`-----' `-----' `--'     `------'`--' '--'`-----'";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t          NAME : RICHARD RAMOS JR.";
    cout << "\n\n\n\t\t\t\t\t\t\t          AGE : 19 ";
    cout << "\n\n\n\t\t\t\t\t\t\t          BIRTHDAY : JULY 25, 2003";
    cout << "\n\n\n\t\t\t\t\t\t\t          ADDRESS : BLK 6 LOT 8 PHASE 1F SUB-URBAN VILLAGE, SAN JOSE, RODRIGUEZ, RIZAL ";
    cout << "\n\n\n\t\t\t\t\t\t\t          CONTACT NO. : 09654312934";
    cout << "\n\n\n\t\t\t\t\t\t\t          EMAIL : ramosrichardjr25@gmail.com";
        }
        else
        {
            cout << "Invalid page\n";
            break;
        }

        cout << "\n\n\n\n\n\t\t\t\t\t\t   Press 'left arrow' to go to the previous page or 'right arrow' to go to the next page. 'Backspace' to go back to menu.\n";

        // Detect arrow key or backspace input
        key = _getch();

    if (key == 27) // 27 is the ASCII value for Escape key
            break;
        else if (key == 75 && currentPage > 1) // 75 is the ASCII value for left arrow key
            currentPage--;
        else if (key == 77 && currentPage < 5) // 77 is the ASCII value for right arrow key
            currentPage++;
        else if (key == 8) {
            goBackToMenu = true;
            break;
        }
    }
}


int main() {
    system("cls");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
    cout <<"\t\t    _____  ____  ______  ____     ___  _____ _____     ___ ___   ____  ____    ____   ____    ___  ___ ___    ___  ____   ______       _____ __ __  _____ ______    ___  ___ ___"<<endl;
    cout <<"\t\t   |     ||    ||      ||    \\   /  _]/ ___// ___/    |   |   | /    ||    \\  /    | /    |  /  _]|   |   |  /  _]|    \\ |      |     / ___/|  |  |/ ___/|      |  /  _]|   |   |"<<endl;
    cout <<"\t\t   |   __| |  | |      ||  _  | /  [_(   \\_(   \\_     | _   _ ||  o  ||  _  ||  o  ||   __| /  [_ | _   _ | /  [_ |  _  ||      |    (   \\ |   |  (   \\_ |      | /  [_ | _   _ |"<<endl;
    cout <<"\t\t   |  |_   |  | |_|  |_||  |  ||    _]\\__  |\\__   |   |  \\_/  ||     ||  |  ||     ||  |  ||    _]|  \\_/  ||    _]|  |  ||_|  |_|     \\__  ||  ~  |\\__  ||_|  |_||    _]|  \\_/  |"<<endl;
    cout <<"\t\t   |   _]  |  |   |  |  |  |  ||   [_ /  \\ |/  \\ |    |   |   ||  _  ||  |  ||  _  ||  |_ ||   [_ |   |   ||   [_ |  |  |  |  |       /  \\ ||___, |/  \\ |  |  |  |   [_ |   |   |"<<endl;
    cout <<"\t\t   |  |    |  |   |  |  |  |  ||     |\\    |\\    |    |   |   ||  |  ||  |  ||  |  ||     ||     ||   |   ||     ||  |  |  |  |       \\    ||     |\\    |  |  |  |     ||   |   |"<<endl;
    cout <<"\t\t   |__|   |____|  |__|  |__|__||_____| \\___| \\___|    |___|___||__|__||__|__||__|__||___,_||_____||___|___||_____||__|__|  |__|        \\___||____/  \\___|  |__|  |_____||___|___|"<<endl;
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   [Enter] Continue                 ";

    char choice = _getch();

    switch (choice) {
        case 13:
            break;
        default:
            return 0;
    }

    int menuChoice = 1;
    char key;

    while (true) {
        system("cls");

        // Display menu options
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t   ,--.   ,--.,------.,--.  ,--.,--. ,--. \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   |   `.'   ||  .---'|  ,'.|  ||  | |  | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   |  |'.'|  ||  `--, |  |' '  ||  | |  | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   |  |   |  ||  `---.|  | `   |'  '-'  ' \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t   `--'   `--'`------'`--'  `--' `-----'  \n";

        switch (menuChoice) {
            case 1:
                cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> FITNESS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   USER\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   ADMIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   SOFTWARE DEVELOPERS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   EXIT\n";
                break;
            case 2:
                cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   FITNESS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> USER\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   ADMIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   SOFTWARE DEVELOPERS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   EXIT\n";
                break;
            case 3:
                cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   FITNESS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   USER\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> ADMIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   SOFTWARE DEVELOPERS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   EXIT\n";
                break;
            case 4:
                cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   FITNESS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   USER\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   ADMIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> SOFTWARE DEVELOPERS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   EXIT\n";
                break;
            case 5:
                cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   FITNESS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   USER\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   ADMIN\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   SOFTWARE DEVELOPERS\n";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t-> EXIT\n";
                break;
        }

        key = _getch();

        if (key == 13) { // Enter key is pressed
            switch (menuChoice) {
                case 1:
                    displayFitnessPage();
                    break;
                case 2:
                    Login();
                    break;
                case 3:
                    AdminLogin();
                    break;
                case 4:
                    displaySoftwareDevelopersPage();
                    break;
                case 5:
                    cout <<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tThank you, Have a Good day!";
                    return 0; // Exit the program
            }

            if (goBackToMenu) {
                goBackToMenu = false; // Reset the flag
                continue; // Go back to the menu
            }
        } else if (key == 80 && menuChoice < 5) { // Down arrow key is pressed
            menuChoice++; // Increment the menu choice
        } else if (key == 72 && menuChoice > 1) { // Up arrow key is pressed
            menuChoice--; // Decrement the menu choice
        }
    }

    return 0;
}
