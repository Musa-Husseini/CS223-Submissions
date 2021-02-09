#ifndef CPTS_223_PA1_LINKEDLIST_H
#define CPTS_223_PA1_LINKEDLIST_H
#include "header.h"

template<class T, class U>
class Node
{
public:
    T command;
    U description;
    int visitedNode = 0;
    Node* next;
};

template<class T, class U>
class commandList
{
private:
    Node<T, U> * head;
    Node<T, U> * tail;

    string userName;
    int userScore;

    //string *loadPlayerNames;


public:
    commandList()
    {
        head = NULL;
        tail = NULL;
        userScore = 0;
        //loadPlayerNames = new string [5];
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

    void add(fstream* file)
    {
        string c, d;
        while(getline(*file, c, ','))
        {

            getline(*file, d);
            push(c, d);
        }
        print();

    }

    void push(string c, string d)
    {

        Node<T, U>* temp = new Node<T, U>;

        temp->command = c;
        temp->description = d;


        if(head == NULL)
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

    void loadPlayerData()
    {
        fstream test;
        test.open("Profiles.csv", ios::in);
        string playerName;
        cout << "Please enter you name: " << endl;
        cin >> playerName;
        string currentFileName;
        string currentFileScore;


        while(!test.eof())
        {
            getline(test, currentFileName, ',');
            getline(test, currentFileScore);

            if(playerName == currentFileName)
            {
                cout << playerName << ": " << currentFileScore << endl;
            }

        }

        test.close();
    }


    void readPlayerData(fstream& outfile)
    {
        outfile << userName << ", " << userScore << endl;
    }
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
    void randomNodeCorrect(string *c, string *d) {

        *c = head->command;
        *d = head->description;

        Node<T, U> *current = head;

        int size = listSize();

        int randomNum = rand() % size + 1;
        for (int i = 0; i < size; i++)
        {

            if(current->next == NULL)
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
    void gamePlay()
    {

        cout << "Enter your name: " << endl;
        cin.ignore();
        getline(cin, userName);

        int questionCount = 0;
        cout << "How many questions would you like there to be asked? (5-30)" << endl;
        cin >> questionCount;
        while(questionCount > 30 || questionCount < 5)
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
            randomNodeCorrect(&currentCommand, &currentDescription);
            randomNodeIncorrect(&wrongDes1);
            randomNodeIncorrect(&wrongDes2);
            while(currentDescription == wrongDes1 || currentDescription == wrongDes2 || wrongDes1 == wrongDes2)
            {
                randomNodeIncorrect(&wrongDes1);
                randomNodeIncorrect(&wrongDes2);
            }

            randOrder = rand() % (3 -1 +1) + 1;

            int userOption = 0;

            switch(randOrder)
            {
                case 1:
                    cout << endl << "Question " << i+1 << ": What does " << currentCommand << " do?" << endl;
                    cout << currentDescription << endl << wrongDes1 << endl << wrongDes2 << endl;
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
                case 2:
                    cout << endl << "Question " << i+1 << ": What does " << currentCommand << " do?" << endl;
                    cout << wrongDes1 << endl << currentDescription  << endl << wrongDes2 << endl;

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
                case 3:
                    cout << endl << "Question " << i+1 << ": What does " << currentCommand << " do?" << endl;
                    cout << wrongDes1 << endl <<  wrongDes2  << endl << currentDescription<< endl;
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
