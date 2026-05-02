#include <iostream>

using namespace std;

int main()
{
    int arr[6];

    for (int i = 0; i < 6; ++i)
    {
        cin >> arr[i];
    }

    for (const auto& data : arr)
    {
        if (data == 7)
            break;

        cout << data << " ";
    }
    return 0;
}