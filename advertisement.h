#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Advertisement;

typedef vector<Advertisement> AdvertisementList;

class User {
private:
	string _login;
	int _password;
	int _phoneNumber;
	AdvertisementList _favourites;

public:
	User(string login, int password, int phoneNumber);

	User(string login);

	User();

	string GetLogin();

	int GetPassword();

	int GetPhoneNumber();

	AdvertisementList GetFavourites();

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

	void PrintReportData();
};

class Advertisement {
private:
	int _index;
	Car _car;
	Report _report;
	string _location;
	int _price;
	User _seller;

public:
	Advertisement(int index, Car car, Report report, string location, int price, User seller);

	Advertisement(int index);

	Advertisement();

	int GetIndex();

	Car GetCar();

	string GetLocation();

	int GetPrice();

	User GetSeller();

	void PrintAdvertisementData();
};

class SearchData {
private:
	const int COMPARES_TARGET = 4;
	string _brand;
	int _year;
	int _price;
	string _location;

public:
	SearchData(string brand, int year, int price, string location);

	SearchData(string brand);

	SearchData();

	int GetComparesTarget();

	string GetBrand();

	int GetYear();

	int GetPrice();

	string GetLocation();

	void PrintSearchData();
};

typedef vector<User> UserList;

void CreateNewUser(UserList* users);

bool EnterToSystem(UserList users, User* user);

Car CreateNewCar();

Report CreateNewReport();

Advertisement CreateNewAdvertisement(User user, AdvertisementList* advertisements);

SearchData CreateNewSearchData();

void PrintAdvertisements(AdvertisementList advertisements);

void DeleteAdvertisement(User user, AdvertisementList* advertisements, Advertisement advertisement);

void AddToFavourites(User* user, Advertisement advertisement);

AdvertisementList SortedAdvertisements(AdvertisementList advertisements, SearchData data);