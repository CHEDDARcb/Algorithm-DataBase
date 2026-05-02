#include <iostream>

using namespace std;

class Movie
{
	Movie() = delete;
	Movie(const Movie&) = delete;
	Movie& operator=(const Movie&) = delete;
public:
	Movie(const char* title, const int duration, const char* genre,
		const char* ageRating)
		: mTitle{}
		, mDuration(duration)
		, mGenre{}
		, mAgeRating{}
	{
		int len = strlen(title);
		strncpy_s(mTitle, len + 1, title, len);

		len = strlen(genre);
		strncpy_s(mGenre, len + 1, genre, len);

		len = strlen(ageRating);
		strncpy_s(mAgeRating, len + 1, ageRating, len);
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
		strncpy_s(mGenre, len + 1, mGenre, len);
	}

	void		SetAgeRating(const char* ageRating)
	{
		if (strlen(mAgeRating))
			memset(mAgeRating, 0, sizeof(mAgeRating));
		int len = strlen(ageRating);
		strncpy_s(mAgeRating, len + 1, ageRating, len);
	}

public:
	const char* GetTitle()const { return mTitle; }
	const int	GetDuration()const { return mDuration; }
	const char* GetGenre()const { return mGenre; }
	const char* GetAgeRating()const { return mAgeRating; }

private:
	char	mTitle[256];
	int		mDuration;
	char	mGenre[256];
	char	mAgeRating[256];
};

class Theater
{
	Theater() = delete;
	Theater(const Theater&) = delete;
	Theater& operator=(const Theater&) = delete;
public:
	Theater(const char* name, const char* location)
		: mName{}
		, mLocation{}
		, mShowTimes{}
		, mTotalRunningTime(0)
		, mMovieNum(0)
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		strlen(location);
		strncpy_s(mLocation, len + 1, location, len);
	}
	~Theater() = default;

public:
	void			AddMovie(Movie* _movie)
	{
		mShowTimes[mMovieNum++] = _movie;
		mTotalRunningTime += _movie->GetDuration();
	}

public:
	void			PrintTheaterInfo()const
	{
		cout << "Theater: " << mName << " | ";
		cout << "Location: " << mLocation << endl;
		cout << "Now Showing: " << endl;
		for (int i = 0; i < mMovieNum; ++i)
		{
			cout << " - " << "\"" << mShowTimes[i]->GetTitle() << "\"" << " ";
			cout << "(" << mShowTimes[i]->GetDuration() << " min" << ", ";
			cout << mShowTimes[i]->GetAgeRating() << ")" << endl;
		}
		cout << "Total: " << mTotalRunningTime << " minutes" << endl;
	}

private:
	char		mName[256];
	char		mLocation[256];
	Movie* mShowTimes[100];
	int			mTotalRunningTime;
	int			mMovieNum;

};

int main()
{
	Movie avatar("Avatar", 162, "sci-fi", "12+");
	Movie taitanic("Taitanic", 195, "Romance", "All");
	Theater theater("CGV Gananm", "Seoul");

	theater.AddMovie(&avatar);
	theater.AddMovie(&taitanic);

	theater.PrintTheaterInfo();

	return 0;
}