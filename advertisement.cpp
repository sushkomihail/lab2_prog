#include "advertisement.h"

void InputLogin(string* login) {
	cout << "������� �����: ";
	cin >> *login;
}

void InputPassword(string* password) {
	cout << "������� ������: ";
	cin >> *password;
}

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

void InputPhoneNumber(string* phoneNumber) {
	do {
		cout << "������� ����� ��������: ";
		cin >> *phoneNumber;
		while (getchar() != '\n');
	} while (!IsNumber(*phoneNumber));
}

User InitUser(string login, string password, string phoneNumber)
{
	User user;
	user.Login = login;
	user.Password = password;
	user.PhoneNumber = phoneNumber;

	return user;
}

void CreateNewUser(UserList* users)
{
	string login, password, phoneNumber;

	cout << "�����������\n\n";
	InputLogin(&login);
	InputPassword(&password);
	InputPhoneNumber(&phoneNumber);

	while (getchar() != '\n');

	users->push_back(InitUser(login, password, phoneNumber));
}

bool EnterToSystem(UserList users, User* user)
{
	string login, password;

	InputLogin(&login);
	InputPassword(&password);

	for (User createdUser : users) {
		if (createdUser.Login == login && createdUser.Password == password) {
			*user = createdUser;
			return true;
		}
	}

	return false;
}

Car InitCar(string brand, int year, int enginePower, string transmission, int mileage)
{
	Car car;
	car.Brand = brand;
	car.Year = year;
	car.EnginePower = enginePower;
	car.Transmission = transmission;
	car.Mileage = mileage;

	return car;
}

Car CreateNewCar()
{
	string brand, transmission;
	int year, enginePower, mileage;

	cout << "�����: ";
	getline(cin, brand);
	InputIntField("��� ������������: ", &year);
	InputIntField("�������� ���������: ", &enginePower);
	cout << "��� ���: ";
	cin >> transmission;
	InputIntField("������: ", &mileage);

	return InitCar(brand, year, enginePower, transmission, mileage);
}

void PrintCarData(Car car)
{
	cout << "<<< ������ �� ���������� >>>" << endl;
	cout << "�����: " + car.Brand << endl;
	cout << "��� ������������: " << car.Year << endl;
	cout << "�������� ���������: " << car.EnginePower << endl;
	cout << "���: " + car.Transmission << endl;
	cout << "������: " << car.Mileage << endl;
}

Report InitReport(int crashesCount, bool isListedAsWanted, bool areDocumentsInOrder, bool isRegistered)
{
	Report report;
	report.CrashesCount = crashesCount;
	report.IsListedAsWanted = isListedAsWanted;
	report.AreDocumentsInOrder = areDocumentsInOrder;
	report.IsRegistered = isRegistered;

	return report;
}

Report CreateNewReport()
{
	int crashesCount, isListedAsWanted, areDocumentsInOrder, isRegistered;

	InputIntField("���������� ������: ", &crashesCount);
	isListedAsWanted = InputBoolField("��������� � �������?(1-��, 0-���): ");
	areDocumentsInOrder = InputBoolField("��������� � �������?(1-��, 0-���): ");
	isRegistered = InputBoolField("����������������?(1-��, 0-���): ");

	return InitReport(crashesCount, isListedAsWanted, areDocumentsInOrder, isRegistered);
}

void PrintReportData(Report report)
{
	cout << "<<< ����� �� ���������� >>>" << endl;
	cout << "���������� ������: " << report.CrashesCount << endl;
	string wanted = report.IsListedAsWanted ? "��������� � �������" : "�� ��������� � �������";
	cout << wanted << endl;
	string documents = report.AreDocumentsInOrder ? "��������� � �������" : "��������� �� � �������";
	cout << documents << endl;
	string registration = report.IsRegistered ? "����������������" : "�� ����������������";
	cout << registration << endl;
}

int Advertisement::ID = 0;

void AssignID(Advertisement* advertisement)
{
	advertisement->CurrentID = advertisement->ID++;
}

Advertisement InitAdvertisement(Car car, Report report, string location, int price, User seller)
{
	Advertisement advertisement;
	AssignID(&advertisement);
	advertisement.Car = car;
	advertisement.Report = report;
	advertisement.Location = location;
	advertisement.Price = price;
	advertisement.Seller = seller;

	return advertisement;
}

