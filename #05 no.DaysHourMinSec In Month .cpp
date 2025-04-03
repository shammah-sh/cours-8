#include<iostream>
using namespace std;
short ReadYear(){
    short year;
    cout<<"Enter a Year : ";
    cin>>year;
    return year;
}
short ReadMonth(){

    short Month;
    cout<<"Enter a Month : ";
    cin>>Month;

    return Month;
}
bool IsLeepYear(short Year){
    return ( (Year%4==0 && Year%100 != 0) || ( Year%400==0 ) );
}
short NumberOfDaysInMonth(short Year,short Month) {

    if(Month<1 || Month>12) return 0;

    if(Month==2){
         return (IsLeepYear(Year)) ? 29 : 28;
    }

    short arr31DaysMonths[]={1,3,5,7,8,10,12};

    for(short i =1 ; i<=12 ; i++){
        if(arr31DaysMonths[i-1]==Month) return 31;
    }
    return 30;
}
int NumberOfHoursInMonth(short Year,short Month){
    return NumberOfDaysInMonth(Year,Month) * 24;
}
int NumberOfMinutesInMonth(short Year,short Month){
    return NumberOfHoursInMonth(Year,Month)*60;
}
int NumberOfSecondsInMonth(short Year ,short Month){
    return NumberOfMinutesInMonth(Year,Month)* 60;
}
int main(){
    short Year=ReadYear();
    short Month=ReadMonth();
    cout << "\nNumber of Days in Month [" << Month << "] is "<< NumberOfDaysInMonth(Year,Month);
    cout << "\nNumber of Hours in Month [" << Month << "] is "<<NumberOfHoursInMonth(Year,Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is "<< NumberOfMinutesInMonth(Year,Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is "<< NumberOfSecondsInMonth(Year,Month);

    return 0;
}
