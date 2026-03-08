#include <iostream>
#include <algorithm>
#include <vector>

struct Node
{
	char v1;
	char v2;
	int cost;
};

std::vector<Node> graph =
{
	{'A', 'B', 6},
	{'A', 'C', 4},
	{'A', 'D', 5},
	{'C', 'B', 1},
	{'C', 'D', 3},
	{'C', 'E', 7},
	{'E', 'B', 3},
	{'E', 'D', 1},
};

int n = 8;

bool compare(Node a, Node b)
{
	return a.cost < b.cost;
}

int org[200] = {};
int findParent(int now)
{
	if (org[now] == 0)
		return now;

	int ret = findParent(org[now]);
	org[now] = ret;

	return ret;
}

int unionOrg(int v1, int v2)
{
	int p1 = findParent(v1);
	int p2 = findParent(v2);

	if (p1 == p2)
		return 0;

	org[p1] = p2;
	return 1;
}

int main()
{
	std::sort(graph.begin(), graph.end(), compare);

	int cnt = 0;
	int sum = 0;

	for (size_t i = 0; i < graph.size(); ++i)
	{
		if (unionOrg(graph[i].v1, graph[i].v2))
		{
			sum += graph[i].cost;
			cnt++;
		}
	}

	if (cnt == 4)
	{
		std::cout << sum << std::endl;
	}

	return 0;
}
