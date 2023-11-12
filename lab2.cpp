#include "advertisement.h"

void ArrayWithDynamicObjects() {
    Report* r1 = new Report(1, false, false, false);
    Report* r2 = new Report(2);
    Report* r3 = new Report(5, true, true, true);

    Report reports[3] = { *r1, *r2, *r3 };

    cout << "----- Массив с динамическими объектами -----" << endl;
    for (Report report : reports) {
        report.PrintReportData();
        cout << endl;
    }
}

void DynamicArrayWithObjects() {
    int n = 3;
    Report* reports = new Report[n]{ Report(1, true, false, true), Report(5), Report(3, false, true, false) };

    cout << "----- Динамический массив с объектами -----" << endl;
    for (int i = 0; i < n; i++) {
        reports[i].PrintReportData();
        cout << endl;
    }

    delete[] reports;
}

void StaticField() {
    Advertisement advs[]{Advertisement(Car("toyota")), Advertisement(Car("nissan")), Advertisement(Car("subaru"))};
    
    cout << "----- Пример работы со статическим полем -----" << endl;
    for (Advertisement adv : advs) {
        cout << "Объявление(" + adv.GetCar().GetBrand() + "); id - " << adv.GetID() << endl;
    }
}

void StaticVoid() {
    cout << "----- Пример работы со статическим методом -----" << endl;
    cout << "Количество объявлений - " << Advertisement::GetCount() << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    //ArrayWithDynamicObjects();
    //DynamicArrayWithObjects();

    //StaticField();
    //StaticVoid();

    /*SearchData data;
    data.Create();
    data.PrintSearchData();*/

    /*User user("mihail");
    AdvertisementList list;
    Advertisement adv;
    adv.Create(user, &list);
    cout << "\nКоличество объявлений: " << list.size() << endl;*/

    //User user("mihail", "123h45", "88888888888");
    //ChangePassword(user);

    /*Car car1("toyota", 2004, 200, "auto", 100000);
    Car car2("nissan", 2000, 280, "manual", 150000);
    car1.PrintCarData();
    cout << endl;
    car2.PrintCarData();
    cout << endl;
    Car car3 = car1 + car2;
    car3.PrintCarData();*/

    SearchData data("toyota", 2004, 200000, "barnaul");
    cout << "data" << endl;
    data.PrintSearchData();
    cout << endl;
    SearchData data1 = data++;
    cout << "data1" << endl;
    data1.PrintSearchData();
    cout << endl;
    cout << "data" << endl;
    data.PrintSearchData();
}