#include <iostream>
#include <vector>

using namespace std;

enum class Matterial
{
	GOLD = 0, STONE
};

struct Data
{
	Matterial mt;
	int weight;

	bool operator<(const Data& other) const
	{
		if (weight != other.weight)
			return weight < other.weight;
		else
			return (mt == Matterial::GOLD) && 
			(other.mt == Matterial::STONE);
	}
};

class Heap
{
public:
	Heap()
		: mSize(0) 
	{}
	void ResizeHeap(int n)
	{
		mHeap.resize(n * n);
	}

public:
	void Push(const Data& data)
	{
		++mSize;
		int curIdx = mSize;
		int parentIdx = GetParent(curIdx);

		while (parentIdx > 0)
		{
			if (data < mHeap[parentIdx])
			{
				mHeap[curIdx] = mHeap[parentIdx];
				curIdx = parentIdx;
			}
			else
				break;
			parentIdx = GetParent(curIdx);
		}

		mHeap[curIdx] = data;
	}

	Data Pop()
	{
		Data popData = mHeap[1];
		Data reposData = mHeap[mSize];

		int curIdx = 1;
		int childIdx;
		while (childIdx = GetHighPriorityChild(curIdx))
		{
			if (mHeap[childIdx] < reposData)
			{
				mHeap[curIdx] = mHeap[childIdx];
				curIdx = childIdx;
			}
			else
				break;
		}

		mHeap[curIdx] = reposData;
		--mSize;

		return popData;
	}

private:
	int GetParent(int idx) { return idx / 2; }
	int GetLChild(int idx) { return idx * 2; }
	int GetRChild(int idx) { return idx * 2 + 1; }
	int GetHighPriorityChild(int idx)
	{
		int lc = GetLChild(idx);
		int rc = GetRChild(idx);

		if (lc > mSize)
			return 0;
		else if (lc == mSize)
			return lc;
		else if (mHeap[lc] < mHeap[rc])
			return lc;
		return rc;
	}
private:
	int mSize;
	vector<Data> mHeap;
};

int n;
Heap hp;

void Input()
{
	cin >> n;
	hp.ResizeHeap(n);

	for (int i = 0; i < n; ++i)
	{
		Data tmp;
		tmp.mt = Matterial::GOLD;
		cin >> tmp.weight;

		hp.Push(tmp);
	}
}

int main(void)
{
	Input();

	bool isContinue = true;
	int popCount = 0;
	while (isContinue)
	{
		for (int k = 0; k < 2; ++k)
		{
			Data d = hp.Pop();

			if (d.mt == Matterial::STONE)
			{
				isContinue = false;
				break;
			}

			++popCount;
			if (k == 1)
			{
				Data stone{ Matterial::STONE, d.weight * 2 };
				hp.Push(stone);
			}
		}
	}

	cout << popCount;

	return 0;
}