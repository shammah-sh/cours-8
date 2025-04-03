#include<iostream>
using namespace std;
struct stDate {
    short Day;
    short Month;
    short Year;
};
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
short NumberOfDaysFormBeginingOfTheYear(short Year,short Month,short Day){
    
    short TotalDays=0;

    for(int i = 1; i<=Month-1;i++){
        TotalDays+=NumberOfDaysInMonth(Year,i);
    }
    TotalDays+=Day;

    return TotalDays;
}
void DateForTotalDays(short TotalDays){
    short Year=0;
    short Month=0;
    short Day=0;
    for(short i = 1 ; i<=12 ; i++){

    }
}
stDate TotalDaysToDate(short Year,short TotalDays){
    
    stDate Date;
    Date.Year=Year;
    int TotalDaysInYear;
    short TotalDaysInMonth;

    for(short i = 1 ; i <=12 ; i ++ ){

        TotalDaysInMonth=NumberOfDaysInMonth(Year,i);

        if( TotalDaysInMonth < TotalDays) {
            TotalDays-=TotalDaysInMonth;
            continue;
        } 
        
        Date.Month=i;
        Date.Day=TotalDays;
        break;
    }

    return Date; 
}
int main(){

    system("clear");
    short Year=ReadYear();
    short Month=ReadMonth();
    short Day=ReadDay();
    short TotalDays=NumberOfDaysFormBeginingOfTheYear(Year,Month,Day);

    cout<<"Number Of Days since the begining of the year is : "<<TotalDays<<endl;

    stDate Date=TotalDaysToDate(Year,TotalDays);
    cout<<Date.Year<<"/"<<Date.Month<<"/"<<Date.Day<<endl;

    return 0;
}
