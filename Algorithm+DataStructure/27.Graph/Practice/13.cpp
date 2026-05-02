#include <iostream>
#include <vector>

using namespace std;

string names[5] =
{
	"A"
	"B"
	"C"
	"D"
	"E"
};

vector<vector<int>> graph =
{
	{0, 1, 7, 2, 0},
	{1, 0, 8, 0, 5},
	{7, 8, 0, 3, 6},
	{2, 0, 3, 0, 0},
	{0, 5, 6, 0, 0}

};

int main()
{
	for (int i = 0; i < graph.size(); ++i)
	{
		for (int j = 1 + i; j < graph[i].size(); ++j)
		{
			cout << char('A' + i) << " " << char('A' + j) << " " << graph[i][j] << endl;
		}
	}

	return 0;
}