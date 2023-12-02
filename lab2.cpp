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

int main()
{
    setlocale(LC_ALL, "rus");

    //VirtualVoidTest();
    //OperatorOverloadTest();
    //AbstractClassTest();
}