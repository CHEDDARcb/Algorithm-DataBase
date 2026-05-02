#include <iostream>

using namespace std;
string input;

int main(void)
{
	cin >> input;

	cout << input << endl;

	int alphaCount = input.size();
	while (alphaCount)
	{
		for (int i = 0; i < input.size(); ++i)
		{
			char& c = input[i];
			if (c >= 'A' && c <= 'Z')
			{
				--c;
				if (c < 'A' || c > 'Z')
				{
					c = '_';
					--alphaCount;
				}
			}
		}
		cout << input << endl;
	}
	return 0;
}