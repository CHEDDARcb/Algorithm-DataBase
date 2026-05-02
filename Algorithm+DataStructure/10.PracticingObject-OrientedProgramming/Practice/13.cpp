#include <iostream>

using namespace std;

class Book
{
	Book() = delete;
public:
	Book(const char* title, const char* author, const char* genre, const int page)
		: mPage(page)
	{
		int len = strlen(title);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, title, len);

		len = strlen(author);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, author, len);

		len = strlen(genre);
		mGenre = new char[len + 1];
		strncpy_s(mGenre, len + 1, genre, len);
	}
	explicit Book(const Book& book)
		: mPage(book.mPage)
	{
		int len = strlen(book.mTitle);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, book.mTitle, len);

		len = strlen(book.mAuthor);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, book.mAuthor, len);

		len = strlen(book.mGenre);
		mGenre = new char[len + 1];
		strncpy_s(mGenre, len + 1, book.mGenre, len);
	}
	Book& operator=(const Book& book)
	{
		mPage = book.mPage;

		if (mTitle != nullptr)
			delete[] mTitle;
		if (mAuthor != nullptr)
			delete[] mAuthor;
		if (mGenre != nullptr)
			delete[] mGenre;

		int len = strlen(book.mTitle);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, book.mTitle, len);

		len = strlen(book.mAuthor);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, book.mAuthor, len);

		len = strlen(book.mGenre);
		mGenre = new char[len + 1];
		strncpy_s(mGenre, len + 1, book.mGenre, len);

		return *this;
	}
	~Book()
	{
		delete[] mTitle;
		delete[] mAuthor;
		delete[] mGenre;
	}

public:
	void			SetTitle(const char* title)
	{
		if (mTitle != nullptr) { delete[] mTitle; }

		int len = strlen(title);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, title, len);
	}
	void			SetAuthor(const char* author)
	{
		if (mAuthor != nullptr) { delete[] mAuthor; }

		int len = strlen(author);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, author, len);
	}
	void			SetGenre(const char* publisher)
	{
		if (mGenre != nullptr) { delete[] mGenre; }

		int len = strlen(publisher);
		mGenre = new char[len + 1];
		strncpy_s(mAuthor, len + 1, publisher, len);
	}
	void			SetPrice(const int page) { mPage = page; }

public:
	const char* GetTitle() const { return mTitle; }
	const char* GetAuthor()const { return mAuthor; }
	const char* GetGenre() const { return mGenre; }
	const int		GetPage()const { return mPage; }

public:
	void			PrintBookInfo()
	{
		cout << "[Book]" << endl;
		cout << "Title: " << "\"" << mTitle << "\"" << endl;
		cout << "Author: " << "\"" << mAuthor << "\"" << endl;
		cout << "Publisher: " << "\"" << mGenre << "\"" << endl;
		cout << "Price: " << "$" << mPage << endl;
	}

private:
	char* mTitle;
	char* mAuthor;
	char* mGenre;
	int		mPage;
};

class Library
{
	Library() = delete;
	Library(const Library&) = delete;
	Library& operator=(const Library&) = delete;
public:
	Library(const char* location, const char* manager)
		: mBooks{}
		, mBooksNum(0)
		, mLocation{}
		, mManager{}
	{
		int len = strlen(location);
		strncpy_s(mLocation, len + 1, location, len);

		len = strlen(manager);
		strncat_s(mManager, len + 1, manager, len);
	}
	~Library() = default;

public:
	void AddBook(Book* book)
	{
		mBooks[mBooksNum++] = book;
	}

	void SetLocation(const char* location)
	{
		if (strlen(mLocation))
			memset(mLocation, 0, sizeof(mLocation));
		int len = strlen(location);
		strncpy_s(mLocation, len + 1, location, len);
	}

	void SetManager(const char* manager)
	{
		if (strlen(mManager))
			memset(mManager, 0, sizeof(mManager));
		int len = strlen(manager);
		strncpy_s(mManager, len + 1, manager, len);
	}

public:
	void PrintLibraryInfo()const
	{
		cout << "Library: " << mLocation << "Library" << " | ";
		cout << "Manager: " << mManager << endl;
		cout << "Books: " << endl;
		for (int i = 0; i < mBooksNum; ++i)
		{
			cout << "-\"" << mBooks[i]->GetTitle() << "\" by" << mBooks[i]->GetAuthor() << " ";
			cout << "(" << mBooks[i]->GetGenre() << ", " << mBooks[i]->GetPage() << "p)" << endl;
		}
	}

private:
	Book* mBooks[100];
	int		mBooksNum;
	char	mLocation[256];
	char	mManager[256];
};

int main()
{
	Book b1("1984", "Orwell", "Distopia", 320);
	Book b2("Dune", "Herbert", "Sci-Fi", 500);
	Library lb("Central", "Ms. Kim");

	lb.AddBook(&b1);
	lb.AddBook(&b2);

	lb.PrintLibraryInfo();

	return 0;
}