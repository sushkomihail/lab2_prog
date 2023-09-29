#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Advertisement;

struct User {
	string Login;
	int Password;
	int PhoneNumber;
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
	int Index;
	Car Car;
	Report Report;
	string Location;
	int Price;
	User Seller;
};

struct SearchData {
	string Brand;
	int Year;
	int Price;
	string Location;
};

typedef vector<User> UserList;
typedef vector<Advertisement> AdvertisementList;

User InitUser(string login, int password, int phoneNumber);

void CreateNewUser(UserList* users);

bool EnterToSystem(UserList users, User* user);

Car InitCar(string brand, int year, int enginePower, string transmission, int mileage);

Car CreateNewCar();

void PrintCarData(Car car);

Report InitReport(int crashesCount, bool isListedAsWanted, bool areDocumentsInOrder, bool isRegistered);

Report CreateNewReport();

void PrintReportData(Report report);

Advertisement InitAdvertisement(int index, Car car, Report report, string location, int price, User seller);

Advertisement CreateNewAdvertisement(User user, AdvertisementList* advertisements);

void PrintAdvertisement(Advertisement advertisement);

SearchData InitSearchData(string brand, int year, int price, string location);

SearchData CreateNewSearchData();

void PrintSearchData(SearchData data);

void PrintAdvertisements(AdvertisementList advertisements);

void DeleteAdvertisement(User user, AdvertisementList* advertisements, Advertisement advertisement);

void AddToFavourites(User* user, Advertisement advertisement);

AdvertisementList SortedAdvertisements(AdvertisementList advertisements, SearchData data);