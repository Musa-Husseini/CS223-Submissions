
#include "linkedList.h"

int main()
{
    srand(time(NULL));
    fstream infile;
    infile.open("Linux_Commands_Cheat_Sheet.csv", ios::in | ios::out);


    fstream outfile;
    outfile.open("Profiles.csv", ios::in | ios::out);

    commandList<string, string> x;


    x.add(&infile);
    x.print();



    int userOption = mainMenu();


    while(userOption != 7)
    {
        switch(userOption)
        {
            case 1:
                gameRules();
                break;
            case 2:
                //play game
                x.gamePlay();
                x.readPlayerData(outfile);
                break;
            case 3:
                //load previous game
                x.loadPlayerData();
                break;
            case 4:
                //add command
                x.addCommand();
                break;
            case 5:
                //remove command
                x.deleteNode();
                break;
            case 6:
                x.overWrite();
                infile.close();
                outfile.close();
                return 0;
        }
        userOption = mainMenu();
    }


    return 0;
}