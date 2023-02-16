
#include <iostream> 
#include <cstdlib>

using namespace std; 

int main()
{
   cout << "Hello World!\n";
   /////Pointers
   int t = 5;
   cout << "a = " << t << endl;
   cout << "size of x = " << sizeof(t) << endl;

   int* p = &t;
   cout << "p = " << p << endl;
   cout << "value with address p = " << *p << endl;

   *p = 6;
   cout << "a = " << t << endl;

   //Array declaration
   int b[5] = {};
   int c[5] = { 2, 4 };
   int d[] = { 1, 3, 4, 7 };

   for (int i = 0; i < 10; i++) {
       cout << c[i] << " | ";
   }
   cout << endl;

   //c[6] = 10;

   for (int i = 0; i < 10; i++) {
       cout << c[i] << " | ";
   }
   cout << endl;

   cout << c[1000] << endl; //debug - exception occurs here


   //Array addressing
   int x = 10;
   cout << "size of x = " << sizeof(x) << endl;

   int a[5] = { 1, 2, 3, 4, 5 };

   for (int i = 0; i < 5; i++) {
       cout << a[i] << " | ";
   }
   cout << endl;
   for (int i = 0; i < 5; i++) {
       cout << &a[i] << " | ";
   }
   cout << endl;

   cout << *(&a[0] + 1) << endl;



//    int a[5] = { 1, 2, 3, 4, 5 };
//    cout << &a[0]<< endl;
//    cout << (&a[0] + 1) << endl;
//    cout << *(&a[0] + 1) << endl;

}