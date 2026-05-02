#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* head;
string value = " ";
int result = 0;

void InitMap(int cur, Node* prev)
{
	if (cur > value.size() - 1) return;

	Node* newNode = new Node;
	newNode->data = value[cur] - '0';
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (head == nullptr) head = newNode;
	else
	{
		if (cur % 2) prev->right = newNode;
		else prev->left = newNode;
	}

	InitMap(cur * 2, newNode);
	InitMap(cur * 2 + 1, newNode);
}

void DFS(Node* cur, int level)
{
	if (cur == nullptr) return;

	if (cur->left == nullptr &&
		cur->right == nullptr)
		result += cur->data;

	DFS(cur->left, level + 1);
	DFS(cur->right, level + 1);

}

int main()
{
	string input;

	cin >> input;

	value += input;

	InitMap(1, nullptr);
	DFS(head, 0);

	cout << result;

	return 0;
}