#include <iostream>
#include <vector>

using namespace std;

vector<int> value(5, 0);
vector<int> path(5, 0);
int cnt = 0;

void Input()
{
    for (int i = 0; i < value.size(); ++i)
    {
        cin >> value[i];
    }
}

void Combiantion_NoMultiple(int start, int curSum, int curLev, bool isOver)
{
    if (curSum >= 10 && curSum <= 20)
        cnt++;
    if (isOver || curLev == 5)
        return;

    for (int i = start; i < value.size(); ++i)
    {
        path[curLev] = value[i];

        if (curSum + value[i] > 20)
            isOver = true;

        Combiantion_NoMultiple(i + 1, curSum + value[i], curLev + 1, isOver);

        isOver = false;
        path[curLev] = 0;
    }
}

int main(void)
{
    Input();

    Combiantion_NoMultiple(0, 0, 0, false);

    cout << cnt;
    return 0;
}