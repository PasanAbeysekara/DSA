#include <iostream> //import header files that includes IO functions such as cin and cout

#include <cstdlib>
#include "Doubly_Linked_List.h"

using namespace std; //define the namespace

class Stack_Array {

private:
    int top;
    int capacity;
    int* data;

public:
    Stack_Array(int cap) {
        capacity = cap;
        top = 0;
        data = new int[capacity];
    }

    void push(int val) {
        if (top >= capacity)
            cout << "Stack is full" << endl;
        else {
            data[top] = val;
            top++;
        }

    }

    int pop() {
        if (top == 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            top--;
            return data[top];
        }
    }

    void print() {
        for (int i = 0; i < top; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack_Array sa(10);
    sa.push(4);
    sa.push(7);
    sa.print();
    cout << sa.pop() << endl;
    sa.push(9);
    sa.print();

}