#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char data;
	Node* next;
};

Node* head = new Node;
Node* tail = head;

void push(char data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	tail->next = newNode;
	tail = newNode;
}

char pop()
{
	if (head == tail) return '0';

	Node data{ head->next->data, head->next->next };

	if (head->next == tail) tail = head;

	delete head->next;

	head->next = data.next;

	return data.data;
}

int main()
{
	int n;

	cin >> n;

	int tmp = n;
	while (tmp--)
	{
		char input;
		cin >> input;
		push(input);
	}

	tmp = n;
	while (tmp--)
	{
		cout << pop();
	}

	return 0;
}