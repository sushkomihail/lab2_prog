#include "advertisement.h"

void Static() {
    static Report report = InitReport(0, false, true, true);
    report.CrashesCount += 1;
    cout << report.CrashesCount << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Static();
    Static();
    Static();
}