#include <bits/stdc++.h>
using namespace std;

string toMonth(string month)
{
    if (month == "Jan")
        return "01";
    else if (month == "Feb")
        return "02";
    else if (month == "Mar")
        return "03";
    else if (month == "Apr")
        return "04";
    else if (month == "May")
        return "05";
    else if (month == "Jun")
        return "06";
    else if (month == "Jul")
        return "07";
    else if (month == "Aug")
        return "08";
    else if (month == "Sep")
        return "09";
    else if (month == "Oct")
        return "10";
    else if (month == "Nov")
        return "11";
    else
        return "12";
}

string substr(string date, int beg, int size)
{
    string res;
    int i = beg;
    while (size--)
    {
        res += date[i];
        i++;
    }
    return res;
}

string reformatDate(string d)
{
    string res;
    string DD, MM, YYYY;

    if (d.length() == 13)
    {
        DD = substr(d, 0, 2);
        MM = toMonth(substr(d, 5, 3));
        YYYY = substr(d, 9, 4);
        res = YYYY + "-" + MM + "-" + DD;
    }

    else if (d.length() == 12)
    {
        DD = substr(d, 0, 1);
        MM = toMonth(substr(d, 4, 3));
        YYYY = substr(d, 8, 4);
        res = YYYY + "-" + MM + "-" + "0" + DD;
    }

    return res;
}

int main()
{
    string date;
    cout << "Enter date : ";
    cin >> date;

    cout << "Formatted date is : ";
    string res = reformatDate(date);

    cout << res;
    return 0;
}