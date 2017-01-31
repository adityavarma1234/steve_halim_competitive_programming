#include<bits/stdc++.h>
using namespace std;
int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool leapyear(int a)
{
    if(a%4==0 && a%100!=0)
        return true;
    if(a%400==0)
        return true;
    return false;
}
function g()
int main()
{
    int day,month,year,predict_days,aday, amonth,ayear;
    while(1)
    {
        scanf("%d %d %d %d", &predict_days, &day, &month, &year);
        if(predict_days == 0 && day == 0 && month ==0  && year == 0)
            break;
        aday = day;
        amonth = month;
        ayear = year;
    }
    return 0;
}
