#include <iostream>

using namespace std;

struct Sim
{
	int age;
};

int main(void)
{
	Sim* simData[5];

	for (auto& data : simData)
	{
		data = new Sim;
		cin >> data->age;
	}

	int max = INT_MIN;
	int min = INT_MAX;
	int maxIDX = -1;
	int minIDX = -1;

	for (int i = 0; i < 5; ++i)
	{
		if (max < simData[i]->age)
		{
			max = simData[i]->age;
			maxIDX = i;
		}
		if (min > simData[i]->age)
		{
			min = simData[i]->age;
			minIDX = i;
		}
	}

	cout << "MAX:" << max << endl;
	cout << "MIN: " << min << endl;

	return 0;
}