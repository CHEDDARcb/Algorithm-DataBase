#include <iostream>

using namespace std;

int input()
{
    int a;
    cin >> a;

    return a;
}

void cals(int _a, int _b, int _c)
{
    cout << _a + _b + _c;
}
int main()
{
    int a = input();
    int b = input();
    int c = input();

    cals(a, b, c);

    return 0;
}