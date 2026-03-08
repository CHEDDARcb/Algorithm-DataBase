#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	string path;
	int cost;

	bool operator<(const Data& other)
	{
		return this->cost < other.cost;
	}
};

const int HIPCAPACITY = 50;
class Heap
{
public:
	Heap()
		: mSize(0)
	{
		mHeap.resize(HIPCAPACITY + 1);
	}

public:
	void Push(Data& data)
	{
		++mSize;
		int pushIdx = mSize;
		int parentIdx = GetParent(pushIdx);
		while (parentIdx > 0)
		{
			if (mHeap[parentIdx] < data)
			{
				mHeap[pushIdx] = mHeap[parentIdx];
				pushIdx = parentIdx;
			}
			else
				break;

			parentIdx = GetParent(pushIdx);
		}

		mHeap[pushIdx] = data;
	}
	Data Pop()
	{
		Data popData = mHeap[1];
		Data reposData = mHeap[mSize];

		int curIdx = 1;
		int childIdx;
		while (childIdx = GetHighPriorityChild(curIdx))
		{
			if (reposData < mHeap[childIdx])
			{
				mHeap[curIdx] = mHeap[childIdx];
				curIdx = childIdx;
			}
			else break;
		}

		mHeap[curIdx] = reposData;
		mSize--;

		return popData;
	}

private:
	int GetParent(int idx)
	{
		return idx / 2;
	}
	int GetHighPriorityChild(int idx)
	{
		int lc = GetLeftChild(idx);
		int rc = GetRightChild(idx);

		if (lc > mSize)
			return 0;
		else if (lc == mSize)
			return lc;
		else if (mHeap[lc] < mHeap[rc])
			return rc;
		else
			return lc;
	}
	int GetLeftChild(int idx)
	{
		return idx * 2;
	}
	int GetRightChild(int idx)
	{
		return idx * 2 + 1;
	}

private:
	int mSize;
	vector<Data> mHeap;
};

int n;
vector<vector<int>> map;
string name;
vector<bool> visited;

void Input()
{
	cin >> n;

	map.resize(n, vector<int>(n));
	visited.resize(n, false);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
		name.push_back('A' + i);
}

int main(void)
{
	Input();

	Data dt;
	Heap hp;

	dt.path.resize(4);
	dt.path[1] = '-';
	dt.cost = 0;

	for (int i = 0; i < n; ++i)
	{
		visited[i] = true;

		dt.path[0] = name[i];
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] > 0 && !visited[j])
			{
				visited[j] = true;

				dt.path[2] = name[j];
				dt.cost += map[i][j];

				hp.Push(dt);

				visited[j] = false;
				dt.cost = 0;
			}
		}
		visited[i] = false;
	}

	for (int i = 0; i < 3; ++i)
	{
		Data top = hp.Pop();

		cout << top.path << " " << top.cost << endl;
	}

	return 0;
}