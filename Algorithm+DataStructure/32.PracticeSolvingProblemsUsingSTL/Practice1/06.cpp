#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p;
struct Data
{
	vector<string> names;
	int n = 0;
};
vector<Data> giins;

int main(void)
{
	cin >> n >> p;

	giins.resize(n);

	for (int i = 0; i < p; ++i)
	{
		int giin;
		string name;

		cin >> giin >> name;

		giins[giin].names.push_back(name);
		giins[giin].n++;
	}

	auto result = max_element(giins.begin(), giins.end(),
		[](const Data& a, const Data& b) {
			return a.n < b.n;
		});

	for (auto name : (*result).names)
		cout << name << " ";

	return 0;

}