Advertisement CreateNewAdvertisement(User user, AdvertisementList* advertisements)
{
	int price;
	string location;

	Car car = CreateNewCar();
	Report report = CreateNewReport();

	cout << "��������������: ";
	cin >> location;
	InputIntField("����: ", &price);

	Advertisement advertisement = InitAdvertisement(car, report, location, price, user);
	AssignID(&advertisement);
	advertisements->push_back(advertisement);

	return advertisement;

}

void PrintAdvertisement(Advertisement advertisement)
{
	cout << "---------- ���������� (" << advertisement.Location << ") ----------" << endl << endl;
	PrintCarData(advertisement.Car);
	cout << endl;
	PrintReportData(advertisement.Report);
	cout << endl;
	cout << "����: " << advertisement.Price << endl << endl;
	cout << "������� ��������: " << advertisement.Seller.PhoneNumber << endl;
}

SearchData InitSearchData(string brand, int year, int price, string location)
{
	SearchData data;
	data.Brand = brand;
	data.Year = year;
	data.Price = price;
	data.Location = location;

	return data;
}

void InputFilterField(string title, int* destination) {
	string question = "���� '" + title + "'(1 - ������, 0 - ����������): ";
	if (InputBoolField(question)) {
		InputIntField(title + ": ", destination);
	}
	else {
		*destination = -1;
	}
}

void InputFilterField(string title, string* destination) {
	string question = "���� '" + title + "'(1 - ������, 0 - ����������): ";
	if (InputBoolField(question)) {
		cout << title + ": ";
		cin >> *destination;
		while (getchar() != '\n');
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

	return InitSearchData(brand, year, price, location);
}

void PrintSearchData(SearchData data)
{
	string brand = data.Brand == "" ? "���" : data.Brand;
	string year = data.Year == -1 ? "���" : to_string(data.Year);
	string price = data.Price == -1 ? "���" : to_string(data.Price);
	string location = data.Location == "" ? "���" : data.Location;

	cout << "----- ��������� ������ -----" << endl << endl;
	cout << "�����: " << brand << endl;
	cout << "���: " << year << endl;
	cout << "����: " << price << endl;
	cout << "��������������: " << location << endl;
}

void PrintAdvertisements(AdvertisementList advertisements)
{
	if (advertisements.size() == 0) {
		cout << "���������� ���!" << endl;
		return;
	}

	for (Advertisement advertisement : advertisements)
	{
		PrintAdvertisement(advertisement);
		cout << endl;
	}
}

void DeleteAdvertisement(User user, AdvertisementList* advertisements, Advertisement advertisement)
{
	if (advertisement.Seller.Login != user.Login || advertisement.Seller.Password != user.Password) {
		cout << "������ ���������� ��� �� �����������, �� �� ������ ��� �������!" << endl;
		return;
	}

	for (int i = 0; i < advertisements->size(); i++) {
		if (advertisements->at(i).CurrentID == advertisement.CurrentID) {
			advertisements->erase(advertisements->begin() + i);
			cout << "���������� ������� �������!" << endl;
			return;
		}
	}

	cout << "������� ���������� ��� � ������!";
}

void AddToFavourites(User* user, Advertisement advertisement)
{
	user->Favourites.push_back(advertisement);
}

void CompareSearchData(bool expression, int* counter) {
	if (expression) *counter += 1;
}

AdvertisementList SortedAdvertisements(AdvertisementList advertisements, SearchData data)
{
	AdvertisementList list;

	int counter = 0;

	for (Advertisement advertisement : advertisements) {
		CompareSearchData(advertisement.Car.Brand == data.Brand || data.Brand == "", &counter);
		CompareSearchData(advertisement.Car.Year == data.Year || data.Year == -1, &counter);
		CompareSearchData(advertisement.Price <= data.Price || data.Price == -1, &counter);
		CompareSearchData(advertisement.Location == data.Location || data.Location == "", &counter);

		if (counter == data.COUNTER_TARGET) {
			list.push_back(advertisement);
		}

		counter = 0;
	}

	return list;
}
