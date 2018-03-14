#include <bits/stdc++.h>
#include "0616214_Date.h"
using namespace std;

// Driver Program to check your implementation
int main()
{
        Date date1(8, 3, 2018);
        Date date2 = date1.DateAfter(13);
        Date date3 = date1.DateBefore(25);

        date1.setDay(25);
        date2.setMonth(12);
        date3.setYear(2015);

        /*****test*****/
        // cout << "d1: " << date1.getYear() << "/" << date1.getMonth() << "/"
        //      << date1.getDay() <<endl;
        // cout << "d2: " << date2.getYear() << "/" << date2.getMonth() << "/"
        //      << date2.getDay() <<endl;
        // cout << "d3: " << date3.getYear() << "/" << date3.getMonth() << "/"
        //      << date3.getDay() <<endl;
        // date2.printMonthCalendar(); // test
        // cout << date2.day() << endl;
        // cout << "hello" << "\n";
        // cout << date3.getDay() << "\n";

        cout << date1.numberOfDays() << endl;
        cout << date2.dayOfWeek() << "\n";
        date3.printMonthCalendar();

        return 0;
}
