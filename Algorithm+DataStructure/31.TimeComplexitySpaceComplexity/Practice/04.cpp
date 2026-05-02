#include <iostream> 
#include <vector>

using namespace std;

vector<string> strs(5);

void Input()
{
	for (int i = 0; i < 5; ++i)
	{
		cin >> strs[i];
	}
}

void Change()
{
	for (int i = 0; i < 5; ++i)
	{
		char tmp = strs[i][1];
		strs[i][1] = strs[i][3];
		strs[i][3] = tmp;
	}
}

bool FindMAPOM()
{
	for (int i = 0; i < 5; ++i)
	{
		if (strs[i] == "MAPOM")
			return true;
	}

	return false;
}

int main()
{
	Input();
	Change();

	if (FindMAPOM())
		cout << "yes";
	else
		cout << "no";

	return 0;
}