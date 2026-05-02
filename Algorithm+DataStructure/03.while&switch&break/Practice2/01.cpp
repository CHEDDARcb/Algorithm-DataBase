#include <iostream>

using namespace std;

int main(void)
{
	int arr[6];

	for (int i = 0; i < 6; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << i << "번은 " << arr[i] << "점 ";

		if (arr[i] < 5)
			cout << "불합격" << endl;
		else
			cout << "합격" << endl;
	}

	return 0;
}