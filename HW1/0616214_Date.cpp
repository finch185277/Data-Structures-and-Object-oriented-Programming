#include <bits/stdc++.h>
#include "0616214_Date.h"
using namespace std;

//==============================================================================
//========================= implementation ==============================
//==============================================================================

Date::Date(int d, int m, int y){
        setMonth(m);
        setDay(d);
        setYear(y);
}

Date::~Date(){
}

int Date::getMonth() {
        return month;
}
int Date::getDay() {
        return day;
}
int Date::getYear() {
        return year;
}

/*Set function for updating private member*/
void Date::setDay(int set_day) {
        day = (set_day > 0 && set_day <= numberOfDays()) ? set_day : 1;
}
void Date::setMonth(int set_month) {
        month = (set_month >= 1 && set_month <= 12) ? set_month : 1;
}
void Date::setYear(int set_year) {
        year = (set_year >= 1) ? set_year : 1;
}

/*A Function that returns the date after a given date
    For e.g-

    today is 8/3/2018 (Day/Month/Year)
    DateAfter(3) should return a date of 11/3/2018 */
Date Date::DateAfter(int days) {
        int copy_year=year, copy_month=month, copy_day=day+days;
        Date temp1(copy_day, copy_month, copy_year);
        while(copy_day>temp1.numberOfDays()) {
                copy_day-=temp1.numberOfDays();
                copy_month++;
                if(copy_month>12) {
                        temp1.setYear(copy_year+=copy_month/12);
                        temp1.setMonth(copy_month%=12);
                } else {
                        temp1.setMonth(copy_month);
                }
        }
        temp1.setDay(copy_day);
        return temp1;
}

/*A Function that returns the date after a given date
    For e.g-

    today is 8/3/2018 (Day/Month/Year)
    DateBefore(3) should return a date of 5/3/2018 */
Date Date::DateBefore(int days) {
        int copy_year = year, copy_month = month, copy_day = day - days;
        // cout << month <<day << year<<endl;
        // cout << "before1"<<copy_month<< copy_day<< copy_year<<"\n";
        Date temp2(copy_day, copy_month, copy_year);
        while(copy_day <= 0) {
                copy_month--;
                if(copy_month<=0) {
                        temp2.setYear(copy_year--);
                        copy_month+=12;
                }
                temp2.setMonth(copy_month);
                copy_day += temp2.numberOfDays();
        }
        // cout << "before2"<<copy_month<< copy_day<< copy_year<<"\n";

        // setMonth(copy_month);
        temp2.setDay(copy_day);
        return temp2;
}

/*A Function that returns the day of a date
    For e.g-

    if the date is 8/3/2018, then the day() function
    should return "Thursday"
 */
string Date::dayOfWeek() {
        int d = 0;
        string weekdays[] = {"Sunday", "Monday",
                             "Tuesday",
                             "Wednesday",
                             "Thursday",
                             "Friday",
                             "Saturday",};
        d = getWeekday();
        return weekdays[d];
}
string Date::monthName() {
        int m;
        string months[] = {"0",
                           "January", "February", "March", "April",
                           "May", "June", "July", "August",
                           "September", "October", "November", "December"};
        m = getMonth();
        return months[m];
}
int Date::getWeekday() {
        //days
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //add 1
        days[2] += isLeapYear(year);
        //count the # of whole year
        int week_num, i;
        week_num = day;
        for (i=0; i<month; i++) {
                week_num += days[i];
        }
        //count week #
        int tmp_year = year-1;
        week_num += tmp_year + (tmp_year/4) - (tmp_year/100) + (tmp_year/400);
        week_num = (week_num+7)%7; //count week #
        return week_num;
}

/* A Function to return the number of days in
    Current Month.

    Month Number     Name        Number of Days
    0                January     31
    1                February    28 (non-leap) / 29 (leap)
    2                March       31
    3                April       30
    4                May         31
    5                June        30
    6                July        31
    7                August      31
    8                September   30
    9                October     31
    10               November    30
    11               December    31*/
int Date::numberOfDays() {
        int m;
        //the days of each month
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //add 1
        days[2] += isLeapYear(year);
        m = getMonth();
        return days[m];
}

/* Function to print a calendar of the current month.
   Just like what you see on a calendar. An example is like

   --------------March--------------
   Sun  Mon  Tue  Wed  Thu  Fri  Sat
                    1    2    3
   4    5    6    7    8    9   10
   11   12   13   14   15   16   17
   18   19   20   21   22   23   24
   25   26   27   28   29   30   31

 */
void Date::printMonthCalendar() {
        int weekday = (getWeekday() - (day % 7) + 7 +1) % 7;
        //begin print
        int i, count;
        cout << "--------------" << monthName() << "--------------\n";
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        //the #1 week blank
        for (i=0; i<weekday; i++) {
                printf("%5s", " ");
        }
        //each day
        for (i=1, count=weekday+1; i<=numberOfDays(); i++, count++) {
                printf("%5d", i);
                //\n
                if (count % 7 == 0) {
                        printf("\n");
                }
        }
        //if the lastest day is sat., then \n.
        if ((count-1) %7 != 0) {
                printf("\n");
        }
}

int Date::isLeapYear(int years) {
        return (year%400==0) || ((year%4==0) && (year%100!=0));
}
