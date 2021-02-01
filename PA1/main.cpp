
#include "linkedList.h"

int main()
{
    ifstream infile;
    infile.open("Linux_Commands_Cheat_Sheet.csv");

    if(!infile)
        return 0;
    commandList<string, string> x;
    //x.add(infile);


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