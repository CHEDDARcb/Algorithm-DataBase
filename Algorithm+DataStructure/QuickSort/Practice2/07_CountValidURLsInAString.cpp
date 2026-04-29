#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    string input;
    cin >> input;

    const vector<string> s =
    {
        "http://",
        "https://"
    };
    const vector<string> e =
    {
        ".com",
        ".co.kr",
        ".org",
        ".net"
    };

    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
            input[i] = input[i] - 'A' + 'a';
    }

    int cnt = 0;    
    int pos = 0;

    while (pos < input.size())
    {
        int startIdx = string::npos;
        string startWord;

        for (int i = 0; i < s.size(); ++i)
        {
            int idx = input.find(s[i], pos);
            if (idx != string::npos)
            {
                if (startIdx == string::npos || idx < startIdx)
                {
                    startIdx = idx;
                    startWord = s[i];
                }
            }
        }

        if (startIdx == string::npos)
            break;

        int contentStart = startIdx + startWord.size();

        int endIdx = string::npos;
        int endLen = 0;

        for (int i = 0; i < e.size(); ++i)
        {
            int idx = input.find(e[i], contentStart);
            if (idx != string::npos)
            {
                if (endIdx == string::npos || idx < endIdx)
                {
                    endIdx = idx;
                    endLen = e[i].size();
                }
            }
        }

        if (endIdx != string::npos)
        {
            int middleLen = endIdx - contentStart;
            if (middleLen >= 3)
            {
                ++cnt;
                pos = endIdx + endLen;
            }
            else
            {
                pos = startIdx + 1;
            }
        }
        else
        {
            pos = startIdx + 1;
        }
    }

    cout << cnt;
    return 0;
}