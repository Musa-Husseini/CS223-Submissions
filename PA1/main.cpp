
#include "linkedList.h"
/*
 ADVANTAGES/DISADVANTAGES LINKED LIST
 One advantage of using a linked list is it is an easy way to store all my information in an organized format. An disadvantage is how long it takes the
 compiler to traverse the linked list. Since it always goes from the start to finish it isn't the most efficient way to store data.

 ADVANTAGES/DISADVANTAGES ARRAY
 One advantage of storing the profiles in an array is it is easy to use a loop and traverse the array until you find the profile you want. A disadvantage is finding the right amount
 of indexes to put in the array. Since there can be infinetly many profiles there can be a lot of space being allocated just for the single array. Also like the linked list traversing
 the array can be inefficient also.
 */
int main()
{
    srand(time(NULL));
    fstream infile;
    infile.open("Linux_Commands_Cheat_Sheet.csv", ios::in | ios::out); //opens command csv file


    fstream outfile;
    outfile.open("Profiles.csv", ios::in | ios::out); //opens output file

    commandList<string, string> x; //creates a object of commandList


    x.add(&infile); //reads file and adds it to linked list


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