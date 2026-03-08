#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    long long prevMax = LLONG_MIN;
    long long prevMin = LLONG_MAX;

    // 첫 번째 행 초기화
    for (int j = 0; j < n; ++j) {
        prevMax = max(prevMax, a[0][j]);
        prevMin = min(prevMin, a[0][j]);
    }

    // 2번째 행부터
    for (int i = 1; i < n; ++i) {
        long long curMax = LLONG_MIN;
        long long curMin = LLONG_MAX;

        for (int j = 0; j < n; ++j) {
            long long x = a[i][j];

            long long c1 = prevMax * x;
            long long c2 = prevMin * x;

            curMax = max(curMax, max(c1, c2));
            curMin = min(curMin, min(c1, c2));
        }

        prevMax = curMax;
        prevMin = curMin;
    }

    cout << prevMax << '\n';
    return 0;
}