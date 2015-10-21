#include <stdio.h>
/* definition of variables at the top */




int main (void) {
    /* this is the year that is inputed */
    int year;
    /* this is to check whether the input has reached an end */
    int end;
    /* this is the day that calculate easter date returns */
    int day;
    /* this is the function prototype for calculate_easter date */
    int calculate_Easter_date (int year);
    while(1) {
        end = scanf("%d", &year);
        if (end == EOF) {
            break;
        }
        if ((year > 1581) && (year < 39999)) {
            day = calculate_Easter_date(year);
            if (day > 0) {
                printf("%d - April %d\n", year, day);
            }
            else {
                day = (-1) * day;
                printf("%d - March %d\n", year, day); 
            }
        } 
        else {
            fprintf(stderr, "year out of range");
        }
        
    }
    return 0;
}

        /* takes in the year given from the input file, then declares a 
uses the metonic cycle to definea golden year was.
it then defines the century it is and the amount of skipped leap years
from that century. then there is a correctionFactor to account for the
fact that the moon doesn't orbit earth exactly 235 times in 19 years.
Then the function defines how many days the moon has been since it was
a new moon. CalendarFullMoon first is defined by when the fullMoon will
happen, and then is set to the first Sunday after the fullMoon. It then
is used to determine whether this date falls before or after march, by 
looking at whether it is greater than 31. Then the character date is used
to format as a string the exact date that easter will occur on based
on what month and day the sunday after the full moon is. The date is then
returned.
*/
int calculate_Easter_date (int year) {
    /* the goldenYear is equal to the year 19 mod + 1 because thats how long 
    the metonic cycle takes (19 years) */

    int goldenYear;
    
    /* this is the century that the year is in usefull for counting skipped
    leap years. it is equal to the year divided by 100. (no remainder) */

    int century;
    
    /* this is the amount of skipped leap years, which happens 3/4 times per 
    century ever since the 15th century. */
    
    int skippedLeapyears;
    
    /* this is the correction factor to account for the fact that the moon 
    doesn't orbit exactly 235 times in 19 years. so we hace to multiply
    the century were in times 8 and add 5 to it and divide by 25. 
    and then subtract 5 to account for this error. similar to that
    of skippedLeapYears as a correction factor */ 
    
    int correctionFactor;

    /* this calculates a day that mod 7 + 7 is on a sunday. */

    int sunday;

    /* this is the epact which is when the new moon occured relative to
    january 1st, the first day of year. originally the epact was 
    calculated by just using the leap year every four years but then life got
    more complicated, and so the epact is calculated to be 11 times the 
    golden year +20 + correction factor minus the amount of skipped leap 
    years. and dividing it by 30 to get how many days from january first 
    the epact occured */
    
    int epact;

    /* calendarFullMoon is used to calculate when in march or April the
    first sunday after a full moon has occured. originally it is set
    to 44 - epact which is when the first full moon occurs. but then 
    it is changed to the sunday after the first full moon occurs which
    is given by adding 7 to itself and subtracting 
    the reaminder of sunday added to itself */

    int calendarFullMoon;

    /* int date is the date that is returned by the function, if it is
    in April the date will be the positive value of calendar full moon
    and if it is in March it will be the negative value of the first
    calendar full moon */



    int date;
    goldenYear = (year % 19) + 1;
    century = (year / 100) + 1;
    skippedLeapyears = (3 * century) / 4 - 12;
    correctionFactor = ((8 * century + 5) / 25) - 5;
    sunday = ((5 * year) / 4) - skippedLeapyears - 10;
    epact = (11 * goldenYear + 20 + correctionFactor - skippedLeapyears) % 30;
    if ((epact > 25 && goldenYear > 11) || epact == 24) {
        epact += 1;
    }
    calendarFullMoon = 44 - epact;
    if (calendarFullMoon < 21) {
        calendarFullMoon += 30;
    }
    calendarFullMoon = calendarFullMoon + 7 - (sunday + calendarFullMoon) % 7;
    if (calendarFullMoon > 31) {
        date = calendarFullMoon - 31;
    }
    else if (calendarFullMoon < 31) {
        date = (-1) * calendarFullMoon;
    }
    return date;
}