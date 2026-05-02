#include <iostream>

using namespace std;

struct sketchbook
{
	char image[3][3];
};

void SearchPattern(const sketchbook& _skchbk, int _bucket[])
{
	int row = sizeof(_skchbk.image) / sizeof(_skchbk.image[0]);
	int col = sizeof(_skchbk.image[0]) / sizeof(char);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int idx = static_cast<int>(_skchbk.image[i][j]);
			++_bucket[idx];
		}
	}
}

int main()
{
	sketchbook skchbk;

	for (auto& row : skchbk.image)
		for (auto& data : row)
			cin >> data;

	int bucket[256]{};
	SearchPattern(skchbk, bucket);

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (bucket[i])
			cout << static_cast<char>(i);
	}

	return 0;
}