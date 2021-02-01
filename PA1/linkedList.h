#ifndef CPTS_223_PA1_LINKEDLIST_H
#define CPTS_223_PA1_LINKEDLIST_H
#include "header.h"

template<class T, class U>
class Node
{
public:
    T command;
    U description;
    Node* next;
};

template<class T, class U>
class commandList
{
private:
    Node<T, U> * head;

public:
    commandList()
    {
        head = NULL;
    }

    //template<class T, class U>
    void add(fstream& file)
    {
        Node<T, U>* data = new Node<T, U>;
        while(!file.eof())
        {
            getline(file, data->command, ',');
            getline(file, data->description);
            push(data);
            cout << data->command;
        }

    }

    //template<class T, class U>
    void push(Node<string, string>* data)
    {
        //Node<T, U>* temp = new Node<T, U>;

        //temp->command = data.command;
        //temp->description = data.description;

        if(head == NULL)
        {
            head = data;

        }
        else
        {
            data->next = head;
            head = data;
        }
    }


};

#endif //CPTS_223_PA1_LINKEDLIST_H
