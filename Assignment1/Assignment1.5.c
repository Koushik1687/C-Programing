#include <stdio.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int calculateDays(struct Date date) {
    int days = 0;


    for (int y = 1; y < date.year; y++) {
        days += isLeapYear(y) ? 366 : 365;
    }


    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 0; m < date.month - 1; m++) {
        days += monthDays[m];
    }


    days += date.day;


    if (date.month > 2 && isLeapYear(date.year)) {
        days++;
    }

    return days;
}

int main() {
    struct Date birthDate;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);


    struct Date today;
    today.day = currentTime->tm_mday;
    today.month = currentTime->tm_mon + 1;
    today.year = currentTime->tm_year + 1900; 


    printf("Enter your birth day (1-31): ");
    scanf("%d", &birthDate.day);
    printf("Enter your birth month (1-12): ");
    scanf("%d", &birthDate.month);
    printf("Enter your birth year (e.g., 1990): ");
    scanf("%d", &birthDate.year);


    int totalDaysBirth = calculateDays(birthDate);
    int totalDaysToday = calculateDays(today);

    int ageInDays = totalDaysToday - totalDaysBirth;


    printf("Total days from birth date to today: %d days\n", ageInDays);

    return 0;
}