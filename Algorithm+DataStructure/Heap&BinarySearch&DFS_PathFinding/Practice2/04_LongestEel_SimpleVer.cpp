#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string eel;
    cin >> eel;

    int cur = 0;
    int best = 0;
    int curStart = 0;
    int bestL = -1, bestR = -1;

    for (int i = 0; i < (int)eel.size(); ++i) 
    {
        if (eel[i] == '~') 
        {
            if (cur == 0) 
                curStart = i; // 새 구간 시작

            cur++;
            if (cur > best) {
                best = cur;
                bestL = curStart;
                bestR = i;
            }
        }// '#'
        else
        {
            cur = 0;
        }
    }

    // ~가 하나도 없으면 아무것도 출력하지 않음 (문제 요구에 맞게 조정 가능)
    if (bestL == -1) return 0;

    for (int i = bestL; i <= bestR; ++i) cout << eel[i];
    return 0;
}