#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	string input;
	int start;
	string command;
	list<char> str;

	cin >> input >> start >> command;

	for (int i = 0; i < input.size(); ++i)
	{
		str.push_back(input[i]);
	}
	list<char>::iterator cur = b;
	advance(cur, start);

	for (int i = 0; i < command.size(); ++i)
	{
		if (command[i] == 'L' && cur != str.begin())
			advance(cur, -1);
		else if (command[i] == 'R' && cur != str.end())
			advance(cur, 1);
		else if (command[i] == 'D' && cur != str.end())
			cur = str.erase(cur);
	}

	cout << distance(str.begin(), cur);

	return 0;
}