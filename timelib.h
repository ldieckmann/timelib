#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

int is_leapyear(int year);
int get_days_for_month(int year, int month);
int day_of_the_year(int year, int month, int day);
int exist_date(int year, int month, int day);
void input_date(int *yearPointer, int *monthPointer, int *dayPointer);

#endif // TIMELIB_H_INCLUDED
