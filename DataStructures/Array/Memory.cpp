// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream> //import header files that includes IO functions such as cin and cout
#include <dos.h>
#include <cstdlib>

using namespace std; //define the namespace

int* funcA() {
   int z = 11;
   //heap example
   int* p = new int[10];
   p[0] = 5;
   delete[]p;
   //stack example
   //int p[100000];
   //p[0] = 21;
   return p;

/*
   // All these variables get memory
   // allocated on stack
   int a;
   int b[10];
   int n = 20;
   int c[n];

   // This memory for 10 integers
   // is allocated on heap.
   int *ptr  = new int[10];
*/

}

int main()
{
   int x = 10;
   int y = 30;
   int* p = funcA();

   //cout << "Going to sleep" << endl;
   //cout.flush();
   //Sleep(100000);

   cout << p[0] << endl;

   return 0;
}

