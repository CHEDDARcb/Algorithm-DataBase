#include <iostream>
#include <queue>
using namespace std;

const int N = 5;

const int dir[5][2] =
{
    {0, 0},
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int map[N][N] =
{
    {0, 0, 0, 3, 0},
    {0, 0, 0, 3, 0},
    {3, 3, 0, 0, 0},
    {0, 0, 3, 0, 0},
    {0, 0, 0, 0, 0}
};

bool visited[N][N][N][N];

struct Node
{
    int ey, ex;
    int ay, ax;
    int time;
};

int ey, ex, ay, ax;

int BFS()
{
    queue<Node> q;
    q.push({ ey, ex, ay, ax, 0 });
    visited[ey][ex][ay][ax] = true;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if (cur.ey == cur.ay && cur.ex == cur.ax)
            return cur.time;

        for (int i = 0; i < 5; ++i)
        {
            int ney = cur.ey + dir[i][0];
            int nex = cur.ex + dir[i][1];

            if (ney < 0 || ney >= N || nex < 0 || nex >= N)
                continue;
            if (map[ney][nex] == 3)
                continue;

            for (int j = 0; j < 5; ++j)
            {
                int nay = cur.ay + dir[j][0];
                int nax = cur.ax + dir[j][1];

                if (nay < 0 || nay >= N || nax < 0 || nax >= N)
                    continue;
                if (map[nay][nax] == 3)
                    continue;

                if (visited[ney][nex][nay][nax])
                    continue;

                visited[ney][nex][nay][nax] = true;
                q.push({ ney, nex, nay, nax, cur.time + 1 });
            }
        }
    }

    return -1;
}

int main()
{
    cin >> ey >> ex >> ay >> ax;

    int result = BFS();
    cout << result;

    return 0;
}