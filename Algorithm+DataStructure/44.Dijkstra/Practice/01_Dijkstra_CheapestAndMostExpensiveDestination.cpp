#include <iostream>
#include <queue>
#include <vector>

const int NOT = 999999;
const int INF = 9876543421;

using namespace std;

int board[5][5] =
{
	{0, 25, 100, 10, 30},
	{NOT, 0, 10, NOT, NOT},
	{NOT, NOT, 0, NOT, NOT},
	{NOT, NOT, NOT, 0, 5},
	{NOT, 5, NOT, NOT, 0}
};
vector<int> result(5);

void Dijkstra(int start)
{
	for (int i = 0; i < result.size(); ++i)
		result[i] = INF;

	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	result[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int currentCost = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (currentCost > result[currentNode])
			continue;

		for (int nextNode = 0; nextNode < result.size(); ++nextNode)
		{
			if (board[currentNode][nextNode] == NOT ||
				board[currentNode][nextNode] == 0)
				continue;

			int nextCost = currentCost + board[currentNode][nextNode];

			if (nextCost < result[nextNode])
			{
				result[nextNode] = nextCost;
				pq.push({ nextCost, nextNode });
			}
		}
	}
}

int main(void)
{
	int start = 0;

	Dijkstra(start);

	char nodes[5] = { 'A', 'B', 'C', 'D', 'E' };
	int mxIdx = 1;
	int mnIdx = 1;
	for (int i = 1; i < 5; ++i)
	{
		if (result[i] == INF)
			continue;

		if (mnIdx == -1 || result[i] < result[mnIdx])
			mnIdx = i;

		if (mxIdx == -1 || result[i] > result[mxIdx])
			mxIdx = i;
	}
	cout << nodes[mnIdx] << '(' << result[mnIdx] << ')' << endl;
	cout << nodes[mxIdx] << '(' << result[mxIdx] << ')' << endl;

	return 0;
}