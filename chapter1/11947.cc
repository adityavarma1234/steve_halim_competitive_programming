#include <bits/stdc++.h>
using namespace std;
void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;
    *date = *localtime( &date_seconds ) ; ;
}
string findsign(int day, int month)
{
    if(month == 1)
    {
        if(day <21)
            return "capricorn";
        return "aquarius";
    }
    if(month==2)
    {
        if(day <= 19)
            return "aquarius";
        return "pisces";
    }
    if(month == 3)
    {
        if(day <= 20)
            return "pisces";
        return "aries";
    }
    if(month == 4)
    {
        if(day <= 20)
            return "aries";
        return "taurus";
    }
    if(month == 5)
    {
        if(day <= 21)
            return "taurus";
        return "gemini";
    }
    if(month == 6)
    {
        if(day <= 21)
            return "gemini";
        return "cancer";
    }
    if(month == 7)
    {
        if(day <= 22)
            return "cancer";
        return "leo";
    }
    if(month == 8)
    {
        if(day <= 21)
            return "leo";
        return "virgo";
    }
    if(month == 9)
    {
        if(day <= 23)
            return "virgo";
        return "libra";
    }
    if(month == 10)
    {
        if(day <= 23)
            return "libra";
        return "scorpio";
    }
    if(month == 11)
    {
        if(day <= 22)
            return "scorpio";
        return "sagittarius";
    }
    if(day <= 22)
        return "sagittarius";
    return "capricorn";
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cnt = 1;
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        struct tm date = { 0, 0, 12 } ;
        int year  ;
        int month ;
        int day,d ;
        scanf("%2d%2d%4d",&month, &day, &year);
//        cout << day << " " << month << " " << year << endl;
        date.tm_year = year -1900 ;
        date.tm_mon = month -1;
        date.tm_mday = day ;
        d = 280;
        DatePlusDays( &date, d ) ;
        month = date.tm_mon + 1;
        day = date.tm_mday;
        year = date.tm_year + 1900 ;
//        cout << cnt << " " << month << "/"<< day << "/" << date.tm_year + 1900 << " " << findsign(day, month) << endl;
        printf("%d %.2d/%.2d/%d %s\n", cnt, month, day, year, findsign(day, month).c_str());
        cnt++;
    }

}

