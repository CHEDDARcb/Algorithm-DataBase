#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
    string input;
    cin >> input;

    // 1. 금지 단어 검사
    if (input.find("bad") != string::npos ||
        input.find("no") != string::npos ||
        input.find("puck") != string::npos)
    {
        cout << "fail";
        return 0;
    }

    // 2. 연속된 '_' 5개 이하
    int underbarCnt = 0;

    // 3. 모든 알파벳 5회 이하
    unordered_map<char, int> alphaCnt;

    for (char ch : input)
    {
        // 4. 숫자 없어야 함
        if ('0' <= ch && ch <= '9')
        {
            cout << "fail";
            return 0;
        }

        if (ch == '_')
        {
            ++underbarCnt;
            if (underbarCnt > 5)
            {
                cout << "fail";
                return 0;
            }
        }
        else
        {
            underbarCnt = 0;
        }

        if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
        {
            alphaCnt[ch]++;
            if (alphaCnt[ch] > 5)
            {
                cout << "fail";
                return 0;
            }
        }
    }

    cout << "pass";

    return 0;
}