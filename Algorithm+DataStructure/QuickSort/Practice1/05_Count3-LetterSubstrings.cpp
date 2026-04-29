#include <iostream>
#include <unordered_map>

using namespace std;

const string str = "BOBOOBOBOBOBBM";
unordered_map<string, int> uom;

void Init()
{
	for (int i = 0; i <= str.size() - 3; ++i)
	{
		string sub = str.substr(i, 3);
		uom[sub]++;
	}
}

int main(void)
{
	Init();

	int n;
	cin >> n;
	while (n--)
	{
		string input;
		cin >> input;

		if (uom.find(input) != uom.end())
			cout << uom[input] << endl;
		else
			cout << 0 << endl;
	}
}