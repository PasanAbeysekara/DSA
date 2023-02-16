// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream> //import header files that includes IO functions such as cin and cout
#include <cstdlib>

using namespace std; //define the namespace



int main()
{
   cout << "Hello World!\n";
   int a = 5;
   cout << "a = " << a << endl;

   int* p = &a;
   cout << "size of p = " << sizeof(p) << endl;
   cout << "p = " << p << endl;
   cout << "value with address p = " << *p << endl;

   *p = 6;
   cout << "a = " << a << endl;


}
