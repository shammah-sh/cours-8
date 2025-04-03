bool IsDate1BeforDate2(stDate Date1,stDate Date2){

    if(Date1.Year != Date2.Year) 
        return Date1.Year < Date2.Year;
    
    if(Date1.Month != Date2.Month)
        return Date1.Month < Date2.Month ;

    return Date1.Day < Date2.Day ;
}
