#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int k, n;

void Input()
{
	cin >> n >> k;
	arr.resize(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}
}

void Rotate()
{
	int rotate = k % 4;

	while (rotate--)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = 1 + i; j < arr[i].size(); ++j)
			{
				int tmp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = tmp;
			}
		}

		for (int i = 0; i < arr.size(); ++i)
		{
			reverse(arr[i].begin(), arr[i].end());
		}
	}
}

int main(void)
{
	Input();
	Rotate();

	for (auto& row : arr)
	{
		for (auto& data : row)
			cout << data << " ";
		cout << endl;
	}

	return 0;
}