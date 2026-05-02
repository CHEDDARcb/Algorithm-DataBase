#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
};

Node* head;
string value;

void InitMap(int cur, Node* prev = nullptr)
{
	if (cur > value.size() - 1) return;

	Node* newNode = new Node;
	newNode->data = value[cur];
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (cur == 1) head = newNode;
	else
	{
		if (cur % 2 == 0) prev->left = newNode;
		else prev->right = newNode;
	}

	InitMap(cur * 2, newNode);
	InitMap(cur * 2 + 1, newNode);
}

void DFS(Node* cur, int level)
{
	if (cur == nullptr) return;

	cout << cur->data << " ";

	DFS(cur->left, level + 1);
	DFS(cur->right, level + 1);

}

int main()
{
	string input;
	value = ' ';
	cin >> input;

	value += input;

	InitMap(1);
	DFS(head, 0);

	return 0;
}