#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Advertisement;
class User;

typedef vector<Advertisement> AdvertisementList;
typedef vector<User> UserList;

class User {
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

	void Create(UserList* users);

	void AddToFavourites(Advertisement advertisement);

	void PrintUserData();
};

class Car {
private:
	string _brand;
	int _year;
	int _enginePower;
	string _transmission;
	int _mileage;

public:
	Car(string brand, int year, int enginePower, string transmission, int mileage);

	Car(string brand);

	Car();

	string GetBrand();

	int GetYear();

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

	void Create(User user, AdvertisementList* advertisements);

	void Delete(User user, AdvertisementList* advertisements);

	void PrintAdvertisementData();
};

class SearchData {
private:
	const int COMPARES_TARGET = 4;
	string _brand;
	int _year;
	int _price;
	string _location;

	void CompareSearchData(bool expression, int* counter);

	void InputFilterField(string title, int* destination);

	void InputFilterField(string title, string* destination);

public:
	SearchData(string brand, int year, int price, string location);

	SearchData(string brand);

	SearchData();

	void Create();

	AdvertisementList SortAdvertisementList(AdvertisementList list);

	void PrintSearchData();
};

bool EnterToSystem(UserList users, User* user);

void PrintAdvertisements(AdvertisementList advertisements);