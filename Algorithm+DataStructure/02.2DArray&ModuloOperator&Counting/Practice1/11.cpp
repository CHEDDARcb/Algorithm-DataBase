#include <iostream>

using namespace std;

int arr[3][3];
int num;

void input()
{
	cin >> num;
}

void process()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr[i][j] = num++;
		}
	}
}

void output()
{
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data << "	";
		}
		cout << endl;
	}
}

int main(void)
{
	input();
	process();
	output();

	return 0;
}