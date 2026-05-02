#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int comp(int a, int b)
{
    return a - b;
}

void print(int sum, int comp)
{
    cout << "ÇÕ:" << sum << endl;
    cout << "Â÷:" << comp << endl;
}

int main()
{
    int a;
    int b;

    cin >> a >> b;

    print(sum(a, b), comp(a, b));

    return 0;
}