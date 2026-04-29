#include <iostream>
#include <unordered_set>

using namespace std;

const string strs[5] =
{
	"1011",
	"0011",
	"1111",
	"0000",
	"1100"
};
unordered_set<string> uos;

void Init()
{
	for (int i = 0; i < 5; ++i)
		uos.insert(strs[i]);
}

int main(void)
{
	Init();

	bool isFind = false;
	for (int i = 0; i < 5; ++i)
	{
		string input;
		cin >> input;

		if (uos.find(input) != uos.end())
			isFind = true;
	}

	cout << (isFind ? "yes" : "no");

	return 0;
}