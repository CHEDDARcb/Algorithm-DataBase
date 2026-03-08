#include <iostream>
#include <vector>

using namespace std;

vector<int> graph = { 0, 3, 2, 5, 1, 6, 0, 7, 0, 0, 0, 0, 0, 0, 4, 8 };

void DFS(int curIdx)
{
	if (curIdx >= graph.size() || graph[curIdx] == 0)
		return;

	int lIdx = curIdx * 2;
	int rIdx = curIdx * 2 + 1;

	DFS(lIdx);
	DFS(rIdx);

	cout << graph[curIdx] << " ";
}

int main(void)
{
	DFS(1);

	return 0;
}