#include <iostream>
#include <vector>

using namespace std;

vector<int> base;
vector<int> dat;
vector<int> result;

int main(void)
{
	int n;
	cin >> n;

	base.resize(n);
	dat.resize(10, 0);
	result.resize(n);

	for (auto& data : base)
		cin >> data;

	for (int i = 0; i < n; ++i)
	{
		dat[base[i]]++;
	}

	for (int i = 1; i < dat.size(); ++i)
	{
		dat[i] += dat[i - 1];;
	}

	for (auto& data : dat)
		cout << data;
	cout << endl;

	for (int i = 0; i < base.size(); ++i)
	{
		int idx = dat[base[i]] - 1;
		result[idx] = base[i];
		dat[base[i]]--;
	}

	for (auto& data : result)
		cout << data;

	return 0;
}