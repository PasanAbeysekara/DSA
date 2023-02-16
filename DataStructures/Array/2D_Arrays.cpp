// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream> //import header files that includes IO functions such as cin and cout
#include <cstdlib>

using namespace std; //define the namespace

int main()
{
   int** p;
   int N = 3, M = 5;

   p = new int* [N];

   //create arrays
   for (int i = 0; i < N; i++) {
       p[i] = new int[M];
   }

   //assign values
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < M; j++) {
           p[i][j] = i * j;
       }
   }

   //print
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < M; j++) {
           cout << p[i][j] << " ";
       }
       cout << endl;
   }
}

