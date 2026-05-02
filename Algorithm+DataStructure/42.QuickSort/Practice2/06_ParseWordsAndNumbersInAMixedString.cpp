#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string input;
	cin >> input;

	vector<string> results;
	int i = 0;
	while (i < input.size())
	{
		string result;

		int j = i;
		while (j < input.size() &&
			input[j] >= 'A' && input[j] <= 'Z')
			++j;
		string name = input.substr(i, j - i);

		i = j;
		while (j < input.size() &&
			input[j] >= '0' && input[j] <= '9')
			++j;
		string num = input.substr(i, j - i);

		i = j;

		int n = stoi(num);
		n += 17;
		num = to_string(n);

		result = name;
		result.push_back('#');
		result.append(num);

		results.push_back(result);
	}

	for (auto& re : results)
		cout << re << endl;

	return 0;
}