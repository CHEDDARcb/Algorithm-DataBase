#include <iostream>

using namespace std;

class Player
{
	Player() = delete;
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
public:
	Player(const char* name, const int id, const char* team, const int score)
		: mName{}
		, mID(id)
		, mTeam{}
		, mScore(score)
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		len = strlen(team);
		strncpy_s(mTeam, len + 1, team, len);
	}
	~Player() = default;

public:
	void				SetName(const char* name)
	{
		if (strlen(mName))
			memset(mName, 0, sizeof(mName));
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);
	}

	void				SetID(const int id) { mID = id; }

	void				SetTeam(const char* team)
	{
		if (strlen(mTeam))
			memset(mTeam, 0, sizeof(mTeam));
		int len = strlen(team);
		strncpy_s(mTeam, len + 1, team, len);
	}

	void				SetScore(const int score) { mScore = score; }

public:
	const char* GetName()const { return mName; }
	const int			GetID()const { return mID; }
	const char* GetTeam()const { return mTeam; }
	const int			GetScore()const { return mScore; }

private:
	char	mName[256];
	int		mID;
	char	mTeam[256];
	int		mScore;
};

class ScoreBoard
{
	ScoreBoard(const ScoreBoard&) = delete;
	ScoreBoard& operator=(const ScoreBoard&) = delete;
public:
	ScoreBoard()
		: mPlayers{}
		, mPlayerNum(0)
		, mAverScore(0)
	{
	}
	~ScoreBoard() = default;

public:
	void AddPlayer(Player* player)
	{
		mPlayers[mPlayerNum++] = player;
		CalcAverage();
	}

public:
	void PrintPlayersInfo()const
	{
		cout << "[ScoreBoard]" << endl;
		for (int i = 0; i < mPlayerNum; ++i)
		{
			cout << "-Player: " << mPlayers[i]->GetName() << " ";
			cout << "(Team " << mPlayers[i]->GetTeam() << ")" << " ";
			cout << "Score: " << mPlayers[i]->GetScore() << endl;
		}
		cout << "Average: " << mAverScore << endl;
	}

private:
	void CalcAverage()
	{
		int sum = 0;
		for (int i = 0; i < mPlayerNum; ++i)
		{
			sum += mPlayers[i]->GetScore();
		}

		mAverScore = sum / mPlayerNum;
	}

private:
	Player* mPlayers[100];
	int			mPlayerNum;
	int			mAverScore;
};

int main()
{
	Player p1("John", 123, "A", 80);
	Player p2("Mary", 456, "B", 90);

	ScoreBoard scoreBD;
	scoreBD.AddPlayer(&p1);
	scoreBD.AddPlayer(&p2);

	scoreBD.PrintPlayersInfo();

	return 0;
}