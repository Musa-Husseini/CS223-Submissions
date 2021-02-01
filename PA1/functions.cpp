#include "header.h"

int mainMenu()
{
    int userMenuOption = 0;
    cout << "Please select an option: " << endl;
    cout << "1. Game Rules" << endl << "2. Play Game" << endl << "3. Load Previous Game" << endl << "4. Add Command" << endl << "5. Remove Command" << endl << "6. Exit Game" << endl;
    cin >> userMenuOption;

    while(userMenuOption > 6 || userMenuOption < 1)
    {
        cout << "Please select an option: " << endl;
        cout << "1. Game Rules" << endl << "2. Play Game" << endl << "3. Load Previous Game" << endl << "4. Add Command" << endl << "5. Remove Command" << endl << "6. Exit Game" << endl;
        cin >> userMenuOption;
    }

    return userMenuOption;
}

void gameRules()
{
    
}