#include <iostream>

using namespace std;

int main(void)
{
	char arr[7] = { 'A', '1', '1', '1', '5', 'A', 'W' };
	char input;

	cin >> input;

	int count = 0;

	for (const auto& data : arr)
	{
		if (input == data)
			count++;
	}

	if (count >= 3)
	{
		cout << "THREE" << endl;
	}
	else if (count == 2)
	{
		cout << "TOW" << endl;
	}
	else if (count == 1)
	{
		cout << "ONE" << endl;
	}
	else
	{
		cout << "NOTHING";
	}
	return 0;
}
