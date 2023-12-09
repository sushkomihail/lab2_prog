#include "advertisement.h"

void VirtualVoidTest() {
    Car testCar("dodge");
    Truck testTruck("peterbilt");

    cout << "(Виртуальная функция)" << endl;
    cout << "*car = &testCar:" << endl;
    Car* car = &testCar;
    car->PrintCarData();
    cout << "----------------------------" << endl;
    cout << "*car = &testTruck:" << endl;
    car = &testTruck;
    car->PrintCarData();

    cout << "\n(Невиртуальная функция)" << endl;
    cout << "*car = &testCar:" << endl;
    car = &testCar;
    car->PrintCarData1();
    cout << "----------------------------" << endl;
    cout << "*car = &testTruck:" << endl;
    car = &testTruck;
    car->PrintCarData1();

    cout << "\n(Вызов виртуальной функции невиртуальной базового класса)" << endl;
    cout << "*car = &testCar:" << endl;
    car = &testCar;
    car->Print();
    cout << "----------------------------" << endl;
    cout << "*car = &testTruck:" << endl;
    car = &testTruck;
    car->Print();
}

void OperatorOverloadTest() {
    cout << "truck = car:" << endl;
    Car car = Car("ford");
    Truck truck;
    truck = car;
    truck.PrintCarData();
}

void AbstractClassTest() {
    cout << "Абстрактный класс:" << endl;
    BaseSearchData bs;
    bs.Create();
    bs.PrintSearchData();

    ExtensiveSearchData es;
    es.Create();
    es.PrintSearchData();
}

void SorTest(vector<Car> vector) {
    cout << "Сортировка по пробегу" << endl;
    sort(vector.begin(), vector.end(), [](Car& car1, Car car2) {
        return car1.GetMileage() < car2.GetMileage();
        });

    for (Car car : vector) {
        car.PrintCarData();
    }
}

void FindTest(vector<Car> vector) {
    cout << "Поиск 'dodge'" << endl;

    for (Car car : vector) {
        car.PrintCarData();
    }

    auto result = find_if(vector.begin(), vector.end(), [](Car& car) {
        return car.GetBrand() == "dodge";
        });

    if (result == vector.end()) {
        cout << "Не найдено!";
        return;
    }
    
    cout << "****** Найдено! " << "индекс: " << result - vector.begin();
}

int main()
{
    setlocale(LC_ALL, "rus");

    //VirtualVoidTest();
    //OperatorOverloadTest();
    //AbstractClassTest();

    vector<Car> v = { Car("toyota", 1, 1, "m", 1), Truck("peterbilt", 1, 1, "a", 3, 1), Car("dodge", 1, 1, "a", 2) };
    SorTest(v);
    cout << "---------------------" << endl;
    FindTest(v);
}