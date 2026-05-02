#include <iostream>

using namespace std;

void printData(int _data)
{
    cout << _data << endl;
}

void odd(int _n)
{
    printData(_n - 10);
}

void even(int _n)
{
    printData(_n * 2);
}

int main()
{
    int a, b;

    cin >> a >> b;
    int div = a / b;

    if (div % 2)
    {
        odd(div);
    }
    else
    {
        even(div);
    }
    printData(a + b);

    return 0;
}