#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int* pa = &a;
    int* pb = &b;

    int temp = *pa;
    *pa = *pb;
    *pb = temp;

    cout << a << " " << b;

    return 0;
}