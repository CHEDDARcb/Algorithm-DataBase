#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct field
{
	stack<int> crops;
};
vector<vector<field>> fields(3, vector<field>(3));
vector<int> windDmg;
int fn, wn;

void Input()
{
	cin >> fn;

	for (int i = 0; i < fn; ++i)
	{
		int y, x;
		string cropsHP;
		cin >> y >> x >> cropsHP;
		for (int j = 0; j < cropsHP.size(); ++j)
		{
			fields[y][x].crops.push(cropsHP[j] - '0');
		}
	}

	cin >> wn;
	windDmg.resize(wn);
	for (int i = 0; i < wn; ++i)
	{
		cin >> windDmg[i];
	}
}

void ApplyDamage(int dmg)
{
	for (int i = 0; i < fields.size(); ++i)
	{
		for (int j = 0; j < fields[i].size(); ++j)
		{
			field& field = fields[i][j];
			if (field.crops.size())
			{
				field.crops.top() -= dmg;
				if (field.crops.top() <= 0)
					field.crops.pop();
			}
		}
	}
}

void Simulation()
{
	for (int k = 0; k < wn; ++k)
	{
		int dmg = windDmg[k];

		ApplyDamage(dmg);
	}
}

int Counting()
{
	int result = 0;
	for (int i = 0; i < fields.size(); ++i)
	{
		for (int j = 0; j < fields[i].size(); ++j)
		{
			field& field = fields[i][j];
			result += field.crops.size();
		}
	}

	return result;
}

int main(void)
{
	Input();

	Simulation();

	cout << Counting();

	return 0;
}