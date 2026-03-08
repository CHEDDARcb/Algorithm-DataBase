#include <iostream>
#include <vector>

using namespace std;

const vector<int> arr = { 4, 4, 5, 7, 8, 10, 20, 22, 23, 24 };

bool BinarySearch(int start, int end, int target)
{
	if (start > end)
		return false;

	int mid = (start + end) / 2;
	
	if (arr[mid] == target)
		return true;
	else if (arr[mid] > target)
		return BinarySearch(start, mid - 1, target);
	else
		return BinarySearch(mid + 1, end, target);
}

int main(void)
{
	int target;

	cout << "dho";
	cin >> target;

	bool result = BinarySearch(0, arr.size() - 1, target);

	cout << (result ? "O" : "X") << endl;
}