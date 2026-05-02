#include <iostream>
#include <vector>

using namespace std;

enum class eColor
{
	Red,
	Black,
	End,
};

struct Node
{
	int Data;
	eColor Color;

	Node* Left;
	Node* Right;
	Node* Parent;

	Node(int data)
		: Data(data)
		, Left(nullptr)
		, Right(nullptr)
		, Parent(nullptr)
	{
	}
};

class RedBlackTree
{
public:
	RedBlackTree()
	{
		NIL = new Node(0);
		NIL->Color = eColor::Black;
		mRoot = NIL;
	}

	void LeftRotate(Node* x)
	{
		Node* y = x->Right;

		x->Right = y->Left;
		if (y->Left != NIL)
			y->Left->Parent = x;

		y->Parent = x->Parent;
		if (x->Parent == NIL)
		{
			mRoot = y;
		}
		else if (x == x->Parent->Left)
		{
			x->Parent->Parent = y;
		}
		else
		{
			x->Parent->Right = y;
		}

		y->Left = x;
		x->Parent = y;
	}
	void RightRotate(Node* y)
	{
		Node* x = y->Left;

		y->Left = x->Right;
		if (x->Right != NIL)
		{
			x->Right->Parent = y;
		}

		x->Parent = y->Parent;
		if (y->Parent == NIL)
		{
			mRoot = x;
		}
		else if (y == y->Parent->Left)
		{
			y->Parent->Left = x;
		}
		else
		{
			y->Parent->Right = x;
		}

		x->Right = y;
		y->Parent = x;
	}
	void Insert(int data)
	{
		Node* newNode = new Node(data);
		newNode->Left = NIL;
		newNode->Right = NIL;

		Node* y = NIL;
		Node* x = mRoot;

		while (x != NIL)
		{
			y = x;
			if (newNode->Data < x->Data)
			{
				x = x->Left;
			}
			else
			{
				x = x->Right;
			}
		}

		newNode->Parent = y;

		if (y == NIL)
		{
			mRoot = newNode;
		}
		else if (newNode->Data < y->Data)
		{
			y->Left = newNode;
		}
		else
		{
			y->Right = newNode;
		}

		newNode->Color = eColor::Red;
		InsertFixup(newNode);
	}

	void InsertFixup(Node* z)
	{
		while (z->Parent->Color == eColor::Red)
		{
			if (z->Parent == z->Parent->Parent->Left)
			{
				Node* y = z->Parent->Parent->Right;
				if (y->Color == eColor::Red)
				{
					z->Parent->Color = eColor::Black;
					y->Color = eColor::Black;
					z->Parent->Parent->Color = eColor::Red;
					z = z->Parent->Parent;
				}
				else
				{
					if (z == z->Parent->Right)
					{
						z = z->Parent;
						LeftRotate(z);
					}

					z->Parent->Color = eColor::Black;
					z->Parent->Parent->Color = eColor::Red;
					RightRotate(z->Parent->Parent);
				}
			}
			else
			{
				Node* y = z->Parent->Parent->Left;
				if (y->Color == eColor::Red)
				{
					z->Parent->Color = eColor::Black;
					y->Color = eColor::Black;
					z->Parent->Parent->Color = eColor::Red;
					z = z->Parent->Parent;
				}
				else
				{
					if (z == z->Parent->Left)
					{
						z = z->Parent;
						RightRotate(z);
					}
					z->Parent->Color = eColor::Black;
					z->Parent->Parent->Color = eColor::Red;
					LeftRotate(z->Parent->Parent);
				}
			}
		}
		mRoot->Color = eColor::Black;
	}

	Node* Search(int data)
	{
		Node* current = mRoot;
		while (current != NIL && data != current->Data)
		{
			if (data < current->Data)
			{
				current = current->Left;
			}
			else
			{
				current = current->Right;
			}
		}
		return current;
	}

	void InOrderTraversal(Node* node)
	{
		if (node != NIL)
		{
			InOrderTraversal(node->Left);
			cout << node->Data << " ";
			InOrderTraversal(node->Right);
		}
	}

	Node* GetRoot() const { return mRoot; }

	void PrintColorTree(Node* node, int depth = 0)
	{
		const string RED_COLOR = "\033[31m";
		const string BLACK_COLOR = "\033[30m";
		const string RESET_COLOR = "\033[0m";
		const string BOLD = "\033[1m";

		if (node != NIL)
		{
			PrintColorTree(node->Right, depth + 1);

			for (int i = 0; i < depth; ++i)
				cout << "  ";
			cout << (node->Color == eColor::Red ? RED_COLOR : BLACK_COLOR)
				<< BOLD << node->Data << "(" << (node->Color == eColor::Red ? "R" : "B") << ")"
				<< RESET_COLOR << "\n";
			
			PrintColorTree(node->Left, depth + 1);
		}
	}

	void DisplayColorTree()
	{
		PrintColorTree(mRoot);
	}

	vector<int> GetSortedArray()
	{
		vector<int> result;
		InOrderCollect(mRoot, result);
		return result;
	}

	void InOrderCollect(Node* node, vector<int>& arr)
	{
		if (node != NIL)
		{
			InOrderCollect(node->Left, arr);
			arr.push_back(node->Data);
			InOrderCollect(node->Right, arr);
		}
	}

	int GetBlackHeight(Node* node)
	{
		if (node == NIL)
		{
			return 1;
		}
		int leftBlackHeight = GetBlackHeight(node->Left);
		int rightBlackHeight = GetBlackHeight(node->Right);
		if (leftBlackHeight == -1 || rightBlackHeight == -1 || leftBlackHeight != rightBlackHeight)
		{
			return -1;
		}
		return leftBlackHeight + (node->Color == eColor::Black ? 1 : 0);
	}

	bool ValidateRedBlackTree()
	{
		return ValidateProperties(mRoot) != -1;
	}

	int ValidateProperties(Node* node)
	{
		if (node == NIL)
			return 1;

		if (node->Color == eColor::Red)
		{
			if (node->Left->Color == eColor::Red || node->Right->Color == eColor::Red)
				return -1;
		}
		int leftBlackHeight = ValidateProperties(node->Left);
		int rightBlackHeifth = ValidateProperties(node->Right);
		if (leftBlackHeight == -1 || rightBlackHeifth == -1 || leftBlackHeight != rightBlackHeifth)
			return -1;

		return leftBlackHeight + (node->Color == eColor::Black ? 1 : 0);
	}

	Node* GetNIL() const { return NIL; }

private:
	Node* NIL;
	Node* mRoot;
};

int main(void)
{
	RedBlackTree rbt;

	cout << "OO Red-Black Tree 완전정복" << endl;
	cout << "+++++++++++++++++++++++++++\n" << endl;

	vector<int> data = { 20, 10, 30, 5, 15, 25, 35 };

	cout << "\n=== 레드 블랙 트리 삽입 과정 === " << endl;

	for (int value : data)
	{
		cout << "\n 삽입: " << value << endl;
		rbt.Insert(value);

		cout << "기본 출력: " << endl;
		rbt.DisplayColorTree();

		std::cout << "---------------------" << endl;
	}

	cout << "\n=== 정렬된 결과===" << endl;
	vector<int> sorted = rbt.GetSortedArray();
	for (int value : sorted)
	{
		cout << value << " ";
	}

}