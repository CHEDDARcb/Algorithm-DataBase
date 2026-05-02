#include<iostream>

using namespace std;

bool isSame(const char* name1, const char* name2)
{
	int idx = 0;
	while (name1[idx] != '\0' && name2[idx] != '\0')
	{
		if (name1[idx] != name2[idx])
			return false;
		++idx;
	}

	return name1[idx] == name2[idx];
}

int main()
{
	char names[2][100]{};

	for (auto& name : names)
		cin >> name;

	if (isSame(names[0], names[1]))
		cout << "동명";
	else
		cout << "남남";

	return 0;
}