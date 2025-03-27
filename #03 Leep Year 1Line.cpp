bool IsLeepYear(int Year){
    return ( (Year%4==0 && Year%100 != 0) || ( Year%400==0 ) );
}
