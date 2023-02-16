// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream> //import header files that includes IO functions such as cin and cout

#include <cstdlib>
#include <limits>

using namespace std; //define the namespace

class Queue_Array {
private:
    int front;
    int rear;
    int size;
    int capacity;
    int* data;

public:
    Queue_Array(int cap) {
        capacity = cap;
        size = 0;
        front = 0;
        rear = 0;
        data = new int[capacity];
    }

    void enQueue(int val) {
        if (size == capacity) {
            cout << "Queue is full" << endl;
        }
        else {
            data[rear] = val;
            rear = (rear + 1) % capacity;
            size++;
        }
    }

    int deQueue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        else {
            int temp = data[front];
            front = (front + 1) % capacity;
            size--;
            return temp;
        }

    }

    void print() {
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << data[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};


int main()
{
    Queue_Array qa(4);
    qa.enQueue(5);
    qa.enQueue(7);
    qa.enQueue(9);
    qa.print();

    cout << qa.deQueue() << endl;

    qa.enQueue(45);
    qa.enQueue(6);
    qa.print();

    qa.enQueue(2);

    return 0;
}

