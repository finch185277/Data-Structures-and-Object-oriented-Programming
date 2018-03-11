#include <bits/stdc++.h>
using namespace std;

class Date
{
public:
Date(int, int, int);
~Date();

/*Get function for accessing private member*/
int getDay();
int getMonth();
int getYear();

/*Set function for updating private member*/
void setDay(int set_day);
void setMonth(int set_month);
void setYear(int set_year);

/*A Function that returns the date after a given date
    For e.g-

    today is 8/3/2018 (Day/Month/Year)
    DateAfter(3) should return a date of 11/3/2018 */
Date DateAfter(int set_day);

/*A Function that returns the date after a given date
    For e.g-

    today is 8/3/2018 (Day/Month/Year)
    DateBefore(3) should return a date of 5/3/2018 */
Date DateBefore(int set_day);

/*A Function that returns the day of a date
    For e.g-

    if the date is 8/3/2018, then the day() function
    should return "Thursday"
 */
string dayName();
string monthName();

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
int numberOfDays(int);

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
void printMonthCalendar();

int isLeapYear(int set_year);
int getWeekday();

private:
/*Current Date*/
int day;
int month;
int year;

};

//==============================================================================
//==============================================================================
//==============================================================================

Date::Date(int m, int d, int y){
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
        day = (set_day > 0 && set_day <= numberOfDays(month)) ? set_day : 1;
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
        while(copy_day>numberOfDays(copy_month)) {
                copy_day-=numberOfDays(copy_month);
                copy_month++;
                if(copy_month>12) {
                        copy_year+=copy_month/12;
                        copy_month%=12;
                }
        }
        return Date(copy_month, copy_day, copy_year);
}

/*A Function that returns the date after a given date
    For e.g-

    today is 8/3/2018 (Day/Month/Year)
    DateBefore(3) should return a date of 5/3/2018 */
Date Date::DateBefore(int days) {
        int copy_year=year, copy_month=month, copy_day=day-days;
        while(copy_day <= 0) {
                copy_day+=numberOfDays(copy_month-1);
                copy_month--;
                if(copy_month<=0) {
                        copy_year--;
                        copy_month+=12;
                }
        }
        return Date(copy_month, copy_day, copy_year);
}

/*A Function that returns the day of a date
    For e.g-

    if the date is 8/3/2018, then the day() function
    should return "Thursday"
 */
string Date::dayName() {
        int d = 0;
        string weekdays[] = {"Sunday", "Monday",
                             "Tuesday",
                             "Wednesday",
                             "Thursday",
                             "Friday",
                             "Saturday",};
        //如果是閏年，2月就多加1天變成29天
        d = getWeekday();
        return weekdays[d];
}
string Date::monthName() {
        int m;
        string weekdays[] = {"0",
                             "January", "February", "March", "April",
                             "May", "June", "July", "August",
                             "September", "October", "November", "December"};
        //如果是閏年，2月就多加1天變成29天
        m = getMonth();
        return weekdays[m];
}
int Date::getWeekday() {
        int offset = 0;
        //12個月各月的天數
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //如果是閏年，2月就多加1天變成29天
        days[2] += isLeapYear(year);
        //計算這一天是一年中的第幾天
        int d, i;
        d = day;
        for (i=0; i<month; i++) {
                d += days[i];
        }
        //根據公式去計算這一天是星期幾
        int tmp_year = year-1;
        d += tmp_year + (tmp_year/4) - (tmp_year/100) + (tmp_year/400);
        d += offset + 7; //此處+7是避免d算出來是負值的情況
        d %= 7; //算出星期幾
        return d;
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
int Date::numberOfDays(int m) {
        //12個月各月的天數
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //如果是閏年，2月就多加1天變成29天
        days[2] += isLeapYear(year);
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
        //開始印出月歷
        int i, count;
        cout << "--------------" << monthName() << "--------------\n";
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        //印出第一週的空白
        for (i=0; i<weekday; i++) {
                printf("%5s", " ");
        }
        //印出每一天
        for (i=1, count=weekday+1; i<=numberOfDays(month); i++, count++) {
                printf("%5d", i);
                //處理換行
                if (count % 7 == 0) {
                        printf("\n");
                }
        }
        //如果最後一天是星期六就不要再多印換行，以保持輸出的資料沒有多餘的空行
        if ((count-1) %7 != 0) {
                printf("\n");
        }
}

int Date::isLeapYear(int years) {
        return (year%400==0) || ((year%4==0) && (year%100!=0));
}
