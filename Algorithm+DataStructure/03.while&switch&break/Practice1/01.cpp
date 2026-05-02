#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;

    int cnt = 0;
    while (cnt < a)
    {
        cout << cnt + 1 << " ";
        cnt++;
    }

    return 0;
}