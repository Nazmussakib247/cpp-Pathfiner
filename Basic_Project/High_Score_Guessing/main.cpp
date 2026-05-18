#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int secret = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Guess the number (1 to 100):\n";

    // Game loop
    do {
        cin >> guess;
        attempts++;

        if (guess > secret)
            cout << "Too high!\n";
        else if (guess < secret)
            cout << "Too low!\n";
        else
            cout << "Correct!\n";

    } while (guess != secret);

    cout << "You guessed in " << attempts << " attempts.\n";

    // Read leaderboard and find best score
    ifstream infile("highscore.txt");

    string name;
    int score;
    int bestScore = 1000;

    while (infile >> name >> score) {
        if (score < bestScore) {
            bestScore = score;
        }
    }

    infile.close();

    cout << "Current Best Score: " << bestScore << endl;

    // Compare scores
    if (attempts < bestScore) {
        cout << "New High Score!\n";
    } else {
        cout << "Try again to beat the high score!\n";
    }

    // Append new score
    ofstream outfile("highscore.txt", ios::app);

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    outfile << playerName << " " << attempts << endl;

    outfile.close();

    return 0;
}
