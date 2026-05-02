#include <iostream>

using namespace std;

struct DataCount
{
	int data;
	int count = 0;
};

int arr[2][6] =
{
	{4, 5, 6, 1, 3, 1},
	{2, 1, 3, 6, 3, 6}
};

void input(DataCount dc[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> dc[i].data;
	}
}

void process(DataCount dc[], int size)
{
	for (int z = 0; z < size; ++z)
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (arr[i][j] == dc[z].data)
					++dc[z].count;
			}
		}
	}
}

void output(DataCount dc[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << dc[i].data << "=" << dc[i].count << "°³" << endl;
	}
}

int main(void)
{
	DataCount dc[3];
	int size = 3;

	input(dc, size);
	process(dc, size);
	output(dc, size);

	return 0;
}