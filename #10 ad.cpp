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

    if(Month<1 || Month > 12) return 0;

    short NumberOfDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month==2) ? (IsLeepYear(Year) ? 29 : 28) : NumberOfDays[Month-1] ;
    
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
short ReadDay(){
    short Day;
    cout<<"Enter a Day : ";
    cin>>Day;
    return Day;
}
short NumberOfDaysFormBeginingOfTheYear(short Year,short Month,short Day){

    short TotalDays=0;

    for(int i = 1; i<=Month-1;i++){
        TotalDays+=NumberOfDaysInMonth(Year,i);
    }
    TotalDays+=Day;

    return TotalDays;
}
int main(){

    system("clear");
    short Year=ReadYear();
    short Month=ReadMonth();
    short Day=ReadDay();

    cout<<"Number Of Days since the begining of the year is : "<<NumberOfDaysFormBeginingOfTheYear(Year,Month,Day)<<endl;

    return 0;
}
