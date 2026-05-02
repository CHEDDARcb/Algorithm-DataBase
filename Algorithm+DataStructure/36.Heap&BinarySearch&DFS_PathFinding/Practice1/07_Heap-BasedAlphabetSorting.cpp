#include <iostream>
#include <vector>

using namespace std;

const int HEAPSIZE = 50;

class MaxHeap
{
public:
	MaxHeap()
		: mSize(0)
	{
		mMaxH.resize(HEAPSIZE + 1);
	}

public:
	void Push(char data)
	{
		++mSize;
		int curIdx = mSize;
		int parentIdx = GetParent(curIdx);

		while (parentIdx != 0)
		{
			if (data > mMaxH[parentIdx])
			{
				mMaxH[curIdx] = mMaxH[parentIdx];
				curIdx = parentIdx;
			}
			else
				break;
			parentIdx = GetParent(curIdx);
		}

		mMaxH[curIdx] = data;
	}
public:
	char Pop()
	{
		char popData = mMaxH[1];
		char reposData = mMaxH[mSize];
		mMaxH[mSize] = '\0';
		--mSize;

		int curIdx = 1;
		int childIdx;
		while (childIdx = GetPriorityLRChild(curIdx))
		{
			if (reposData < mMaxH[childIdx])
			{
				mMaxH[curIdx] = mMaxH[childIdx];
				curIdx = childIdx;
			}
			else
				break;
		}

		mMaxH[curIdx] = reposData;
		return popData;
	}

private:
	int GetParent(int idx)
	{
		return idx / 2;
	}
	int GetLChild(int idx)
	{
		return idx * 2;
	}
	int GetRChild(int idx)
	{
		return idx * 2 + 1;
	}
	int GetPriorityLRChild(int idx)
	{
		int lc = GetLChild(idx);
		int rc = GetRChild(idx);
		if (lc > mSize)
			return 0;
		else if (lc && rc > mSize)
			return lc;
		else if (mMaxH[lc] > mMaxH[rc])
			return lc;
		else
			return rc;
	}

private:
	vector<char> mMaxH;
	int mSize;
};

int main(void)
{
	MaxHeap maH;
	string input;

	cin >> input;

	for (int i = 0; i < input.size(); ++i)
		maH.Push(input[i]);

	for (int i = 0; i < input.size(); ++i)
		cout << maH.Pop();

	return 0;
}