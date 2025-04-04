#include<iostream>
using namespace std;
struct stDate {
    short Day;
    short Month;
    short Year;
};

short ReadDaysAdd(){
    
    short Days=0;

    cout<<"How many days do you want to add : ";
    cin>>Days;
    
    return Days;
}
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
short ReadDay(){
    short Day;
    cout<<"Enter a Day : ";
    cin>>Day;
    return Day;
}

stDate ReadFullDate(){

    stDate Date;

    Date.Year=ReadYear();
    Date.Month=ReadMonth();
    Date.Day=ReadDay();
    
    return Date;
}
void PrintDate(stDate Date ){
    cout<<"Date : "<<Date.Year<<"/"<<Date.Month<<"/"<<Date.Day<<endl;
}
bool IsLastDayInMonth(stDate Date){
    short LastDayInMonth=NumberOfDaysInMonth(Date.Year,Date.Month);
    return Date.Day==LastDayInMonth;
}
bool IsLastMonthInYear(short Month){
    return Month == 12 ;
}
int main(){

    system("clear");
    
    stDate Date=ReadFullDate();
    PrintDate(Date);
    if(IsLastDayInMonth(Date))
    {
        cout<<"Yes, Day is Last Day in the month.\n";
    } 
        else 
    {
        cout<<"No, Day isn't Last day in month. \n";
    }
    return 0;
}
