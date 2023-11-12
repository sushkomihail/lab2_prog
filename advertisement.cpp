#include "advertisement.h"

bool IsNumber(string string) {
	for (char symbol : string) {
		if (symbol < '0' || symbol > '9') {
			return false;
		}
	}

	return true;
}

void InputIntField(string request, int* destination)
{	
	string value;

	do {
		cout << request;
		cin >> value;
		while (getchar() != '\n');
	} while (!IsNumber(value));

	*destination = stoi(value);
}

bool InputBoolField(string question)
{
	int command;

	do {
		InputIntField(question, &command);
	} while (command != 0 && command != 1);

	return command == 1;
}

void ChangePassword(User &user)
{
	cout << "----- ����� ������ -----" << endl;
	cout << "���������� ������: " + user._password << endl;
	cout << "������� ����� ������: ";
	cin >> user._password;
	cout << "����� ������: " + user._password << endl;
}

bool EnterToSystem(UserList users, User* user)
{
	User enteredUser;

	cout << "----- ���� � ������ -----" << endl;

	enteredUser.InputLogin();
	enteredUser.InputPassword();

	for (User createdUser : users) {
		if (createdUser.GetLogin() == enteredUser.GetLogin() && createdUser.GetPassword() == enteredUser.GetPassword()) {
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

int Advertisement::_id = 0;

void Advertisement::AssignID()
{
	_currentId = _id++;
}

Advertisement::Advertisement(Car car, Report report, string location, int price, User seller)
{
	AssignID();
	_car = car;
	_report = report;
	_location = location;
	_price = price;
	_seller = seller;
}

Advertisement::Advertisement(Car car)
{
	AssignID();
	_car = car;
	_report = Report();
	_price = 0;
	_seller = User();
}

Advertisement::Advertisement()
{
	AssignID();
	_car = Car();
	_report = Report();
	_price = 0;
	_seller = User();
}

int Advertisement::GetID()
{
	return _currentId;
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

int Advertisement::GetCount()
{
	return _id;
}

void Advertisement::Create(User user, AdvertisementList* advertisements)
{
	Car car;
	Report report;

	car.Create();
	report.Create();

	cout << "��������������: ";
	cin >> _location;
	InputIntField("����: ", &_price);

	_seller = user;

	advertisements->push_back(*this);
}

void Advertisement::Delete(User user, AdvertisementList* advertisements)
{
	if (_seller.GetLogin() != user.GetLogin() || _seller.GetPassword() != user.GetPassword()) {
		cout << "������ ���������� ��� �� �����������, �� �� ������ ��� �������!" << endl;
		return;
	}

	for (int i = 0; i < advertisements->size(); i++) {
		if (advertisements->at(i).GetID() == _currentId) {
			advertisements->erase(advertisements->begin() + i);
			cout << "���������� ������� �������!" << endl;
			return;
		}
	}

	cout << "������� ���������� ��� � ������!";
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

User::User(string login, string password, string phoneNumber)
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

string User::GetPassword()
{
	return _password;
}

string User::GetPhoneNumber()
{
	return _phoneNumber;
}

AdvertisementList User::GetFavourites()
{
	return _favourites;
}

void User::InputLogin()
{
	cout << "������� �����: ";
	cin >> _login;
}

void User::InputPassword()
{
	cout << "������� ������: ";
	cin >> _password;
}

void User::InputPhoneNumber()
{
	do {
		cout << "������� ����� ��������: ";
		cin >> _phoneNumber;
		while (getchar() != '\n');
	} while (!IsNumber(_phoneNumber));
}

void User::Create(UserList* users)
{
	cout << "----- ����������� -----\n\n";
	
	InputLogin();
	InputPassword();
	InputPhoneNumber();

	users->push_back(*this);
}

void User::AddToFavourites(Advertisement advertisement)
{
	_favourites.push_back(advertisement);
	cout << "���������� (id = " << advertisement.GetID() << ") ��������� � ���������!" << endl;
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
	_year = 0;
	_enginePower = 0;
	_mileage = 0;
}

Car::Car()
{
	_year = 0;
	_enginePower = 0;
	_mileage = 0;
}

Car Car::operator+(const Car& car)
{
	Car tmp;
	tmp._brand = _brand + car._brand;
	tmp._year = _year + car._year;
	tmp._enginePower = _enginePower + car._enginePower;
	tmp._transmission = _transmission + car._transmission;
	tmp._mileage = _enginePower + car._mileage;
	return tmp;
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
	InputIntField("��� ������������: ", &_year);
	InputIntField("�������� ���������: ", &_enginePower);
	cout << "��� ���: ";
	cin >> _transmission;
	InputIntField("������: ", &_mileage);
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
	_crashesCount = 0;
}

void Report::Create()
{
	InputIntField("���������� ������: ", &_crashesCount);
	_isListedAsWanted = InputBoolField("��������� � �������?(1-��, 0-���): ");
	_areDocumentsInOrder = InputBoolField("��������� � �������?(1-��, 0-���): ");
	_isRegistered = InputBoolField("����������������?(1-��, 0-���): ");
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
	if (expression) counter += 1;
}

void SearchData::InputFilterField(string request, int* destination)
{
	string question = "���� '" + request + "'(1 - ������, 0 - ����������): ";
	if (InputBoolField(question)) {
		InputIntField(request + ": ", destination);
	}
	else {
		*destination = -1;
	}
}

void SearchData::InputFilterField(string request, string& destination)
{
	string question = "���� '" + request + "'(1 - ������, 0 - ����������): ";
	if (InputBoolField(question)) {
		cout << request + ": ";
		cin >> destination;
		while (getchar() != '\n');
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
	_year = 0;
	_price = 0;
}

SearchData::SearchData()
{
	_year = 0;
	_price = 0;
}

SearchData::SearchData(const SearchData &data)
{
	_brand = data._brand;
	_year = data._year;
	_price = data._price;
	_location = data._location;
}

SearchData& SearchData::operator++()
{
	_year++;
	_price++;
	return *this;
}

SearchData& SearchData::operator++(int value)
{
	SearchData tmp(*this);
	_year++;
	_price++;
	return tmp;
}

void SearchData::Create()
{
	cout << "----- ������ -----" << endl << endl;
	InputFilterField("�����", _brand);
	InputFilterField("���", &_year);
	InputFilterField("������������ ����", &_price);
	InputFilterField("��������������", _location);
}

AdvertisementList SearchData::SortAdvertisementList(AdvertisementList list)
{
	AdvertisementList newlist;

	int counter = 0;

	for (Advertisement advertisement : list) {
		CompareSearchData(advertisement.GetCar().GetBrand() == _brand || _brand == "", &counter);
		CompareSearchData(advertisement.GetCar().GetYear() == _year || _year == -1, &counter);
		CompareSearchData(advertisement.GetPrice() <= _price || _price == -1, &counter);
		CompareSearchData(advertisement.GetLocation() == _location || _location == "", &counter);

		if (counter == COMPARES_TARGET) {
			newlist.push_back(advertisement);
		}

		counter = 0;
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
	cout << "������������ ����: " << price << endl;
	cout << "��������������: " << location << endl;
}
