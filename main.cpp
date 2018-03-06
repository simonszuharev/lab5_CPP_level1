#include <iostream>
#include "coin.h" // I am using coin.h file because my compiler supports this type only, not .hpp

//Final submission , where I corrected the output design

using namespace std;

/*Use the Coin class to implement a program that simulates tossing of two coins simultaneously. The program should contain a loop that:

Prompts the user to predict the outcome of the toss: "Odd" or "Even".  "Odd" predicts the side up of both coins will be different. "Even" predicts the side of both coins will be the same. The prompt should provide an option to terminate the loop and exit the program.
Simulates tossing of both coins.
Determines if the user's prediction was correct or incorrect and displays a message to that effect.
Accumulates and displays the total number of correct and incorrect predictions.
Refer to Lab5 Screen Display in the Review folder for a sample of the program interaction and output display requirements.

The following files are to be used in the solution and may be downloaded from the Review folder:

Lab5 Coin Class Definition (coin.hpp)
Lab5 Coin Class Implementation (coin.cpp).
These files are to be used "as is", without modification, to implement the coin toss simulation program.*/

 string pred_or_preds(int number);
 string verb(string verb);

 char inputOption(string prompt, string options, bool lower=true);

     void outputPrompt(string prompt) {
        cout << prompt;
        cin.clear();
        cin.sync();
    }

        char inputOption(string prompt, string options, bool lower) {
        outputPrompt(prompt);
        char result = cin.get();
        while(options.find_first_of(result) == string::npos) {
            cout << "Please re-enter. ";
            cout << prompt;
            cin.clear(); cin.sync();
            result = cin.get();
        }
        return lower == true ? tolower(result) : result;
    }

int main()
{
    char repeat,
    current_sides;

    int lucky_predictions = 0;
    int predictions;
    string result,
        correctness;

    Coin coin_1;
    Coin coin_2;

    cout << "Toss Two Coins Simultaneously\n";
    cout << "-----------------------------\n";

    while(tolower(repeat) != 'q') {

            cout << "Toss the coins.\n";
            repeat = inputOption("Predict Odd, Even, or Quit (O/E/Q):", "oOeEqQ");
            if (tolower(repeat) == 'q') break;

            coin_1.tossCoin();
            coin_2.tossCoin();
            predictions = (coin_1.getTossCount()+coin_2.getTossCount())/2;
            current_sides =  (coin_1.getSideUp() == coin_2.getSideUp()) ? 'E' : 'O';
            lucky_predictions = (toupper(repeat) == current_sides) ? ++lucky_predictions : lucky_predictions;
            result = (toupper(repeat) == 'O') ? "Odd" : "Even";
            correctness = (toupper(repeat) == current_sides) ? "correct" : "incorrect";

            cout << "Coin #1 side up is " << coin_1.getSideUp() << " and Coin #2 up is " << coin_2.getSideUp() << "." << endl;
            cout << "You predicted " << result << ". Your prediction was " << correctness << ".\n";
            cout << "Out of " << predictions << " " << pred_or_preds(predictions) << ", " << lucky_predictions << " ";
            cout << pred_or_preds(lucky_predictions) << " " << verb(pred_or_preds(lucky_predictions)) << "been correct. \n" << endl;

    }
    cout << "\n-----------------------------";

    return 0;
}


    string pred_or_preds(int number){

        string pred;
        return (pred = (number <= 1) ? "prediction" : "predictions");
    }

    string verb(string verb){
        return (verb = (verb == "prediction") ? "has ":"have ");
    }
