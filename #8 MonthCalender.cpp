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
short CalcaluatDayOrder(short Year,short Month,short Day){
    short a =(14-Month)/12.0;
    short y=Year-a;
    short m=Month+(12*a)-2;

    return (( Day + y + (y/4) - (y/100) + (y/400) + ( (31*m)/12 )) % 7);
}
string DayName(short DayOrder){
    string arrDayNames[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    return arrDayNames[DayOrder];
}
string MonthShortName(short MonthNumber){

    string Months[12] = { "Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"
        };
        return (Months[MonthNumber - 1]);
}
void PrintMonthCalender(short Year,short Month){

    int NumberOfDays=NumberOfDaysInMonth(Year,Month);
    int Current=CalcaluatDayOrder(Year,Month,1);

    printf("________________%s________________\n\n",MonthShortName(Month).c_str());
    cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    int i ;
    for(i=0;i<Current;i++){
        printf("     ");
    }   
    for(short j=1;j<=NumberOfDays;j++){
        
        printf("%5d",j);
        if(++i==7){
            i=0;
            printf("\n");
        }
    }   
    printf("\n________________________________________\n");
}
int main(){
    short Year=ReadYear();
    short Month=ReadMonth();
    PrintMonthCalender(Year,Month);

    return 0;
}
//January, February, March, April, May, June, July, August, September, October, November, and December.
