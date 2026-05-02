#include <iostream>

using namespace std;

int main()
{
	int vect[8];

	for (auto& data : vect)
		cin >> data;

	int bucket[10]{};

	for (const auto& data : vect)
	{
		++bucket[data];
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < bucket[i]; ++j)
		{
			cout << i << " ";
		}
	}

	return 0;
}