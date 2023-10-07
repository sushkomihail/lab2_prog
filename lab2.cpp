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

int main()
{
    setlocale(LC_ALL, "rus");

    ArrayWithDynamicObjects();
    DynamicArrayWithObjects();
}