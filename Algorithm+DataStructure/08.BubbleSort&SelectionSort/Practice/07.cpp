#include <iostream>

using namespace std;

void Magic(int (*arr)[3])
{
	int data = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			arr[i][j] = data++;
		}
	}
}

void Output(int (*arr)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == 0)
				cout << " ";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}

int main(void)
{
	int arr[3][3]{};

	Magic(arr);
	Output(arr);

	return 0;
}