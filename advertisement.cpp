#include "advertisement.h"

void InputLoginPassword(string* login, int* password) {
	cout << "������� �����: ";
	cin >> *login;
	cout << "������� ������: ";
	cin >> *password;
}

void CreateNewUser(UserList* users)
{
	string login;
	int password, phoneNumber;

	cout << "�����������\n\n";
	InputLoginPassword(&login, &password);
	cout << "������� ����� ��������: ";
	cin >> phoneNumber;

	while (getchar() != '\n');

	users->push_back(User(login, password, phoneNumber));
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

Car CreateNewCar()
{
	string brand, transmission;
	int year, enginePower, mileage;

	cout << "�����: ";
	getline(cin, brand);
	cout << "��� ������������: ";
	cin >> year;
	cout << "�������� ���������: ";
	cin >> enginePower;
	cout << "��� ���: ";
	cin >> transmission;
	cout << "������: ";
	cin >> mileage;

	while (getchar() != '\n');

	return Car(brand, year, enginePower, transmission, mileage);
}

Report CreateNewReport()
{
	int crashesCount, isListedAsWanted, areDocumentsInOrder, isRegistered;

	cout << "���������� ������: ";
	cin >> crashesCount;
	cout << "��������� � �������?(1-��, 0-���): ";
	cin >> isListedAsWanted;
	cout << "��������� � �������?(1-��, 0-���): ";
	cin >> areDocumentsInOrder;
	cout << "����������������?(1-��, 0-���): ";
	cin >> isRegistered;

	while (getchar() != '\n');

	return Report(crashesCount, isListedAsWanted, areDocumentsInOrder, isRegistered);
}

Advertisement CreateNewAdvertisement(User user, AdvertisementList* advertisements)
{
	int price;
	string location;

	Car car = CreateNewCar();
	Report report = CreateNewReport();

	cout << "��������������: ";
	cin >> location;
	cout << "����: ";
	cin >> price;

	while (getchar() != '\n');

	Advertisement advertisement(advertisements->size(), car, report, location, price, user);
	advertisements->push_back(advertisement);

	return advertisement;

}

bool CanEnterFilterField(string question) {
	int command;

	do {
		cout << question;
		cin >> command;
	} while (command != 0 && command != 1);

	while (getchar() != '\n');

	return command == 1;
}

void InputFilterField(string title, int* destination) {
	string question = "���� '" + title + "'(1 - ������, 0 - ����������): ";
	if (CanEnterFilterField(question)) {
		cout << title + ": ";
		cin >> *destination;
	}
	else {
		*destination = -1;
	}
}

void InputFilterField(string title, string* destination) {
	string question = "���� '" + title + "'(1 - ������, 0 - ����������): ";
	if (CanEnterFilterField(question)) {
		cout << title + ": ";
		cin >> *destination;
	}
}

SearchData CreateNewSearchData()
{
	string brand, location;
	int year, price, command;

	cout << "----- ������ -----" << endl << endl;
	InputFilterField("�����", &brand);
	InputFilterField("���", &year);
	InputFilterField("����", &price);
	InputFilterField("��������������", &location);

	while (getchar() != '\n');

	return SearchData(brand, year, price, location);
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

void DeleteAdvertisement(User user, AdvertisementList* advertisements, Advertisement advertisement)
{
	if (advertisement.GetSeller().GetLogin() == user.GetLogin() && advertisement.GetSeller().GetPassword() == user.GetPassword()) {
		advertisements->erase(advertisements->begin() + advertisement.GetIndex());
		cout << "���������� ������� �������!" << endl;
		return;
	}

	cout << "������ ���������� ��� �� �����������, �� �� ������ ��� �������!" << endl;
}

void AddToFavourites(User* user, Advertisement advertisement)
{
	user->GetFavourites().push_back(advertisement);
}

void CompareSearchData(bool expression, int* counter) {
	if (expression) *counter += 1;
}

AdvertisementList SortedAdvertisements(AdvertisementList advertisements, SearchData data)
{
	AdvertisementList list;

	int counter;
	int counterTarget = 4;

	for (Advertisement advertisement : advertisements) {
		CompareSearchData(advertisement.GetCar().GetBrand() == data.GetBrand() || data.GetBrand() == "", &counter);
		CompareSearchData(advertisement.GetCar().GetYear() == data.GetYear() || data.GetYear() == -1, &counter);
		CompareSearchData(advertisement.GetPrice() == data.GetPrice() || data.GetPrice() == -1, &counter);
		CompareSearchData(advertisement.GetLocation() == data.GetLocation() || data.GetLocation() == "", &counter);

		if (counter == counterTarget) {
			list.push_back(advertisement);
		}
	}

	return list;
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
	crashesCount = crashesCount;
}

Report::Report()
{
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

string SearchData::GetBrand()
{
	return _brand;
}

int SearchData::GetYear()
{
	return _year;
}

int SearchData::GetPrice()
{
	return _price;
}

string SearchData::GetLocation()
{
	return _location;
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
