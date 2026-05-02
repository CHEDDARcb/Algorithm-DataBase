#include <iostream>

using namespace std;

int main()
{
    char a, b, c;

    cin >> a >> b >> c;

    char* pa = &a;
    char* pb = &b;
    char* pc = &c;

    (*pa)++;
    (*pb)++;
    (*pc)++;

    cout << *pa << " " << *pb << " " << *pc;

    return 0;
}