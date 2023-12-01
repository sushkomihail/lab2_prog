#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Advertisement;
class User;

typedef vector<Advertisement> AdvertisementList;
typedef vector<User> UserList;

class User {
	friend void ChangePassword(User& user);

private:
	string _login;
	string _password;
	string _phoneNumber;
	AdvertisementList _favourites;

public:
	User(string login, string password, string phoneNumber);

	User(string login);

	User();

	string GetLogin();

	string GetPassword();

	string GetPhoneNumber();

	AdvertisementList GetFavourites();

	void InputLogin();

	void InputPassword();

	void InputPhoneNumber();

	void Create();

	void AddToFavourites(Advertisement advertisement);

	void PrintUserData();
};

class Car {
protected:
	string _brand;
	int _year;
	int _enginePower;
	string _transmission;
	int _mileage;

public:
	Car(string brand, int year, int enginePower, string transmission, int mileage);

	Car(string brand);

	Car();

	Car operator+(const Car& car);

	string GetBrand();

	int GetYear();

	int GetMileage();

	virtual void Create();

	virtual void PrintCarData();
};

class Truck : public Car {
private:
	int _loadCapacity;

public:
	Truck(string brand, int year, int enginePower, string transmission, int mileage, int loadCapacity);
	Truck();
	Truck& operator=(const Car& car);
	void Create();
	void PrintCarData();
};

class Report {
private:
	int _crashesCount;
	bool _isListedAsWanted;
	bool _areDocumentsInOrder;
	bool _isRegistered;

public:
	Report(int crashesCount, bool isListedAsWanted, bool areDocumentsInOrder, bool isRegistered);

	Report(int crashesCount);

	Report();

	void Create();

	void PrintReportData();
};

class Advertisement {
private:
	static int _id;
	int _currentId;
	Car _car;
	Report _report;
	string _location;
	int _price;
	User _seller;

	void AssignID();

public:
	Advertisement(Car car, Report report, string location, int price, User seller);

	Advertisement(Car car);

	Advertisement();

	int GetID();

	Car GetCar();

	string GetLocation();

	int GetPrice();

	User GetSeller();

	static int GetCount();

	void Create(User user, AdvertisementList* advertisements);

	void Delete(User user, AdvertisementList* advertisements);

	void PrintAdvertisementData();
};

class SearchData {
protected:
	int _comparesTarget;
	string _brand;
	int _year;
	int _price;
	string _location;

	void CompareSearchData(bool expression, int* counter);

	void InputFilterField(string title, int* destination);

	void InputFilterField(string title, string& destination);

public:
	SearchData& operator++();

	SearchData operator++(int value);

	virtual void Create();
	
	virtual int GetComparesCount(Advertisement advertisement);
	
	AdvertisementList SortAdvertisementList(AdvertisementList list);
	
	void PrintSearchData();
};

class BaseSearchData : public SearchData {
public:
	BaseSearchData(string brand, int year, int price, string location);
	
	BaseSearchData(string brand);
	
	BaseSearchData();
	
	void Create();

	int GetComparesCount(Advertisement advertisement);
};

class ExtensiveSearchData : public SearchData {
private:
	int _mileage;

public:
	ExtensiveSearchData();

	void Create();

	int GetComparesCount(Advertisement advertisement);
};

const string UsersBase = "users.txt";

void ChangePassword(User &user);

vector<string> SplitString(string string);

UserList GetUserList();

bool EnterToSystem(UserList users, User* user);

void PrintAdvertisements(AdvertisementList advertisements);