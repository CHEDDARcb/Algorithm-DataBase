#include <iostream>

using namespace std;

int main(void)
{
	char arr[3][3] =
	{
		{'A', 'B', 'C'},
		{'D', 'E', 'F'},
		{'G', 'H', 'I'}
	};
	int inputY1, inputX1;
	int inputY2, inputX2;

	cin >> inputY1 >> inputX1 >> inputY2 >> inputX2;

	char temp = arr[inputY1][inputX1];
	arr[inputY1][inputX1] = arr[inputY2][inputX2];
	arr[inputY2][inputX2] = temp;

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			cout << data << " ";
		}
		cout << endl;
	}

	return 0;
}