#include <iostream>
#include <vector>
using namespace std;

const vector<int> evid = { -1, 0, 0, 1, 2, 4, 4 };
const vector<int> timeStemp = { 8, 3, 5, 6, 8, 9, 10 };

void TrackTarget(int idx)
{
	if (idx == 0)
	{
		cout << "0번index(출발)" << endl;
		return;
	}

	TrackTarget(evid[idx]);
	cout << idx << "번index(" << timeStemp[idx] << "시)" << endl;
}

int main()
{
	int input;

	cin >> input;

	TrackTarget(input);

	return 0;
}