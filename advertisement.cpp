#include "advertisement.h"

void InputLoginPassword(string* login, int* password) {
	cout << "������� �����: ";
	cin >> *login;
	cout << "������� ������: ";
	cin >> *password;
}

bool EnterToSystem(UserList users, User* user)
{
	string login;
	int password;

	InputLoginPassword(&login, &password);

	while (getchar() != '\n');

	for (User createdUser : users) {
		if (createdUser.GetLogin() == login && createdUser.GetPassword() == password) {
			*user = createdUser;
			return true;
		}
	}

	return false;
}

void PrintAdvertisements(AdvertisementList advertisements)
{
	if (advertisements.size() == 0) {
		cout << "���������� ���!" << endl;
		return;
	}

	for (Advertisement advertisement : advertisements)
	{
		advertisement.PrintAdvertisementData();
		cout << endl;
	}
}

Advertisement::Advertisement(int index, Car car, Report report, string location, int price, User seller)
{
	_index = index;
	_car = car;
	_report = report;
	_location = location;
	_price = price;
	_seller = seller;
}

Advertisement::Advertisement(int index)
{
	_index = index;
}

Advertisement::Advertisement()
{
}

int Advertisement::GetIndex()
{
	return _index;
}

Car Advertisement::GetCar()
{
	return _car;
}

string Advertisement::GetLocation()
{
	return _location;
}

int Advertisement::GetPrice()
{
	return _price;
}

User Advertisement::GetSeller()
{
	return _seller;
}

void Advertisement::Create(User user, AdvertisementList* advertisements)
{
	Car car;
	Report report;

	car.Create();
	report.Create();

	cout << "��������������: ";
	cin >> _location;
	cout << "����: ";
	cin >> _price;

	while (getchar() != '\n');

	_index = advertisements->size();
	_seller = user;

	advertisements->push_back(*this);
}

void Advertisement::AddToFavourites(User* user)
{
	user->GetFavourites().push_back(*this);
}

void Advertisement::Delete(User user, AdvertisementList* advertisements)
{
	if (_seller.GetLogin() == user.GetLogin() && _seller.GetPassword() == user.GetPassword()) {
		advertisements->erase(advertisements->begin() + _index);
		cout << "���������� ������� �������!" << endl;
		return;
	}

	cout << "������ ���������� ��� �� �����������, �� �� ������ ��� �������!" << endl;
}

void Advertisement::PrintAdvertisementData()
{
	cout << "---------- ���������� (" << _location << ") ----------" << endl << endl;
	_car.PrintCarData();
	cout << endl;
	_report.PrintReportData();
	cout << endl;
	cout << "����: " << _price << endl << endl;
	cout << "������� ��������: " << _seller.GetPhoneNumber() << endl;
}

User::User(string login, int password, int phoneNumber)
{
	_login = login;
	_password = password;
	_phoneNumber = phoneNumber;
}

User::User(string login)
{
	_login = login;
}

User::User()
{
}

string User::GetLogin()
{
	return _login;
}

int User::GetPassword()
{
	return _password;
}

int User::GetPhoneNumber()
{
	return _phoneNumber;
}

AdvertisementList User::GetFavourites()
{
	return _favourites;
}

void User::Create(UserList* users)
{
	cout << "�����������\n\n";
	InputLoginPassword(&_login, &_password);
	cout << "������� ����� ��������: ";
	cin >> _phoneNumber;

	while (getchar() != '\n');

	users->push_back(*this);
}

void User::PrintUserData()
{
	cout << "----- ������ ������������ -----" << endl;
	cout << "�����: " + _login << endl;
	cout << "����� ��������: " << _phoneNumber << endl;
	cout << "��������� ����������: " << endl;
	PrintAdvertisements(_favourites);
}

Car::Car(string brand, int year, int enginePower, string transmission, int mileage)
{
	_brand = brand;
	_year = year;
	_enginePower = enginePower;
	_transmission = transmission;
	_mileage = mileage;
}

Car::Car(string brand)
{
	_brand = brand;
}

Car::Car()
{
}

string Car::GetBrand()
{
	return _brand;
}

int Car::GetYear()
{
	return _year;
}

void Car::Create()
{
	cout << "�����: ";
	getline(cin, _brand);
	cout << "��� ������������: ";
	cin >> _year;
	cout << "�������� ���������: ";
	cin >> _enginePower;
	cout << "��� ���: ";
	cin >> _transmission;
	cout << "������: ";
	cin >> _mileage;

	while (getchar() != '\n');
}

