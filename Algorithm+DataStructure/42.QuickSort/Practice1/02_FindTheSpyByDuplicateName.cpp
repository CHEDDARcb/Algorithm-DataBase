#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<int>> uom;
int n;
string spyKey;

int Partition(int left, int right)
{
	auto& vect = uom[spyKey];
	int pivot = vect[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot > vect[low])
			++low;
		while (high >= left + 1 && pivot < vect[high])
			--high;

		if(low <= high)
			swap(vect[low], vect[high]);
	}

	swap(vect[left], vect[high]);

	return high;
}

void QuickSort(int left, int right)
{
	if (left >= right)
		return;

	int pivot = Partition(left, right);
	QuickSort(left, pivot - 1);
	QuickSort(pivot + 1, right);
}

int main(void)
{
	cin >> n;

	while (n--)
	{
		string name;
		int age;

		cin >> name >> age;

		if (uom.find(name) != uom.end())
			spyKey = name;

		uom[name].push_back(age);
	}

	QuickSort(0, uom[spyKey].size() - 1);

	cout << spyKey << endl;
	for (auto& data : uom[spyKey])
		cout << data << " ";

	return 0;
}