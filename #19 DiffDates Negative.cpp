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
void PrintYearCalender(short Year){

    printf("\n____________________________________\n\n");
    printf("%19s - %d\n", "Calendar", Year);
    printf("____________________________________\n\n");

    for(short i=1;i<=12;i++){
        PrintMonthCalender(Year,i);
        cout<<endl;
    }


}
short NumberOfDaysFormBeginingOfTheYear(short Year,short Month,short Day){
    
    short TotalDays=0;

    for(int i = 1; i<=Month-1;i++){
        TotalDays+=NumberOfDaysInMonth(Year,i);
    }
    TotalDays+=Day;

    return TotalDays;
}
stDate ReadFullDate(){

    stDate Date;

    Date.Year=ReadYear();
    Date.Month=ReadMonth();
    Date.Day=ReadDay();
    
    return Date;
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

stDate AddDaysToDate(stDate Date,short AddDays){
    
    short TotalDays=AddDays+NumberOfDaysFormBeginingOfTheYear(Date.Year,Date.Month,Date.Day);
    short MonthDay;

    Date.Month=1;
    
    while (true)
    {   
        MonthDay=NumberOfDaysInMonth(Date.Year,Date.Month);

        if(TotalDays>MonthDay)
        {
            TotalDays-=MonthDay;
            Date.Month++;

            if(Date.Month > 12 )
            {
                Date.Year++;
                Date.Month=1;
            }
        } else
        {
            Date.Day=TotalDays;
            break;
        }
    }
    
    return Date;
}
/*
stDate AddDaysToDate(stDate Date, short AddDays) {
    short TotalDays = NumberOfDaysFormBeginingOfTheYear(Date.Year, Date.Month, Date.Day) + AddDays;
    while (TotalDays > (IsLeepYear(Date.Year) ? 366 : 365)) {
        TotalDays -= (IsLeepYear(Date.Year) ? 366 : 365);
        Date.Year++;
    }

    return TotalDaysToDate(Date.Year, TotalDays);
}*/ //22 23 10 12
bool IsDate1BeforDate2(stDate Date1,stDate Date2){

    if(Date1.Year != Date2.Year) 
        return Date1.Year < Date2.Year;
    
    if(Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month ;

    return Date1.Day < Date2.Day ;
}
bool IsDate1EqualToDate2(stDate Date1,stDate Date2){

    return ( (Date1.Year==Date2.Year) && (Date1.Month==Date2.Month) && (Date1.Day==Date2.Day) );
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
stDate IncuresDateByOneDay(stDate Date){

    if(IsLastDayInMonth(Date)){

        if(IsLastMonthInYear(Date.Month)){
            
            Date.Year++;
            Date.Month=1;
            Date.Day=1;

            return Date;

        } else {

            Date.Day=1;
            Date.Month++;
            return Date;
        }   

        return Date;
    }

    Date.Day++;

    return Date;
    
}
void SwapDate(stDate &Date1 , stDate &Date2){
    stDate TempDate;

    TempDate=Date1;
    Date1=Date2;
    Date2=TempDate;

}
int GetDifferenceInDays(stDate Date1,stDate Date2 , bool InculdEndDay=false){

    int Days=0;
    int SwapFlagVal=1;

    if(!IsDate1BeforDate2(Date1,Date2)){
        SwapDate(Date1,Date2);
        SwapFlagVal=-1;
    }

    while (IsDate1BeforDate2(Date1,Date2))
    {
        Days++;
        Date1=IncuresDateByOneDay(Date1);
    }

    return (InculdEndDay) ? ++Days * SwapFlagVal : Days *SwapFlagVal ;
    
}
int main(){

    system("clear");

    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    cout << "\nDiffrence is: "<< GetDifferenceInDays(Date1, Date2) << " Day(s).";
    cout << "\nDiffrence (Including End Day) is: "<< GetDifferenceInDays(Date1, Date2, true) << " Day(s).";
    return 0;
}
