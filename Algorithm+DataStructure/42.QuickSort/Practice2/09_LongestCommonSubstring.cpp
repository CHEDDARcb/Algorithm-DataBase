#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;

    string A, B;
    if (str1.size() >= str2.size())
    {
        A = str1;
        B = str2;
    }
    else
    {
        A = str2;
        B = str1;
    }

    for (int len = B.size(); len >= 1; --len)
    {
        for (int start = 0; start + len <= B.size(); ++start)
        {
            string sub = B.substr(start, len);
            if (A.find(sub) != string::npos)
            {
                cout << sub;
                return 0;
            }
        }
    }

    return 0;
}