#ifndef CPTS_223_PA1_LINKEDLIST_H
#define CPTS_223_PA1_LINKEDLIST_H
#include "profilesArray.h"
#include "header.h"

/*
 Creates nodes for the linked list
 */
template<class T, class U>
class Node
{
public:
    T command;
    U description;
    int visitedNode = 0; //used for making sure the isnt a repeat of same question asked
    Node* next;
};

/*
 Class for the game
 */
template<class T, class U>
class commandList
{
private:
    Node<T, U> * head; //head for linked list
    Node<T, U> * tail; //tail for linked list
    string userName;
    int userScore;



public:
    commandList()
    {
        head = NULL;
        tail = NULL;
        userScore = 0;
        userName = "";



    }

    ~commandList()
    {
        Node<T, U>* data = new Node<T, U>;

        data = head;
        while(data->next != NULL)
        {
            data = head->next;
            delete(head);
            head = data;
        }

        delete(data);
    }

    /*
     reads in data from file and calls push function
     */
    void add(fstream* file)
    {
        string c, d;
        //c is for command and d is for description and the while loop will read until end of list
        while(getline(*file, c, ','))
        {

            getline(*file, d);
            push(c, d); //calls on push function
        }

    }

    void push(string c, string d)
    {

        Node<T, U>* temp = new Node<T, U>; //creates temp node

        temp->command = c;
        temp->description = d;


        if(head == NULL) //if head is empty then head is the first node
        {
            head = temp;
            tail = temp;
        }
        else
        {

            tail->next = temp;
            tail = tail->next;
        }


    }

    void print()
    {
        Node<T, U>* data;
        data = head;


        while(data->next != NULL)
        {
            cout << data->command << " " << data->description << endl;
            data = data->next;
        }

        cout << data->command << " " << data->description << endl;
    }


    int profilesSize(fstream& file)
    {
        int counter = 0;
        string temp;
        while(getline(file, temp))
        {
            counter++;
        }

        return counter;
    }
    /*
     loads previous player data
     */
    void loadPlayerData()
    {
        fstream file;
        file.open("Profiles.csv", ios::in);

        string playerName;
        cout << "Please enter you name: " << endl;
        cin >> playerName;

        string currentName;
        int size = profilesSize(file);
        file.close();
        file.open("Profiles.csv", ios::in);

        string currentPoints;

        profilesArray pArray[size];



        int counter = 0;
        while(counter != size)
        {

            getline(file, currentName, ',');
            getline(file, currentPoints, '\n');


            pArray[counter].setPoints(currentPoints);
            pArray[counter].setName(currentName);
            counter++;
        }

        for(int i = 0; i < size; i++)
        {
            if(playerName == pArray[i].getName())
            {
                cout << pArray[i].getName() << ": " << pArray[i].getPoints()<< endl;
            }

        }


        file.close();
    }

/*
 prints out the player data
 */
    void readPlayerData(fstream& outfile)
    {
        outfile << userName << ", " << userScore << endl;
    }

    /*
     determines the size of the list
     */
    int listSize()
    {
        int size = 0;

        Node<T, U>* data;
        data = head;

        while(data->next != NULL)
        {
            size++;
            data = data->next;
        }

        return size;
    }

    /*
     it will find the random command and the following description
     */
    void randomNodeCorrect(string *c, string *d) {

        *c = head->command;
        *d = head->description;

        Node<T, U> *current = head;

        int size = listSize();

        int randomNum = rand() % size + 1;
        for (int i = 0; i < size; i++)
        {

            if(current->next == NULL) //if the list has been run through it goes back to the beginning
            {
                current = head;
            }
            if ( i == randomNum && current->visitedNode == 0)
            {
                *c = current->command;
                *d = current->description;
                current->visitedNode = 1;
                break;
            }
            current = current->next;
        }


    }

    /*
     finds a random description to use
     */
    void randomNodeIncorrect(string *d)
    {
        *d = head->description;

        Node<T, U> *current = head;

        int size = listSize();

        int randomNum = rand() % size + 1;
        for(int i = 0; i < size; i++)
        {
            if(i == randomNum)
            {
                *d = current->description;

                break;
            }

            current = current->next;
        }

    }

