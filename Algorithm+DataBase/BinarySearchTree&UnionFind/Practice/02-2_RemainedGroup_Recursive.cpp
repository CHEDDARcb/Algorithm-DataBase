#include <iostream>
#include <vector>
#include <numeric>      // iota
#include <unordered_map>
#include <string>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rnk;
    vector<char> seen;      // 등장 여부(0/1)
    int groupCount = 0;     // 현재 그룹 수

    DSU(int n) : parent(n), rnk(n, 0), seen(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void touch(int x) {
        if (!seen[x]) {
            seen[x] = 1;
            groupCount++;       // 새 노드가 등장하면 새 그룹 1개
        }
    }

    // 합쳐졌으면 true, 이미 같은 그룹이면 false
    bool unite(int a, int b) {
        touch(a);
        touch(b);

        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;

        groupCount--;           // 두 그룹이 합쳐졌으니 그룹 수 감소
        return true;
    }

    // (옵션) 루트별 멤버 모으기: 마지막에 한 번만 O(V)
    unordered_map<int, vector<int>> buildBuckets() {
        unordered_map<int, vector<int>> bucket;
        bucket.reserve(64);

        for (int x = 0; x < (int)parent.size(); ++x) {
            if (!seen[x]) continue;           // 등장한 노드만
            int root = find(x);
            bucket[root].push_back(x);
        }
        return bucket;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int n;
    //cin >> n;

    DSU dsu(256);

    // 초기 부족 그룹 세팅 (문제 그림 기준)
    // {A,B,C}, {D,E,F}, {G,H}, {I,J} => 총 4그룹이 되지만 하드코딩하지 않고 unite로 자동 계산
    dsu.unite('A', 'B');
    dsu.unite('B', 'C');

    dsu.unite('E', 'F');
    dsu.unite('D', 'E');
    dsu.unite('B', 'D');

    dsu.unite('G', 'H');

    dsu.unite('I', 'J');

    // 추가로 합칠 n개의 입력 처리
    //while (n--) {
    //    char c1, c2;
    //    cin >> c1 >> c2;
    //    dsu.unite((unsigned char)c1, (unsigned char)c2);
    //}

    cout << dsu.groupCount << "개";

    // -------------------------------
    // (옵션) 그룹 멤버를 실제로 보고 싶다면 아래 주석 해제
    auto buckets = dsu.buildBuckets();
    cout << "\n\n[그룹 구성]\n";
    for (auto &kv : buckets) {
        int root = kv.first;
        auto &members = kv.second;
        cout << "root " << char(root) << " : ";
        for (int x : members) cout << char(x) << ' ';
        cout << '\n';
    }
    // -------------------------------

    return 0;
}
