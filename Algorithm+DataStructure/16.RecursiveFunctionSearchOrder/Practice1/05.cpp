#include <iostream>

using namespace std;

int plan[100]{};
int duties[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int n;

void CleanningPlan(int _day, const int _deadLine)
{
	if (_day == _deadLine)
	{
		for (size_t i = 1; plan[i] != '\0'; ++i)
			cout << plan[i];
		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		plan[_day + 1] = duties[i];
		CleanningPlan(_day + 1, _deadLine);
		plan[_day + 1] = '\0';
	}
}

int main()
{
	cin >> n;

	CleanningPlan(0, 4);
	return 0;
}