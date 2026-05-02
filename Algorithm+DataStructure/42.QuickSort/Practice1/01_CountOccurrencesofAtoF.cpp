#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
	unordered_map<char, int> uom;
	string input;

	cin >> input;

	for (auto& data : input)
	{
		char idx = data;
		if (idx >= 'a' && idx <= 'f')
		{
			idx -= 'a';
			idx += 'A';
		}
		if (idx >= 'A' && idx <= 'Z')
			uom[idx]++;
	}

	for (char i = 'A'; i <= 'F'; ++i)
	{
		cout << i << ": ";
		if (uom.find(i) == uom.end())
			cout << 0 << endl;
		else
			cout << uom[i] << endl;
	}
}