#include<iostream>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    int hw = 0;
    // 비트연산
    //while (n)
    //{
    //    hw += (n & 1);
    //    n >>= 1;
    //}

    // Brian Kernighan알고리즘
    while (n)
    {
        n &= (n - 1);
        hw++;
    }

    cout << hw;
}