#include <iostream>
#include <string>

using namespace std;

struct Node
{
	char data;
	int idx;
	Node* next;
};
int dma[150]{};

void MakeNode(Node** tail, char data, int idx)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->idx = idx;
	newNode->next = nullptr;

	(*tail)->next = newNode;
	*tail = newNode;
}

void FreeNode(Node* head)
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

int main(void)
{
	Node* head = new Node;
	Node* tail = head;
	head->next = nullptr;

	string input;

	cin >> input;

	for (int i = 0; i < input.length(); ++i)
	{
		char c = input[i];

		if (dma[int(c)] == 0)
		{
			MakeNode(&tail, c, i);
		}

		dma[int(c)]++;
	}

	Node* cur = head->next;
	Node* nxt;
	bool isOk = false;
	char c;
	while (cur)
	{
		nxt = cur->next;
		c = cur->data;

		if (dma[int(c)] == 1)
		{
			isOk = true;
			break;
		}
		cur = nxt;
	}

	if (isOk) cout << cur->idx;
	else cout << -1;

	FreeNode(head);

	return 0;
}

//다른버전
/*
#include <iostream>
#include <string>

using namespace std;

int dma[26]{};

int main(void)
{
	string input;

	cin >> input;

	for (int i = 0; i < input.length(); ++i)
	{
		++dma[input[i] - 'a'];
	}

	for (int i = 0; i < input.length(); ++i)
	{
		if (dma[input[i] - 'a'] == 1)
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
*/