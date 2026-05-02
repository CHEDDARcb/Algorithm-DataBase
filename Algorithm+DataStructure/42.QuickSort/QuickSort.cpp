#include <iostream>
#include <vector>

using namespace std;

vector<int> vect = { 4, 3, 9, 8, 5, 7, 1, 2 };

int Partition(int left, int right)
{
	int pivot = vect[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot > vect[low])
			++low;

		while (high >= left + 1 && pivot < vect[high])
			--high;

		if (low <= high)
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
	cout << "======Before Sorted======" << endl;
	for (const auto& data : vect)
		cout << data << " ";
	cout << endl;

	QuickSort(0, vect.size() - 1);

	cout << "======After Sorted======" << endl;
	for (const auto& data : vect)
		cout << data << " ";
	cout << endl;
}