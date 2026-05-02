#include <iostream>

using namespace std;

struct Node
{
	char data;
	int idx;
	Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void Push(char data, int idx)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->idx = idx;
	newNode->next = nullptr;

	if (head == nullptr) head = newNode;
	else tail->next = newNode;

	tail = newNode;
}

void PrintAll()
{
	Node* cur = head;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;

	cur = head;
	while (cur)
	{
		cout << cur->idx << " ";
		cur = cur->next;
	}
}

void FreeAll()
{
	Node* delNode = head;
	Node* delNxtNode;
	while (delNode)
	{
		delNxtNode = delNode->next;
		delete delNode;
		delNode = delNxtNode;
	}
}

int main()
{
	int input;
	cin >> input;

	for (int i = 0; i < input; ++i)
	{
		Push('A' + i, i + 1);
	}

	PrintAll();

	FreeAll();

	return 0;
}