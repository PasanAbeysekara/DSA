// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream> //import header files that includes IO functions such as cin and cout

#include <cstdlib>
#include "Doubly_Linked_List.h"

using namespace std; //define the namespace



int main()
{
    Doubly_Linked_List dll;
    cout << "------- Insert First Use Cases -------" << endl;
    dll.insertFirst(5);
    dll.insertFirst(10);
    dll.insertFirst(23);
    dll.print();
    cout << "------- Insert Last Use Cases -------" << endl;
    dll.insertLast(9);
    dll.insertLast(12);
    dll.insertLast(7);
    dll.print();
    cout << "------- Insert At Use Cases -------" << endl;
    dll.insertAt(3, 10);
    dll.insertAt(1, 78);
    dll.insertAt(4, 45);
    dll.print();
    cout << "------- Delete First Use Cases -------" << endl;
    dll.deleteFirst();
    dll.print();
    dll.deleteFirst();
    dll.print();
    cout << "------- Delete Last Use Cases -------" << endl;
    dll.deleteLast();
    dll.print();
    dll.deleteLast();
    dll.print();
    cout << "------- Delete At Use Cases -------" << endl;
    dll.insertAt(2, 34);
    dll.print();
    dll.deleteAt(3);
    dll.print();
    dll.deleteAt(2);
    dll.print();
    /*cout << "------- Delete With Use Cases -------" << endl;
    dll.insertFirst(5);
    dll.insertLast(5);
    dll.insertAt(4, 7);
    dll.insertAt(2, 5);
    dll.print();
    dll.search(5);
    dll.deleteWith(5);
    dll.print();
    cout << "Head : " << dll.getHead()->elem << endl;
    cout << "Tail : " << dll.getTail()->elem << endl;*/
}

