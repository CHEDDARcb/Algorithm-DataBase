#include <iostream>

using namespace std;

class  Queue
{
public:
	struct Node
	{
		char data;
		Node* next;
	};

public:
	Queue()
	{
		mHead = new Node;
		mHead->next = nullptr;
		mTail = mHead;
	}
	~Queue()
	{
		Node* delNode = mHead;
		Node* delNxtNode;
		while (delNode)
		{
			delNxtNode = delNode->next;
			delete delNode;
			delNode = delNxtNode;
		}
	}

public:
	void Enqueue(char data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		mTail->next = newNode;
		mTail = newNode;
	}
	void Dequeue()
	{
		if (mHead == mTail) return;
		Node* delNode = mHead->next;
		Node* delNxtNode = delNode->next;

		if (delNode == mTail) mTail = mHead;

		delete delNode;

		mHead->next = delNxtNode;
	}
	char front()
	{
		if (mHead == mTail) return '0';

		return mHead->next->data;
	}
	void PrintAll()
	{
		Node* cur = mHead->next;
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
private:
	Node* mHead;
	Node* mTail;
};

int main()
{
	Queue que;
	int enNum, deNum;

	cin >> enNum >> deNum;

	while (enNum--)
	{
		char data;
		cin >> data;
		que.Enqueue(data);
	}

	while (deNum--) que.Dequeue();

	que.PrintAll();


	return 0;
}