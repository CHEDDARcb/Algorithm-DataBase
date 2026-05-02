#include <iostream>

using namespace std;

class LibraryItem
{
	LibraryItem() = delete;
	LibraryItem(const LibraryItem&) = delete;
	LibraryItem& operator=(const LibraryItem&) = delete;

public:
	LibraryItem(const char* title)
	{
		strcpy_s(mTitle, sizeof(mTitle), title);
	}
	virtual ~LibraryItem() = default;

public:
	void PrintInfo()const
	{
		cout << mTitle << endl;
	}

private:
	char mTitle[100];
};

class Book : public LibraryItem
{
	Book() = delete;
	Book(const Book&) = delete;
	Book& operator=(const Book&) = delete;

public:
	Book(const char* title)
		: LibraryItem(title)
	{
	}
	virtual ~Book() = default;
};

class DVD : public LibraryItem
{
	DVD() = delete;
	DVD(const DVD&) = delete;
	DVD& operator=(const DVD&) = delete;

public:
	DVD(const char* name)
		: LibraryItem(name)
	{
	}
	virtual ~DVD() = default;
};

int main(void)
{
	Book b("C++ Guide"); DVD d2("Inception");
	LibraryItem* items[] = { &b, &d2 };
	for (int i = 0; i < 2; ++i)
		items[i]->PrintInfo();


	return 0;
}