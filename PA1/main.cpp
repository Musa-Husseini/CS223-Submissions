
#include "header.h"

int main()
{
    //fstream infile;
    //infile.open("LinuxCommandsCheatSheet.csv", ios::in);


    int userOption = mainMenu();
    while(userOption != 6)
    {
        switch(userOption)
        {
            case 1:
                gameRules();
                break;
            case 2:
                //play game
                break;
            case 3:
                //load previous game
                break;
            case 4:
                //add command
                break;
            case 5:
                //remove command
                break;
            case 6:
                //infile.close();
                return 0;

        }
        userOption = mainMenu();
    }
    return 0;
}