    /*
     gameplay function
     */
    void gamePlay()
    {

        cout << "Enter your name: " << endl;
        cin.ignore();
        getline(cin, userName);

        int questionCount = 0;
        cout << "How many questions would you like there to be asked? (5-30)" << endl;
        cin >> questionCount;
        while(questionCount > 30 || questionCount < 5) //error checking
        {
            cout << "Please chose within the range 5-30" << endl;
            cin >> questionCount;
        }

        string currentCommand;
        string currentDescription;
        string wrongDes1;
        string wrongDes2;

        int randOrder = 0;
        for(int i = 0; i < questionCount; i++)
        {
            randomNodeCorrect(&currentCommand, &currentDescription); //correct question and description
            randomNodeIncorrect(&wrongDes1); //incorect descirption
            randomNodeIncorrect(&wrongDes2); //incorect descirption
            while(currentDescription == wrongDes1 || currentDescription == wrongDes2 || wrongDes1 == wrongDes2) //checking for duplicates
            {
                randomNodeIncorrect(&wrongDes1);
                randomNodeIncorrect(&wrongDes2);
            }

            randOrder = rand() % (3 -1 +1) + 1;

            int userOption = 0;

            switch(randOrder)
            {
                case 1: //randomizes which answer is right
                    cout << endl << "Question " << i+1 << ": What does " << currentCommand << " do?" << endl;
                    cout << "1." << currentDescription << endl << "2." << wrongDes1 << endl << "3." << wrongDes2 << endl;
                    cin >> userOption;
                    while(userOption > 3 || userOption < 1)
                    {
                        cout << "Please enter an option between 1-3" << endl;
                        cin >> userOption;
                    }

                    if(userOption == 1)
                    {
                        cout << "Correct! You gained a point" << endl;
                        userScore++;
                    }

                    else
                    {
                        cout << "Incorrect. You lost a point" << endl;
                        userScore--;
                    }



                    break;
                case 2: //randomizes which answer is right
                    cout << endl << "Question " << i+1 << ": What does " << currentCommand << " do?" << endl;
                    cout <<"1." <<  wrongDes1 << endl << "2." << currentDescription  << endl << "3." << wrongDes2 << endl;

                    cin >> userOption;
                    while(userOption > 3 || userOption < 1)
                    {
                        cout << "Please enter an option between 1-3" << endl;
                        cin >> userOption;
                    }

                    if(userOption == 2)
                    {
                        cout << "Correct! You gained a point" << endl;
                        userScore++;
                    }

                    else
                    {
                        cout << "Incorrect. You lost a point" << endl;
                        userScore--;
                    }
                    break;
                case 3:  //randomizes which answer is right
                    cout << endl << "Question " << i+1 << ": What does " << currentCommand << " do?" << endl;
                    cout <<"1." <<  wrongDes1 << endl << "2." <<  wrongDes2  << endl << "3." << currentDescription<< endl;
                    cin >> userOption;
                    while(userOption > 3 || userOption < 1)
                    {
                        cout << "Please enter an option between 1-3" << endl;
                        cin >> userOption;
                    }

                    if(userOption == 3)
                    {
                        cout << "Correct! You gained a point" << endl;
                        userScore++;
                    }

                    else
                    {
                        cout << "Incorrect. You lost a point" << endl;
                        userScore--;
                    }
                    break;
            }

        }



    }

    /*
     adds a command to the linked list
     */
    void addCommand()
    {
        string userCommand;
        string userDescription;

        cout << "Enter you command" << endl;
        cin.ignore();
        getline(cin, userCommand);
        cout << "Enter the description" << endl;
        getline(cin,userDescription);

        push(userCommand, userDescription);

        print();

    }

    /*
     deletes a node from the list
     */
    void deleteNode()
    {
        string userDelete;

        cout << "Which command would you like to be deleted? " << endl;
        cin >> userDelete;

        Node<T, U>* temp = head;
        Node<T, U>* prev = NULL;

        cout << temp->command << endl << userDelete << endl;

        cout << (temp->command.compare(userDelete)) << endl;
        if(temp->command ==  userDelete)
        {
            cout << "test" << endl;
            head = temp->next;
            delete temp;
            print();
            return;
        }
        else
        {
            while(temp != NULL && temp->command != userDelete)
            {
                prev = temp;
                temp = temp->next;
            }

            if(temp == NULL)
                return;
            prev->next = temp->next;

            delete temp;
        }



        print();
    }

    /*
     this will overwrite the csv files with the new information
     */
    void overWrite()
    {
        fstream overWrite;
        overWrite.open("Linux_Commands_Cheat_Sheet.csv", ios::out);
        Node<T, U>* data;
        data = head;

        while(data->next != nullptr)
        {
            overWrite << data->command << ", " << data->description << endl;
            data = data->next;
        }

        overWrite << data->command << ", " << data->description << endl;

        overWrite.close();
    }
};

#endif //CPTS_223_PA1_LINKEDLIST_H
