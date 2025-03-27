#include <iostream>
using namespace std;

bool IsLeapYear(short Year) {
    // Leap year if perfectly divisible by 400
    if (Year % 400 == 0) {
        return true;
    }
    // Not a leap year if divisible by 100 but not divisible by 400
    else if (Year % 100 == 0) {
        return false;
    }
    // Leap year if not divisible by 100 but divisible by 4
    else if (Year % 4 == 0) {
        return true;
    }
    // All other years are not leap years
    else {
        return false;
    }
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}

int main() {
    short Year = ReadYear();
    if (IsLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

    system("read -p 'Press Enter to continue...' var");
    return 0;
}
