#include <iostream>

using namespace std;

int main(void)
{
	int input;

	cin >> input;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << input;
		}
		--input;
		cout << endl;
	}
}