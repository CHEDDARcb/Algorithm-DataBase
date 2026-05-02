#include <iostream>

using namespace std;

int vect[2][5] =
{
    {3, 2, 6, 2, 4},
    {1, 4, 2, 6, 5}
};

int KFC(int target)
{
    for (const auto& row : vect)
    {
        for (const auto& data : row)
        {
            if (data == target)
                return 1;
        }
    }

    return 0;
}

int main()
{
    int input;

    cin >> input;

    int result = KFC(input);

    if (result)
        cout << "값이 존재합니다" << endl;
    else
        cout << "값이 없습니다" << endl;

    return 0;
}
