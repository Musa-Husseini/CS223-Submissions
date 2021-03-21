#include "AVLTree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>





int main() {

    AVLTree<int> *ascendingOrder = new AVLTree<int>();
    AVLTree<int> *descendingOrder = new AVLTree<int>();
    AVLTree<int> *randomOrder = new AVLTree<int>();

    int ascendingOrderArr[50] = {};
    int descendingOrderArr[50] = {};
    int randomOrderArr[50] = {};

    //Populating ascending array
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 1)
            ascendingOrderArr[i / 2] = i;
    }


    //populating descending array
    int index = 0;
    for (int i = 100; i > 0; i--) {
        if (i % 2 == 1) {
            descendingOrderArr[index] = i;
            index++;
        }
    }


    //populating random array
    srand((unsigned) time(0));
    int countArr[100] = {};

    int randNum = 0;
    int counter = 0;

    while (counter != 50) {
        randNum = rand() % 100 + 1;
        while (countArr[randNum] > 0)
            randNum = rand() % 100 + 1;
        if (randNum % 2 == 1) {

            randomOrderArr[counter] = randNum;
            countArr[randNum]++;
            counter++;
        }
    }



    //Test 1

    for (int i = 0; i < 50; i++)
        ascendingOrder->insert(ascendingOrderArr[i]);

    cout << "The height for ascending order is: ";
    ascendingOrder->height();
    ascendingOrder->validate();

    cout << "Ascending Order Contains" << endl;
    for (int i = 0; i < 100; i++)
        ascendingOrder->contains(i);





    //Test 2
    for (int i = 0; i < 50; i++)
        descendingOrder->insert(descendingOrderArr[i]);
    cout << "The height for descending order is: ";
    descendingOrder->height();
    descendingOrder->validate();
    cout << "Descending Order contains" << endl;
    for (int i = 0; i < 100; i++)
        descendingOrder->contains(i);



    //Test 3
    for (int i = 0; i < 50; i++)
        randomOrder->insert(randomOrderArr[i]);
    cout << "The height for random order is: ";
    randomOrder->height();
    randomOrder->validate();
    cout << "Random Order contains" << endl;
    for (int i = 0; i < 100; i++)
        randomOrder->contains(i);


    return 0;
}