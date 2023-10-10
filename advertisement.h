#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Advertisement;
struct User;

typedef vector<User> UserList;
typedef vector<Advertisement> AdvertisementList;

struct User {
	string Login;
	string Password;
	string PhoneNumber;
	vector<Advertisement> Favourites;
};

struct Car {
	string Brand;
	int Year;
	int EnginePower;
	string Transmission;
	int Mileage;
};

struct Report {
	int CrashesCount;
	bool IsListedAsWanted;
	bool AreDocumentsInOrder;
	bool IsRegistered;
};

struct Advertisement {
	static int ID;
	int CurrentID;
	Car Car;
	Report Report;
	string Location;
	int Price;
	User Seller;
};

struct SearchData {
	const int COUNTER_TARGET = 4;
	string Brand;
	int Year;
	int Price;
	string Location;
};

User InitUser(string login, string password, string phoneNumber);

void CreateNewUser(UserList* users);

bool EnterToSystem(UserList users, User* user);

Car InitCar(string brand, int year, int enginePower, string transmission, int mileage);

Car CreateNewCar();

void PrintCarData(Car car);

Report InitReport(int crashesCount, bool isListedAsWanted, bool areDocumentsInOrder, bool isRegistered);

Report CreateNewReport();

void PrintReportData(Report report);

void AssignID(Advertisement* advertisement);

Advertisement InitAdvertisement(Car car, Report report, string location, int price, User seller);

Advertisement CreateNewAdvertisement(User user, AdvertisementList* advertisements);

void PrintAdvertisement(Advertisement advertisement);

SearchData InitSearchData(string brand, int year, int price, string location);

SearchData CreateNewSearchData();

void PrintSearchData(SearchData data);

void PrintAdvertisements(AdvertisementList advertisements);

void DeleteAdvertisement(User user, AdvertisementList* advertisements, Advertisement advertisement);

void AddToFavourites(User* user, Advertisement advertisement);

AdvertisementList SortedAdvertisements(AdvertisementList advertisements, SearchData data);