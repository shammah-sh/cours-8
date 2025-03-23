#include <iostream>
using namespace std;

short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

short ReadDay() {
    short Day;
    do {
        cout << "\nPlease enter a Day (1-31): ";
        cin >> Day;
    } while (Day < 1 || Day > 31);
    return Day;
}

short ReadMonth() {
    short Month;
    do {
        cout << "\nPlease enter a Month (1-12): ";
        cin >> Month;
    } while (Month < 1 || Month > 12);
    return Month;
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year: ";
    cin >> Year;
    return Year;
}

int main() {
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << "\nDate: " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order: " << DayOfWeekOrder(Day, Month, Year);
    cout << "\nDay Name: " << DayShortName(DayOfWeekOrder(Day, Month, Year));
    system("read -p 'Press Enter to exit...'");// i'm one mac so i can't use system("pause")
    return 0;
}
