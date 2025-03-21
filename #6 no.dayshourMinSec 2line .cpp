short NumberOfDaysInAMonth(short Month, short Year)
{
  if (Month < 1 || Month>12)
  return 0;
  int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
  return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
