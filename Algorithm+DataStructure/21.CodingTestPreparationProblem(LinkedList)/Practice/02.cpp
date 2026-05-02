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

	if (*head == nullptr)
	{
		*head = newNode;
	}

	if (*tail)
	{
		(*tail)->next = newNode;
	}
	*tail = newNode;
}

Node* RemoveNthFromEnd(Node* head, int n)
{

	Node* fast = head;
	Node* slow = head;

	for (int i = 0; i < n; ++i)
	{
		fast = fast->next;
	}

	while (fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}

	Node* delNode = slow->next;
	slow->next = slow->next->next;
	delete delNode;

	return head;
}

void PrintAll(Node* head)
{
	Node* cur = head;
	Node* nxt;
	while (cur)
	{
		nxt = cur->next;
		cout << cur->data << " ";
		cur = nxt;
	}

}

int main(void)
{
	Node* head = nullptr;
	Node* tail = nullptr;

	int size = 5;
	while (size--)
	{
		int data;
		cin >> data;
		Insert(&head, &tail, data);
	}

	int n;
	cin >> n;
	head = RemoveNthFromEnd(head, n);

	PrintAll(head);

	return 0;
}