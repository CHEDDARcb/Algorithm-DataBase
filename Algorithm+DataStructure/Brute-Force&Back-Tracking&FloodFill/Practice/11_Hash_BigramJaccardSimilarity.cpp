#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, int> h;
unordered_set<string> pushed;
string str1, str2;

int main(void)
{
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size() - 1; ++i)
	{
		string str;
		str.push_back(str1[i]);
		str.push_back(str1[i + 1]);

		if (pushed.find(str) != pushed.end())
			continue;

		h[str]++;
		pushed.insert(str);
	}

	pushed.clear();
	for (int i = 0; i < str2.size() - 1; ++i)
	{
		string str;
		str.push_back(str2[i]);
		str.push_back(str2[i + 1]);

		if (pushed.find(str) != pushed.end())
			continue;

		h[str]++;
		pushed.insert(str);
	}

	int uni = h.size();
	int intersect = 0;
	for (auto iter = h.begin(); iter != h.end(); ++iter)
	{
		if ((*iter).second >= 2)
			++intersect;
	}

	int result = float(intersect) / uni * 100;

	cout << result;

	return 0;
}