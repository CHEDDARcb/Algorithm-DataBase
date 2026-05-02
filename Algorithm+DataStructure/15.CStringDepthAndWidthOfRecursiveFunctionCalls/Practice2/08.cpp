#include <iostream>

using namespace std;

struct Position
{
	int y;
	int x;
};

Position aPos(2, 0);
Position tPos(2, 1);
Position kPos(2, 2);

void Order(const char _target, const char* _direction)
{
	Position* p = nullptr;

	switch (_target)
	{
	case 'A': p = &aPos; break;
	case 'T': p = &tPos; break;
	case 'K': p = &kPos; break;
	}

	if (p != nullptr)
	{
		if (strcmp(_direction, "UP") == 0)
		{
			p->y -= 1;
		}
		else if (strcmp(_direction, "DOWN") == 0)
		{
			p->y += 1;
		}
		else if (strcmp(_direction, "RIGHT") == 0)
		{
			p->x += 1;
		}
		else if (strcmp(_direction, "LEFT") == 0)
		{
			p->x -= 1;
		}
	}
}
int main()
{
	char stage[5][3] =
	{
		'_', '_', '_',
		'_', '_', '_',
		'_', '_', '_',
		'_', '_', '_',
		'_', '_', '_'
	};

	char target;
	char direction[10];
	for (int i = 0; i < 7; ++i)
	{
		cin >> target >> direction;
		Order(target, direction);
	}

	stage[aPos.y][aPos.x] = 'A';
	stage[tPos.y][tPos.x] = 'T';
	stage[kPos.y][kPos.x] = 'K';

	for (const auto& row : stage)
	{
		for (const auto& data : row)
		{
			cout << data;
		}
		cout << endl;
	}

	return 0;
}