#include<iostream>
using namespace std;
short ReadYear(){
    short year;
    cout<<"Enter a Year : ";
    cin>>year;
    return year;
}
bool IsLeepYear(short Year){
    return ( (Year%4==0 && Year%100 != 0) || ( Year%400==0 ) );
}
int NumberOfDaysInAYear(short year){
    return (IsLeepYear(year)) ? 366 : 365 ;
}
int NumberOfHoursInAYear(int year){
    return NumberOfDaysInAYear(year) * 24 ;
}
int NumberOfMinutesInAYear(int year){
    return NumberOfHoursInAYear(year) * 60;
}
int NumberOfSecondsInAYear(int year){
    return NumberOfMinutesInAYear(year)*60;
}

int main(){
    short Year=ReadYear();

    cout << "\nNumber of Days in Year [" << Year << "] is "<< NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours in Year [" << Year << "] is "<< NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is "<< NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is "<< NumberOfSecondsInAYear(Year);

    return 0;
}
