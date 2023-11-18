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
    
    //cout << "----- Пример работы со статическим полем -----" << endl;
    for (Advertisement adv : advs) {
        cout << "Объявление(" + adv.GetCar().GetBrand() + "); id - " << adv.GetID() << endl;
    }
}

void StaticVoid() {
    cout << "----- Пример работы со статическим методом -----" << endl;
    cout << "Количество объявлений - " << Advertisement::GetCount() << endl;
}

void TryCatch() {
    User user;
    user.Create();
    user.Create();

    UserList list = GetUserList();

    cout << endl;

    for (User user : list) {
        cout << "Логин: " << user.GetLogin() << "; Пароль: " << user.GetPassword() << "; Телефон: " << user.GetPhoneNumber() << endl;
    }
}

void TwoDimensionalArray() {
    Car cars[2][2]{ { Car("toyota"), Car("mazda") }, { Car("nissan"), Car("honda") } };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << cars[i][j].GetBrand() << "\t";
        }
        cout << endl;
    }

    cout << endl << "Элеметы главной диагонали: ";

    for (int i = 0; i < 2; i++) {
        cout << cars[i][i].GetBrand() << "  ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    /*cout << "Try-catch:" << endl;
    TryCatch();*/

    cout << "Одномерный массив:" << endl;
    StaticField();

    cout << "\nДвумерный массив:" << endl;
    TwoDimensionalArray();
}