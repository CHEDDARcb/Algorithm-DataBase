#include <iostream>

using namespace std;

int main()
{
    int a = 3;
    char gd = 'A';

    int* p = &a;
    char* t = &gd;

    cout << *p << " " << *t;

    return 0;
}