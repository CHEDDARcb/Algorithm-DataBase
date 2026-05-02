#include <iostream>

using namespace std;

char arr[3][3] =
{
	{'a', 'b', 'd'},
	{'e', 'w', 'z'},
	{'q', 'v', 'a'},
};

char Input()
{
	char input;

	cin >> input;

	return input;
}

void Process(char input)
{
	input = static_cast<char>(input - 'A' + 'a');

	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data == input)
			{
				cout << "존재";
				return;
			}
		}
	}

	cout << "없음";

	return;
}


int main(void)
{
	Process(Input());

	return 0;
}