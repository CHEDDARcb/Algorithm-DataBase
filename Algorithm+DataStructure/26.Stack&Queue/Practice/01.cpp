#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void Push(Node** head, Node** tail, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (*head == nullptr)
		*head = newNode;
	else
		(*tail)->next = newNode;

	*tail = newNode;
}

void PrintAll(Node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void FreeAll(Node* head)
{
	Node* cur = head;
	Node* nxt;
	while (cur)
	{
		nxt = cur->next;
		delete cur;
		cur = nxt;
	}
}

int main()
{
	int input;
	Node* head = nullptr;
	Node* tail = nullptr;

	cin >> input;

	for (int i = 0; i < 4; ++i)
	{
		Push(&head, &tail, input * (i + 1));
	}

	PrintAll(head);

	FreeAll(head);

	return 0;
}