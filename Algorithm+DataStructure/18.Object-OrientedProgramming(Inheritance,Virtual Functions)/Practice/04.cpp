#include <iostream>

using namespace std;

class Instrument
{
	Instrument(const Instrument&) = delete;
	Instrument& operator=(const Instrument&) = delete;

public:
	Instrument() = default;
	virtual ~Instrument() = default;

public:
	virtual void Play()const = 0;
};

class Piano : public Instrument
{
	Piano(const Piano&) = delete;
	Piano& operator=(const Piano&) = delete;

public:
	Piano() = default;
	virtual ~Piano() = default;

public:
	void Play()const override
	{
		cout << "ding ding!" << endl;
	}
};

class Guitar : public Instrument
{
	Guitar(const Guitar&) = delete;
	Guitar& operator=(const Guitar&) = delete;

public:
	Guitar() = default;
	virtual ~Guitar() = default;

public:
	void Play()const override
	{
		cout << "strum strum!" << endl;
	}
};

int main(void)
{
	Piano p; Guitar g;
	Instrument* instruments[] = { &p, &g };
	for (int i = 0; i < 2; ++i)
		instruments[i]->Play();

	return 0;
}