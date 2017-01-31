#include <bits/stdc++.h>
using namespace std;
void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ; ;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(1)
    {
        struct tm date = { 0, 0, 12 } ;  // nominal time midday (arbitrary).
        int year = 2999 ;
        int month = 12 ;  // February
        int day = 31,d ;   // 26th
        scanf("%d %d %d %d",&d, &day, &month, &year);
        if(d==0 && day==0 && month==0 && year==0)break;
        // Set up the date structure
        date.tm_year = year -1900 ;
        date.tm_mon = month -1;  // note: zero indexed
        date.tm_mday = day ;       // note: not zero indexed

        // Date, less 100 days
        DatePlusDays( &date, d ) ;


        // Show time/date using default formatting
//        std::cout << asctime( &date ) << std::endl ;
        cout << date.tm_mday << " "<< date.tm_mon+1 << " " << date.tm_year + 1900 << endl;
    }

}
