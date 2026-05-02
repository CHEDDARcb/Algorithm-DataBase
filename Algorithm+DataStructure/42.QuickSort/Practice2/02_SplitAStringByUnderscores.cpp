#include <iostream>

using namespace std;

int main(void)
{
	string input;
	cin >> input;

	int num = 1;
	for (int i = 0; i < input.size();)
	{
		int j = i;
		while (j < input.size() &&
			input[j] != '_')
			++j;

		string sub = input.substr(i, j - i);
		cout << num << "#" << sub << endl;

		++num;
		while (j < input.size() &&
			input[j] == '_')
			++j;
		i = j;
	}

	return 0;
}