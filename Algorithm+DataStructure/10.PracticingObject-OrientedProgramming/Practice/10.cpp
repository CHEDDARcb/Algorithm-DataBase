#include <iostream>

using namespace std;

class Movie
{
	struct Tag
	{
		const char* tags[5];
		int		tagNum;
	};
	Movie() = delete;
	Movie(const Movie&) = delete;
	Movie& operator=(const Movie&) = delete;
public:
	Movie(const char* title, const int duration, const char* genre,
		const int ageRating, const char* director)
		: mTitle{}
		, mDuration(duration)
		, mGenre{}
		, mAgeRating(ageRating)
		, mDirector{}
		, mTags{}
	{
		int len = strlen(title);
		strncpy_s(mTitle, len + 1, title, len);

		len = strlen(genre);
		strncpy_s(mGenre, len + 1, genre, len);

		len = strlen(director);
		strncpy_s(mDirector, len + 1, director, len);
	}
	~Movie() = default;

public:
	void		SetTitle(const char* title)
	{
		if (strlen(mTitle))
			memset(mTitle, 0, sizeof(mTitle));
		int len = strlen(title);
		strncpy_s(mTitle, len + 1, title, len);
	}

	void		SetDuration(const int duration) { mDuration = duration; }

	void		SetGenre(const char* genre)
	{
		if (strlen(mGenre))
			memset(mGenre, 0, sizeof(mGenre));
		int len = strlen(genre);
		strncpy_s(mGenre, len + 1, genre, len);
	}

	void		SetAgeRating(const int ageRating) { mAgeRating = ageRating; }

	void		SetDirector(const char* director)
	{
		if (strlen(mDirector))
			memset(mDirector, 0, sizeof(mDirector));
		int len = strlen(director);
		strncpy_s(mDirector, len + 1, director, len);
	}

public:
	const char* GetTitle()const { return mTitle; }
	const int	GetDuration()const { return mDuration; }
	const char* GetGenre()const { return mGenre; }
	const int	GetAgeRating()const { return mAgeRating; }
	const char* GetDirector()const { return mDirector; }

public:
	void PrintMovieInfo()const
	{
		cout << "[Movie]" << endl;
		cout << "Title: " << mTitle << endl;
		cout << "Duration: " << mDuration << " min" << endl;
		cout << "Genre: " << mGenre << endl;
		cout << "Rated: " << mAgeRating << "+" << endl;
		cout << "Directed by: " << mDirector << endl;
		cout << "Tags: " << endl;
		for (int i = 0; i < mTags.tagNum; ++i)
		{
			cout << " #" << mTags.tags[i];
		}
		cout << endl;
	}

	void AddTag(const char* tag)
	{
		mTags.tags[mTags.tagNum++] = tag;
	}

private:
	char	mTitle[256];
	int		mDuration;
	char	mGenre[256];
	int		mAgeRating;
	char	mDirector[256];
	Tag		mTags;
};

int main()
{
	Movie movie("Intersterllar", 169, "Sci-Fi", 12, "JO");
	movie.SetDirector("Nolan");

	movie.AddTag("Sci-Fi");
	movie.AddTag("Space");
	movie.AddTag("Nolan");

	movie.PrintMovieInfo();

	return 0;
}