#include <iostream>

using namespace std;

int n1, n2;

void input()
{
    cin >> n1 >> n2;
}

void output()
{
    int sum = n1 + n2;
    int start = 5;

    if (sum >= 5)
    {
        while (start <= sum)
        {
            cout << start++ << " ";
        }
    }
    else
    {
        while (start >= sum)
        {
            cout << start-- << " ";
        }
    }
}
int main()
{
    input();
    output();

    return 0;
}