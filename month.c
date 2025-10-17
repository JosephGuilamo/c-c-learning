/*
    Write enumerated types that supports dates—such as december 12. 
    Then add a function that produces a next day.  So nextday(date) of december 12 is december 13. 
    Also write a function printdate(date) that prints a date legibly.
    The function can assume that February has 28 days and it most know how many days are in each month. 
    Use a struct with two members; one is the month and the second  is the day of the month—an int (or short).

    Author: Jose Miguel Garcia
    Date: 2025/10/17
*/

#include <stdio.h>

typedef enum month{january = 1, february, march, april,may,june,july,august,september,october,november,december} month;
typedef struct date{ month m; int day;} date; 

int get_days_in_month(int d){
    switch (d)
    {
    case 1:  return 31; break;
    case 2:  return 28; break;
    case 3:  return 31; break;
    case 4:  return 30; break;
    case 5:  return 31; break;
    case 6:  return 30; break;
    case 7:  return 31; break;
    case 8:  return 31; break;
    case 9:  return 30 ;break;
    case 10: return 31; break;
    case 11: return 30; break;
    case 12: return 31; break;
    default: return 0;  break;
    }
}

char *get_month(int m){
    switch (m)
    {
    case 1:  return "January";  break;
    case 2:  return "February"; break;
    case 3:  return "March";    break;
    case 4:  return "April";    break;
    case 5:  return "May";      break;
    case 6:  return "June";     break;
    case 7:  return "July";     break;
    case 8:  return "August";   break;
    case 9:  return "September";break;
    case 10: return "October";  break;
    case 11: return "November"; break;
    case 12: return "December"; break;
    default: return "Unknown";   break;
    }
}

int increment_day(date *d){
    int days_in_month = get_days_in_month(d->m);

    if (d->day == days_in_month) {  
        if(d->m != 12){
             d-> day = 1; 
             d-> m += 1;
        } else {
             d-> day = 1; 
             d->m = 1;
        }
    } else {
        return d->day += 1;
    } 
       
}

void printdate(date *date){
   printf("the month is: %s\n", get_month(date->m));
   printf("the day is: %d\n", date->day); 
}

int main(void) {
    date test_date_1 = {july,1};
    date *ptr_test_date_1 = &test_date_1;
    increment_day(ptr_test_date_1);
    printdate(ptr_test_date_1);
    date test_date_2 = {february,28};
    date *ptr_test_date_2 = &test_date_2;
    increment_day(ptr_test_date_2);
    printdate(ptr_test_date_2);
     date test_date_3 = {december,31};
    date *ptr_test_date_3 = &test_date_3;
    increment_day(ptr_test_date_3);
    printdate(ptr_test_date_3);
    return 0;
}