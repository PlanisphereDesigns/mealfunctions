// lunch_dinner_snack_breakfast_functions.cpp 
//This file uses different functions to "make" different meals during the day.
//The make meal function is flexible for any meal
//interactive in the console

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/* Declare Functions. */
/*makeMeal()*/
void makeMeal(string mealTime, vector<string> menu, string meal) {
    cout << endl;
    cout << "Now making " << meal << "!" << endl;
    cout << endl;
    cout << meal << " today is at " << mealTime << "'oclock" << endl;
    cout << endl;
    cout << "The menu today is: " << endl;
    for (int i = 0; i < int(menu.size()); i++) {
        cout << "Item " << i + 1 << " is: " << menu.at(i) << endl;
    }
}

/*Get menu() function*/
vector<string> getMenu(string mealName, vector<string> genericVector) {
    cout << "What do you want the menu for " << mealName << " to be?  Enter 3 items: ";
    string input;
    for(int i = 0; i < 3; i++) {
        cout << "Please enter item " << i+1 << " for " << mealName << ": ";
        cin >> input;
        /*Check for empty string while loop. Otherwise, the user can enter whatever as a menu item.*/
        while (input.size() == 0) {
            cout << "Please enter a valid input for the " << mealName << " item: ";
            cin >> input;   
        }
        //outside while loop push back vector
        genericVector.push_back(input);
    }
    return genericVector;
}

int main()
{
    vector<string> eatingTimes;
    vector<string> eatingNames;
    string time;
    eatingNames.push_back("Breakfast");
    eatingNames.push_back("Lunch");
    eatingNames.push_back("Snack");
    eatingNames.push_back("Dinner");

    /*Check if the number for time is a valid 1-digit number.*/
    for (int i = 0; i < int(eatingNames.size()); i++) {
        cout << "When do you want " << eatingNames.at(i) << " to be?  Enter a 1 digit number: ";
        /*Use a while loop to keep asking for an int until the user types one*/
        cin >> time;
        while (!isdigit(time.at(0)) || int(time.length()) > 1) {
            cout << "Sorry, that was not a valid time.  Please enter a 1-digit integer only: ";
            cin >> time;
            if (isdigit(time.at(0))) {
                /*extra check to prevent infinite while loops*/
                break;
            }
        }
        eatingTimes.push_back(time);
    }

    vector<string> breakfastMenu;
    vector<string> lunchMenu;
    vector<string> snackMenu;
    vector<string> dinnerMenu;
    vector<string> filledBreakfast;
    vector<string> filledLunch;
    vector<string> filledSnack;
    vector<string> filledDinner;
    /*fill the menus*/
  
    filledBreakfast = getMenu("Breakfast", breakfastMenu);
    filledLunch = getMenu("Lunch", lunchMenu);
    filledSnack = getMenu("Snack", snackMenu);
    filledDinner = getMenu("Dinner", dinnerMenu);

        /*The first one is breakfast, the second one is lunch, the third one is snack, and the fourth one is dinner. 
        This code populates them into the ints vector in this order*/

        /*Call the makeMeal function with different values for different meals.*/
        for (int i = 0; i < int(eatingNames.size()); i++) {
            if (i == 0) {
                makeMeal(eatingTimes.at(i), filledBreakfast, eatingNames.at(i));
            }
            else if (i == 1) {
                makeMeal(eatingTimes.at(i), filledLunch, eatingNames.at(i));

            }
            else if (i == 2) {
                makeMeal(eatingTimes.at(i), filledSnack, eatingNames.at(i));
            }
            else {
                makeMeal(eatingTimes.at(i), filledDinner, eatingNames.at(i));
            }
            
        }
}
