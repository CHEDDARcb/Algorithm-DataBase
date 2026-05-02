#include <iostream>
#include <vector>

using namespace std;

int passNum;
vector<string> passws;
const int alphaNum = 26;

void Input()
{
	cin >> passNum;

	passws.resize(passNum);
	for (int i = 0; i < passws.size(); ++i)
	{
		cin >> passws[i];
	}
}

int main()
{
	Input();

	for (const auto& pass : passws)
	{
		int result = 0;
		for (auto c : pass)
		{
			result = result * alphaNum + (c - 'A');
		}

		cout << result + 1 << endl;
	}

	return 0;
}