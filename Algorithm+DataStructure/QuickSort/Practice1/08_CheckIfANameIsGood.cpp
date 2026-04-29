#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	while (n--)
	{
		string input;
		cin >> input;

		unordered_map<char, int> uom;
		int i = 0;
		for (; i < input.size(); ++i)
		{
			if (input[i] < 'a' || input[i] > 'z')
				break;

			uom[input[i]]++;
			if (uom[input[i]] > 2)
				break;
		}

		int vowelsCnt =
			uom['a'] + uom['e'] + uom['i']
			+ uom['o'] + uom['u'];

		if (i != input.size() || vowelsCnt != 3)
			cout << "no" << endl;
		else
			cout << "good" << endl;
	}

	return 0;
}