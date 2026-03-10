#include <iostream>
#include <unordered_set>

using namespace std;

string str1, str2;

int main(void)
{
	cin >> str1 >> str2;

	unordered_set<string> s1, s2;
	for (int i = 0; i < str1.size() - 1; ++i)
	{
		string str;
		str.push_back(str1[i]);
		str.push_back(str1[i + 1]);

		s1.insert(str);
	}

	for (int i = 0; i < str2.size() - 1; ++i)
	{
		string str;
		str.push_back(str2[i]);
		str.push_back(str2[i + 1]);

		s2.insert(str);
	}

	int intersect = 0;
	for (const auto& s : s1)
	{
		if (s2.find(s) != s2.end())
			++intersect;
	}

	int result = 0;
	int uni = s1.size() + s2.size() - intersect;
	if (uni > 0)
		result = float(intersect) / uni * 100;

	cout << result;

	return 0;
}