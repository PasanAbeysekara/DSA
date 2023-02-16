// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream> //import header files that includes IO functions such as cin and cout

#include <cstdlib>
#include "Singly_Linked_List.h"

using namespace std; //define the namespace



int main()
{
    Singly_Linked_List sll;
    cout << "------- Insert First Use Cases -------" << endl;
    sll.insertFirst(5);
    sll.insertFirst(10);
    sll.insertFirst(23);
    sll.print();
    cout << "------- Insert Last Use Cases -------" << endl;
    sll.insertLast(9);
    sll.insertLast(12);
    sll.insertLast(7);
    sll.print();
    cout << "------- Insert At Use Cases -------" << endl;
    sll.insertAt(10, 3);
    sll.insertAt(1, 78);
    sll.insertAt(4, 45);
    sll.print();
    cout << "------- Delete First Use Cases -------" << endl;
    sll.deleteFirst();
    sll.print();
    sll.deleteFirst();
    sll.print();
    cout << "------- Delete Last Use Cases -------" << endl;
    sll.deleteLast();
    sll.print();
    sll.deleteLast();
    sll.print();
    cout << "------- Delete At Use Cases -------" << endl;
    sll.insertAt(2, 34);
    sll.print();
    sll.deleteAt(3);
    sll.print();
    sll.deleteAt(2);
    sll.print();
    cout << "------- Delete With Use Cases -------" << endl;
    sll.insertFirst(5);
    sll.insertLast(5);
    sll.insertAt(4, 7);
    sll.insertAt(2, 5);
    sll.print();
    sll.search(5);
    sll.deleteWith(5);
    sll.print();
    cout << "Head : " << sll.getHead()->elem << endl;
    cout << "Tail : " << sll.getTail()->elem << endl;
}

