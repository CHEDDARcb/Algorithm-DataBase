#include <iostream>

using namespace std;

int main()
{
	const char base[4][5][3] =
	{
		{' ', '#', ' ',
		 '#', ' ', '#',
		 '#', '#', '#',
		 '#', ' ', '#',
		 '#', ' ', '#',
		},
		{'B', 'B', 'B',
		 'B', ' ', 'B',
		 'B', 'B', 'B',
		 'B', ' ', 'B',
		 'B', 'B', 'B'
		},
		{'C', 'C', 'C',
		 'C', ' ', 'C',
		 'C', ' ', ' ',
		 'C', ' ', 'C',
		 'C', 'C', 'C'
		},
		{'D', 'D', ' ',
		 'D', ' ', 'D',
		 'D', ' ', 'D',
		 'D', ' ', 'D',
		 'D', 'D', ' '}
	};
	int input;

	cin >> input;

	for (const auto& row : base[input])
	{
		for (const auto data : row)
		{
			cout << data;
		}
		cout << endl;
	}

	return 0;
}