int GetDifferenceInDays(stDate Date1,stDate Date2 , bool InculdEndDay=false){
    int Days=0;

    while (IsDate1BeforDate2(Date1,Date2))
    {
        Days++;
        Date1=IncuresDateByOneDay(Date1);
    }

    return (InculdEndDay) ? ++Days : Days ;
    
}
