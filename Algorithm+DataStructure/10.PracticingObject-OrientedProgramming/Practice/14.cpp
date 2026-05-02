#include <iostream>

using namespace std;

class Author
{
	Author() = delete;
	Author(const Author&) = delete;
	Author& operator=(const Author&) = delete;
public:
	Author(const char* name, const char* email, const char* field)
		: mName{}
		, mEmail{}
		, mField{}
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		len = strlen(email);
		strncpy_s(mEmail, len + 1, email, len);

		len = strlen(field);
		strncpy_s(mField, len + 1, field, len);
	}

public:
	const char* GetName()const { return mName; }
	const char* GetEmail()const { return mEmail; }
	const char* GetFiled()const { return mField; }


private:
	char mName[256];
	char mEmail[256];
	char mField[256];
};

class Article
{
	Article() = delete;
	Article(const Article&) = delete;
	Article& operator=(const Article&) = delete;
public:
	Article(const char* title, const char* day, const int charnum, Author* author)
		: mTitle{}
		, mDate{}
		, mCharaterNum(charnum)
		, mAuthor(author)
	{
		int len = strlen(title);
		strncat_s(mTitle, len + 1, title, len);

		len = strlen(day);
		strncat_s(mDate, len + 1, day, len);
	}
	~Article() = default;

public:
	void PrintArticelInfo()const
	{
		cout << "Article: " << "\"" << mTitle << "\" " << "(" << mCharaterNum << " chars )" << endl;
		cout << "Author: " << mAuthor->GetName() << " | ";
		cout << "Email: " << mAuthor->GetEmail() << " | ";
		cout << "Field: " << mAuthor->GetFiled() << endl;
	}

private:
	char		mTitle[256];
	char		mDate[256];
	int			mCharaterNum;
	Author* mAuthor;
};

int main()
{
	Author author("Alice Kim", "alice@domain.com", "Computer Science");
	Article article("Rise of AI", "25-11-05", 1240, &author);

	article.PrintArticelInfo();

	return 0;
}