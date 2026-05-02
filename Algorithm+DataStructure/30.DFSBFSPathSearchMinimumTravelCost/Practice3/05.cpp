#include <iostream>
#include <vector>

using namespace std;

int y, x;
vector<vector<int>> arr;
vector<vector<bool>> visited;
struct Result
{
	int data;
	int i;
	int j;
};
ostream& operator<<(ostream& os, const Result& r)
{
	os << r.data << "(" << r.i << "," << r.j << ")";
	return os;
}

void Input()
{
	cin >> y >> x;

	visited.resize(y, vector<bool>(x, false));
	arr.resize(y, vector<int>(x, 0));

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> arr[i][j];
		}
	}
}
Result FindMax()
{
	int maxI = 0;
	int maxJ = 0;
	for (int i = 0; i < y; ++i)
	{
		for (int j = 1; j < x; ++j)
		{
			if (visited[i][j]) continue;

			if (arr[maxI][maxJ] < arr[i][j])
			{
				maxI = i;
				maxJ = j;
			}
		}
	}

	visited[maxI][maxJ] = true;

	return Result{ arr[maxI][maxJ], maxI, maxJ };
}

int main()
{
	Input();

	int n = 3;
	while (n--)
	{
		cout << FindMax() << endl;
	}
}