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
