#include "timelib.h"

//This function returns 1 if the year is a leapyear, if the year is not a leapjear then it returns 0
//if year is out of border then -1 is returend
//The initparameter is a year in form of an integer and retuns an integer
int is_leapyear(int year)
{   //check if out of border
    if(year<1582 ||year>2400)
    {
        return -1;
    }
    //checks is leapyear
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

//This function tests if the month exists and returns the max possible day
//The initparameter is a year and month in form of an integer and retuns an integer
int get_days_for_month(int year,int month)
{
    if(month < 1 || month > 12)
    {
        return -1;
    }
    else
    {
        if(is_leapyear(year) == 1)
        {   //days possible in a leapyear
            int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
            return days[month - 1];;
        }
        else
        {   //days possible in a leapyear
            int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
            return days[month - 1];
        }
    }
}

//this function checks if the day exists and if the year ist in border
//The initparameter is a year, month and day in form of an integer and retuns an integer
int exist_date(int year, int month,int day)
{
    if (day <= 0 || day > get_days_for_month(year, month) || year < 1582|| year > 2400)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//this function calculates the dayOfYear
//The initparameter is a year, month and day in form of an integer and retuns an integer
int day_of_the_year(int year, int month, int day)
{   //tests if the date exists
    if (exist_date(year,month,day) == 1)
    {
        int i;
        int TotalAmountDays = 0;

        for(i=1; i<month; i++)
        {   //adds up the day for each full month
            TotalAmountDays += get_days_for_month(year, i);
        }
        //adds the days in the present month
        TotalAmountDays += day;
        return TotalAmountDays;

    }
}

//this function get and test the date given by the user
//The initparameter is a year, month and day in form of an integer and retuns an integer
void input_date(int *yearPointer, int *monthPointer, int *dayPointer){
    do{
    printf("Day:");
    scanf("%i", &*dayPointer);
    printf("Month:");
    scanf("%i", &*monthPointer);
    printf("Year:");
    scanf("%i", &*yearPointer);
    }while(exist_date(*yearPointer, *monthPointer, *dayPointer) == 0);

}

