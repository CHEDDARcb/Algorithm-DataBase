#include <iostream>

using namespace std;

struct IdxNLen
{
	IdxNLen& operator=(const IdxNLen& il)
	{
		len = il.len;
		idx = il.idx;

		return *this;
	}

	int len;
	int idx;
};

void Sort(IdxNLen* _base, int _size)
{
	for (int i = 0; i < _size - 1; ++i)
	{
		for (int j = 0; j < _size - 1 - i; ++j)
		{
			if (_base[j].len > _base[j + 1].len)
			{
				IdxNLen tmp = _base[j];
				_base[j] = _base[j + 1];
				_base[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	char strs[4][11];
	IdxNLen sortIdx[4];

	for (int i = 0; i < 4; ++i)
	{
		cin >> strs[i];
		sortIdx[i].len = strlen(strs[i]);
		sortIdx[i].idx = i;
	}

	Sort(sortIdx, 4);

	for (int i = 0; i < 4; ++i)
	{
		cout << strs[sortIdx[i].idx] << endl;
	}

	return 0;
}