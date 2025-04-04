bool IsDate1EqualDate2(stDate Date1,stDate Date2){
  if(Date1.Year!=Date2.Year)
    return false;
  if(Date1.Month!=Date2.Month)
    return false;
  
return Date1.Day==Date2.Day;
}
// return ( (Date1.Year==Date2.Year) && (Date1.Month==Date2.Month) && (Date1.Day==Date2.Day) );
// (Date1.Year==Date2.Year) ? ( (Date1.Month==Date2.Month) ? ((Date1.Day==Date2.Day) ? ture : false ) : false ) : false 
