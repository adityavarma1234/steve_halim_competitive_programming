#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long double h, u, d, f;
    while(1)
    {
        cin >> h >> u >> d >> f;
        if(h==0) break;
        long double distance,fatigue,distanceclimbed;
        distance = 0;
        int days = 0;
        distanceclimbed = u;
        fatigue = u*f/100;
        long double distance_day=0, distance_night=0;
        while(distance <= h &&  distance >= 0)
        {
//            distance_day = distance + (u - days*fatigue);
            distanceclimbed = distanceclimbed - fatigue*distanceclimbed;
            distance_day = distance + distanceclimbed;
            days++;
            distance = distance_day;
            if(distance > h )
            {
                break;
            }
            distance_night = distance - d ;
            distance = distance_night;
            if(distance < 0)
            {
                break;
            }
        }
        if(distance >= h) cout << "success on day "<< days << endl;
        else cout << "failure on day " << days << endl;
    }
}
