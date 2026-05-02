#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

class List
{
public:
	List()
		: mHead(nullptr)
		, mTail(nullptr)
		, mCount(0)
	{
	}
	~List()
	{
		Node* delNode = mHead;
		Node* nxtNode;
		while (delNode)
		{
			nxtNode = delNode->next;
			delete delNode;
			delNode = nxtNode;
		}
	}

public:
	void Insert(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = mTail;

		if (mCount <= 0)
		{
			mHead = newNode;
		}
		else
		{
			mTail->next = newNode;
		}

		mTail = newNode;
		++mCount;
	}

	void DeleteNode(int delData)
	{
		Node* cur = mHead;
		while (cur)
		{
			if (cur->data == delData)
			{
				Node* prev = cur->prev;
				Node* next = cur->next;

				if (cur == mHead) mHead = next;
				if (cur == mTail) mTail = prev;

				if (prev) prev->next = next;
				if (next) next->prev = prev;

				delete cur;
				--mCount;
				return;
			}
			cur = cur->next;
		}
	}

public:
	void PrintAll()const
	{
		Node* curNode = mHead;
		Node* nxtNode;
		while (curNode)
		{
			nxtNode = curNode->next;
			cout << curNode->data << " ";
			curNode = nxtNode;
		}
	}

private:
	Node* mHead;
	Node* mTail;
	int		mCount;
};

int main(void)
{
	List list;
	int n = 4;

	int data;
	while (n--)
	{
		cin >> data;
		list.Insert(data);
	}

	int delData;
	cin >> delData;
	list.DeleteNode(delData);

	list.PrintAll();


	return 0;
}