#include <iostream>
#include <vector>

using namespace std;

struct AVLNode
{
	int data;
	int height;
	AVLNode* left;
	AVLNode* right;

	AVLNode(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
public:
	AVLTree() {}
	~AVLTree() { Destroy(root); }

	void Insert(int value)
	{
		root = Insert(root, value);
	}
	void InorderSort(std::vector<int>& result)
	{
		Inorder(root, result);
	}

private:
	int GetHeight(AVLNode* node)
	{
		return node ? node->height : 0;
	}

	int GetBalanceFactor(AVLNode* node)
	{
		return node ? GetHeight(node->left) - GetHeight(node->right) : 0;
	}

	void UpdateHeight(AVLNode* node)
	{
		if (node)
			node->height = 1 + max(GetHeight(node->left), GetHeight(node->right));
	}

	AVLNode* RotateRight(AVLNode* y)
	{
		AVLNode* x = y->left;
		y->left = x->right;
		x->right = y;
		UpdateHeight(y);
		UpdateHeight(x);
		return x;
	}

	AVLNode* RotateLeft(AVLNode* x)
	{
		AVLNode* y = x->right;
		x->right = y->left;
		y->left = x;
		UpdateHeight(x);
		UpdateHeight(y);
		return y;
	}

	AVLNode* Insert(AVLNode* node, int value)
	{
		if (!node) return new AVLNode(value);

		if (value < node->data)
			node->left = Insert(node->left, value);
		else
			node->right = Insert(node->right, value);

		UpdateHeight(node);

		int balance = GetBalanceFactor(node);

		if (balance > 1 && value <= node->left->data)
			return RotateRight(node);

		if (balance < -1 && value >= node->right->data)
			return RotateLeft(node);

		if (balance > 1 && value > node->left->data)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		if (balance < -1 && value < node->right->data)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}

		return node;
	}

	void Inorder(AVLNode* node, vector<int>& result)
	{
		if (node)
		{
			Inorder(node->left, result);
			result.push_back(node->data);
			Inorder(node->right, result);
		}
	}

	void Destroy(AVLNode* node)
	{
		if (node)
		{
			Destroy(node->left);
			Destroy(node->right);
			delete node;
		}
	}

private:
	AVLNode* root = nullptr;
};

int main(void)
{
	AVLTree tree;
	std::vector<int> values = { 10 ,20 , 30, 40, 50 ,25 };
	for (int value : values)
		tree.Insert(value);

	std::vector<int> sortedValues;
	tree.InorderSort(sortedValues);
	for (int value : sortedValues)
		cout << value << " ";

	return 0;
}