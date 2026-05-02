#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char data;
	Node* next;
};

void Push(Node** head, Node** tail, char data)
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
	for (Node* cur = head; cur != nullptr; cur = cur->next)
	{
		cout << cur->data << " ";
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

	for (int i = input; i < input + 4 && i <= 36; ++i)
	{
		Push(&head, &tail, 'A' + i - 11);
	}

	PrintAll(head);

	FreeAll(head);

	return 0;
}