void Car::PrintCarData()
{
	cout << "<<< ������ �� ���������� >>>" << endl;
	cout << "�����: " + _brand << endl;
	cout << "��� ������������: " << _year << endl;
	cout << "�������� ���������: " << _enginePower << endl;
	cout << "���: " + _transmission << endl;
	cout << "������: " << _mileage << endl;
}

Report::Report(int crashesCount, bool isListedAsWanted, bool areDocumentsInOrder, bool isRegistered)
{
	_crashesCount = crashesCount;
	_isListedAsWanted = isListedAsWanted;
	_areDocumentsInOrder = areDocumentsInOrder;
	_isRegistered = isRegistered;
}

Report::Report(int crashesCount)
{
	_crashesCount = crashesCount;
}

Report::Report()
{
}

void Report::Create()
{
	cout << "���������� ������: ";
	cin >> _crashesCount;
	cout << "��������� � �������?(1-��, 0-���): ";
	cin >> _isListedAsWanted;
	cout << "��������� � �������?(1-��, 0-���): ";
	cin >> _areDocumentsInOrder;
	cout << "����������������?(1-��, 0-���): ";
	cin >> _isRegistered;

	while (getchar() != '\n');
}

void Report::PrintReportData()
{
	cout << "<<< ����� �� ���������� >>>" << endl;
	cout << "���������� ������: " << _crashesCount << endl;
	string wanted = _isListedAsWanted ? "��������� � �������" : "�� ��������� � �������";
	cout << wanted << endl;
	string documents = _areDocumentsInOrder ? "��������� � �������" : "��������� �� � �������";
	cout << documents << endl;
	string registration = _isRegistered ? "����������������" : "�� ����������������";
	cout << registration << endl;
}

void SearchData::CompareSearchData(bool expression, int* counter)
{
	if (expression) *counter += 1;
}

bool SearchData::CanEnterFilterField(string question)
{
	int command;

	do {
		cout << question;
		cin >> command;
	} while (command != 0 && command != 1);

	while (getchar() != '\n');

	return command == 1;
}

void SearchData::InputFilterField(string title, int* destination)
{
	string question = "���� '" + title + "'(1 - ������, 0 - ����������): ";
	if (CanEnterFilterField(question)) {
		cout << title + ": ";
		cin >> *destination;
	}
	else {
		*destination = -1;
	}
}

void SearchData::InputFilterField(string title, string* destination)
{
	string question = "���� '" + title + "'(1 - ������, 0 - ����������): ";
	if (CanEnterFilterField(question)) {
		cout << title + ": ";
		cin >> *destination;
	}
}

SearchData::SearchData(string brand, int year, int price, string location)
{
	_brand = brand;
	_year = year;
	_price = price;
	_location = location;
}

SearchData::SearchData(string brand)
{
	_brand = brand;
}

SearchData::SearchData()
{
}

void SearchData::Create()
{
	cout << "----- ������ -----" << endl << endl;
	InputFilterField("�����", &_brand);
	InputFilterField("���", &_year);
	InputFilterField("����", &_price);
	InputFilterField("��������������", &_location);

	while (getchar() != '\n');
}

AdvertisementList SearchData::SortAdvertisementList(AdvertisementList list)
{
	AdvertisementList newlist;

	int counter;

	for (Advertisement advertisement : list) {
		CompareSearchData(advertisement.GetCar().GetBrand() == _brand || _brand == "", &counter);
		CompareSearchData(advertisement.GetCar().GetYear() == _year || _year == -1, &counter);
		CompareSearchData(advertisement.GetPrice() == _price || _price == -1, &counter);
		CompareSearchData(advertisement.GetLocation() == _location || _location == "", &counter);

		if (counter == COMPARES_TARGET) {
			newlist.push_back(advertisement);
		}
	}

	return newlist;
}

void SearchData::PrintSearchData()
{
	string brand = _brand == "" ? "���" : _brand;
	string year = _year == -1 ? "���" : to_string(_year);
	string price = _price == -1 ? "���" : to_string(_price);
	string location = _location == "" ? "���" : _location;

	cout << "----- ��������� ������ -----" << endl << endl;
	cout << "�����: " << brand << endl;
	cout << "���: " << year << endl;
	cout << "����: " << price << endl;
	cout << "��������������: " << location << endl;
}
