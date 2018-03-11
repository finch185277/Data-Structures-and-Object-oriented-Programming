#include <bits/stdc++.h>
#include "Date.h"
using namespace std;

// Driver Program to check your implementation
int main()
{
        Date date1(3, 8, 2018);
        Date date2 = date1.DateAfter(13);
        Date date3 = date1.DateBefore(25);

        date1.setDay(25);
        date2.setMonth(12);
        date3.setYear(2015);

        /*****test*****/
        // cout << date2.getYear() << "/" << date2.getMonth() << "/"
        //      << date2.getDay() <<endl;
        // cout << date3.getYear() << "/" << date3.getMonth() << "/"
        //      << date3.getDay() <<endl;
        // date2.printMonthCalendar(); // test
        // cout << date2.day() << endl;
        // cout << "hello" << "\n";

        cout << date1.numberOfDays(date1.getMonth()) << endl;
        cout << date2.dayName() << "\n";
        date3.printMonthCalendar();
        // cout << "\n" <<date3.getDay();

        return 0;
}
