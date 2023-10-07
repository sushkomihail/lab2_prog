#include "advertisement.h"

void Static() {
    static Report report = InitReport(0, false, true, true);
    report.CrashesCount += 1;
    cout << report.CrashesCount << endl;
}

void Dynamic() {
    User* userA = new User;
    User userB = InitUser("Михаил", 12345, 88005553535);
    *userA = userB;
    cout << userA->Login;
    delete userA;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Static();
    Static();
    Static();

    Dynamic();
}