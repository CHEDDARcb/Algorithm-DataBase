#include <iostream>

using namespace std;

class Book
{
public:
	Book() = default;
	Book(const char* title, const char* author, const char* publisher
		, const float price, const int page)
		: mTitle(nullptr)
		, mAuthor(nullptr)
		, mPublisher(nullptr)
		, mPrice(price)
		, mCurrentPage(1)
		, mPage(page)
	{
		int len = strlen(title);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, title, len);

		len = strlen(author);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, author, len);

		len = strlen(publisher);
		mPublisher = new char[len + 1];
		strncpy_s(mPublisher, len + 1, publisher, len);
	}
	explicit Book(const Book& book)
		: mPrice(book.mPrice)
		, mCurrentPage(book.mCurrentPage)
		, mPage(book.mPage)
	{
		int len = strlen(book.mTitle);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, book.mTitle, len);

		len = strlen(book.mAuthor);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, book.mAuthor, len);

		len = strlen(book.mPublisher);
		mPublisher = new char[len + 1];
		strncpy_s(mPublisher, len + 1, book.mPublisher, len);
	}
	Book& operator=(const Book& book)
	{
		mPrice = book.mPrice;

		if (mTitle != nullptr)
			delete[] mTitle;
		if (mAuthor != nullptr)
			delete[] mAuthor;
		if (mPublisher != nullptr)
			delete[] mPublisher;

		int len = strlen(book.mTitle);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, book.mTitle, len);

		len = strlen(book.mAuthor);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, book.mAuthor, len);

		len = strlen(book.mPublisher);
		mPublisher = new char[len + 1];
		strncpy_s(mPublisher, len + 1, book.mPublisher, len);

		return *this;
	}
	~Book()
	{
		delete[] mTitle;
		delete[] mAuthor;
		delete[] mPublisher;
	}

public:
	void				SetTitle(const char* title)
	{
		if (mTitle != nullptr) { delete[] mTitle; }

		int len = strlen(title);
		mTitle = new char[len + 1];
		strncpy_s(mTitle, len + 1, title, len);
	}
	void				SetAuthor(const char* author)
	{
		if (mAuthor != nullptr) { delete[] mAuthor; }

		int len = strlen(author);
		mAuthor = new char[len + 1];
		strncpy_s(mAuthor, len + 1, author, len);
	}
	void				SetPublisher(const char* publisher)
	{
		if (mPublisher != nullptr) { delete[] mPublisher; }

		int len = strlen(publisher);
		mPublisher = new char[len + 1];
		strncpy_s(mPublisher, len + 1, publisher, len);
	}
	void				SetPrice(const int price) { mPrice = price; }

public:
	const char* GetTitle() const { return mTitle; }
	const char* GetAuthor()const { return mAuthor; }
	const char* GetPublisher() const { return mPublisher; }
	const int			GetPrice()const { return mPrice; }

public:
	void				PrintBookInfo()
	{
		cout << "[Book]" << endl;
		cout << "Title: " << "\"" << mTitle << "\"" << endl;
		cout << "Author: " << "\"" << mAuthor << "\"" << endl;
		cout << "Publisher: " << "\"" << mPublisher << "\"" << endl;
		cout << "Page: " << mPage << endl;
		cout << "Price: " << "$" << mPrice << endl;
	}

	void				ReadBook(const int pages = 1)
	{
		cout << "start Reading Book..." << mCurrentPage << "p" << endl;
		mCurrentPage += pages;
		if (mCurrentPage >= mPage) mCurrentPage = mPage;
	}

	void				PrintProgress()const
	{
		cout << "Page: " << mCurrentPage << " / " << mPage;
		cout << "(" << CalcProgress() << "%)" << endl;
	}

private:
	const float			CalcProgress()const
	{
		return 100.f * mCurrentPage / mPage;
	}

private:
	char* mTitle;
	char* mAuthor;
	char* mPublisher;
	float	mPrice;
	int		mPage;
	int		mCurrentPage;
};

int main()
{
	Book book("1984", "George Orwell", "Penguin", 15.99f, 345);

	book.PrintBookInfo();

	for (int i = 0; i < 12; ++i)
		book.ReadBook();
	book.PrintProgress();

	return 0;
}