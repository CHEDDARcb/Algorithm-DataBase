#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Insert(Node* head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr) head = newNode;
	else
	{
		Node* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}

	return head;
}

Node* MergeTwoSortedLists(Node* l1, Node* l2)
{
	Node result{ 0, nullptr };
	Node* tail = &result;

	while (l1 && l2)
	{
		if (l1->data <= l2->data)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}

		tail = tail->next;
	}

	tail->next = l1 ? l1 : l2;
	return result.next;
}

void PrintAll(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

int main(void)
{
	Node* l1 = nullptr;
	l1 = Insert(l1, 1);
	l1 = Insert(l1, 2);
	l1 = Insert(l1, 4);

	Node* l2 = nullptr;
	l2 = Insert(l2, 1);
	l2 = Insert(l2, 3);
	l2 = Insert(l2, 4);

	Node* result = MergeTwoSortedLists(l1, l2);
	PrintAll(result);

	return 0;
}