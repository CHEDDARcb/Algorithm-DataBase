#include <iostream>

using namespace std;

class Engine
{
	Engine() = delete;
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
public:
	Engine(const int _horsePower, const char* _fuelType, const char* _engineType)
		: mHorsePower(_horsePower)
		, mFuelType{}
		, mEngineType{}
	{
		int len = strlen(_fuelType);
		strncpy_s(mFuelType, len + 1, _fuelType, len);

		len = strlen(_engineType);
		strncpy_s(mEngineType, len + 1, _engineType, len);
	}
	~Engine() = default;

public:
	void		SetHorsePower(const int _horsePower) { mHorsePower = _horsePower; }

	void		SetFuelType(const char* _fuelType)
	{
		if (strlen(mFuelType))
			memset(mFuelType, 0, sizeof(mFuelType));
		int len = strlen(_fuelType);
		strncpy_s(mFuelType, len + 1, _fuelType, len);
	}

	void		SetEngineType(const char* _engineType)
	{
		if (strlen(mEngineType))
			memset(mEngineType, 0, sizeof(mEngineType));
		int len = strlen(_engineType);
		strncpy_s(mEngineType, len + 1, _engineType, len);
	}

public:
	const int	GetHorsePower()const { return mHorsePower; }
	const char* GetFuelType()const { return mFuelType; }
	const char* GetEngineType()const { return mEngineType; }

private:
	int		mHorsePower;
	char	mFuelType[256];
	char	mEngineType[256];
};

class Car
{
	Car() = delete;
	Car(const Car&) = delete;
	Car& operator=(const Car&) = delete;
public:
	Car(const char* _brand, const char* _model,
		const int _modelYear, Engine* _engine)
		: mBrand{}
		, mModel{}
		, mModelYear(_modelYear)
		, mEngine(_engine)
	{
		int len = strlen(_brand);
		strncpy_s(mBrand, len + 1, _brand, len);

		len = strlen(_model);
		strncpy_s(mModel, len + 1, _model, len);
	}

public:
	void			SetBrand(const char* _brand)
	{
		if (strlen(mBrand))
			memset(mBrand, 0, sizeof(mBrand));
		int len = strlen(_brand);
		strncpy_s(mBrand, len + 1, _brand, len);
	}

	void			SetModel(const char* _model)
	{
		if (strlen(mModel))
			memset(mModel, 0, sizeof(mModel));
		int len = strlen(_model);
		strncpy_s(mModel, len + 1, _model, len);
	}

	void			SetModelYear(const int _modelYear) { mModelYear = _modelYear; }
	void			SetEngine(Engine* _engine) { mEngine = _engine; }

public:
	const char* GetBrand()const { return mBrand; }
	const char* GetModel()const { return mModel; }
	const int		GetModelYear()const { return mModelYear; }
	const Engine* GetEngine()const { return mEngine; }

public:
	void			PrintCarInfo()const
	{
		cout << "Car: " << mBrand << " " << mModel;
		cout << "(" << mModelYear << ")" << endl;
		cout << "Engine: " << mEngine->GetHorsePower() << "HP" << " | ";
		cout << "Fuel: " << mEngine->GetFuelType() << " | ";
		cout << "Type: " << mEngine->GetEngineType() << endl;
	}

private:
	char		mBrand[256];
	char		mModel[256];
	int			mModelYear;
	Engine* mEngine;
};

int main()
{
	Engine eng(450, "Gasoline", "VB");
	Car car("Ford", "Mustang", 2022, &eng);

	car.PrintCarInfo();

	return 0;
}