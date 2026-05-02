#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> uom =
{
	make_pair("KFC", "#BBQ#"),
	make_pair("MC", "#BBQ#"),
	make_pair("BICMAC", "#MACBOOK#"),
	make_pair("SHACK", "#SHOCK#"),
	make_pair("SONY", "#NONY#"),
};

int main(void)
{
	string input;

	cin >> input;

	for (auto& data : uom)
	{
		int start = 0;
		while(start < input.size())
		{
			int idx = input.find(data.first, start);
			if (idx == string::npos)
				break;

			input.erase(idx, data.first.size());
			input.insert(idx, data.second);

			start = idx + data.second.size();
		}
	}

	cout << input;

	return 0;
}