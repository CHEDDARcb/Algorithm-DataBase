#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> neg, pos;
    int zeroCnt = 0;

    for (int i = 0; i < N; ++i) {
        long long x;
        cin >> x;
        if (x < 0) neg.push_back(x);
        else if (x == 0) zeroCnt++;
        else pos.push_back(x);
    }

    // 음수: 절댓값 큰 순 / 작은 순
    vector<long long> negBig = neg;
    vector<long long> negSmall = neg;

    sort(negBig.begin(), negBig.end(),
        [](long long a, long long b) {
            return llabs(a) > llabs(b);
        });

    sort(negSmall.begin(), negSmall.end(),
        [](long long a, long long b) {
            return llabs(a) < llabs(b);
        });

    // 양수: 큰 순 / 작은 순
    vector<long long> posBig = pos;
    vector<long long> posSmall = pos;

    sort(posBig.begin(), posBig.end(), greater<long long>());
    sort(posSmall.begin(), posSmall.end());

    // prefix product
    vector<long long> prefNegBig(negBig.size() + 1, 1);
    vector<long long> prefNegSmall(negSmall.size() + 1, 1);
    vector<long long> prefPosBig(posBig.size() + 1, 1);
    vector<long long> prefPosSmall(posSmall.size() + 1, 1);

    for (int i = 1; i <= (int)negBig.size(); ++i)
        prefNegBig[i] = prefNegBig[i - 1] * negBig[i - 1];

    for (int i = 1; i <= (int)negSmall.size(); ++i)
        prefNegSmall[i] = prefNegSmall[i - 1] * negSmall[i - 1];

    for (int i = 1; i <= (int)posBig.size(); ++i)
        prefPosBig[i] = prefPosBig[i - 1] * posBig[i - 1];

    for (int i = 1; i <= (int)posSmall.size(); ++i)
        prefPosSmall[i] = prefPosSmall[i - 1] * posSmall[i - 1];

    // Case A: 음수 답 가능한지 확인
    bool hasNegative = false;
    long long bestNegative = LLONG_MAX;

    for (int k = 1; k <= min((int)neg.size(), M); k += 2) {
        int p = M - k;
        if (p <= (int)pos.size()) {
            long long val = prefNegBig[k] * prefPosBig[p];
            if (!hasNegative || val < bestNegative) {
                bestNegative = val;
                hasNegative = true;
            }
        }
    }

    if (hasNegative) {
        cout << bestNegative;
        return 0;
    }

    // Case B: 음수 불가능하고 0이 있으면 0
    if (zeroCnt > 0) {
        cout << 0;
        return 0;
    }

    // Case C: 양수 중 최소
    bool hasPositive = false;
    long long bestPositive = LLONG_MAX;

    for (int k = 0; k <= min((int)neg.size(), M); k += 2) {
        int p = M - k;
        if (p <= (int)pos.size()) {
            long long val = prefNegSmall[k] * prefPosSmall[p];
            if (!hasPositive || val < bestPositive) {
                bestPositive = val;
                hasPositive = true;
            }
        }
    }

    cout << bestPositive;
    return 0;
}