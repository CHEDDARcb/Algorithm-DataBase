#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void Insert(Node** head, Node** tail, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	(*tail)->next = newNode;
	*tail = newNode;
}

Node* Reverse(Node* head, Node** tail)
{
	Node* prev = nullptr;
	Node* cur = head->next;

	*tail = cur ? cur : head;

	while (cur)
	{
		Node* nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}

	head->next = prev;

	return head;
}

void PrintAll(Node* head)
{
	Node* cur = head->next;
	Node* nxt;
	while (cur)
	{
		nxt = cur->next;
		cout << cur->data << " ";
		cur = nxt;
	}
}

void FreeAll(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		Node* nxt = cur->next;
		delete cur;
		cur = nxt;
	}
}

int main(void)
{
	Node* dummy = new Node;
	dummy->next = nullptr;
	Node* head = dummy;
	Node* tail = head;

	int size;
	cin >> size;
	while (size--)
	{
		int data;
		cin >> data;

		Insert(&head, &tail, data);
	}

	Reverse(head, &tail);

	PrintAll(head);

	FreeAll(head);


	return 0;
}