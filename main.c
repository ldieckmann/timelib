#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "timelib.h"
//include new library in order to use the function in it

/*
author: Louis Dieckmann
This program calculate the day in a year in order to calculate the user hast to give a year, month and day.
If the date is in the border it will give back the day no. of the date
*/

int main()
{
    int dayOfYear;
    int year = 0;
    int month = 0;
    int day = 0;

    input_date(&year, &month, &day);

    dayOfYear = day_of_the_year(year, month, day);

    printf("No. of day: %i",dayOfYear);
    return 0;
}
