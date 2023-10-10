#include "advertisement.h"

void Dynamic() {
    User* userA = new User;
    User userB = InitUser("Михаил", "12345", "88005553535");
    *userA = userB;
    cout << userA->Login;
    delete userA;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "----- Статическая переменная -----" << endl;
    Advertisement adv1 = InitAdvertisement(Car(), Report(), "", 1, User());
    Advertisement adv2 = InitAdvertisement(Car(), Report(), "", 2, User());
    Advertisement adv3 = InitAdvertisement(Car(), Report(), "", 3, User());
    cout << adv1.CurrentID << endl;
    cout << adv2.CurrentID << endl;
    cout << adv3.CurrentID << endl;
    cout << endl;

    cout << "----- Динамическая переменная -----" << endl;
    Dynamic();
}