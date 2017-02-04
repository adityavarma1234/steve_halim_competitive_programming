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
        long double fatigue,distanceclimbed,heightafterclimbing,heightaftersliding,initialheight;
        int days = 0;
        distanceclimbed = 0;
        fatigue = u*f/(long double)100;
        initialheight =0;
        heightafterclimbing = 0;
        while(heightafterclimbing <= h &&  heightafterclimbing >= 0)
        {
            distanceclimbed = u - fatigue*days;
            days++;
            if(distanceclimbed > 0)
            heightafterclimbing = initialheight + distanceclimbed;
            else heightafterclimbing = initialheight;
//            if(heightafterclimbing > h || heightafterclimbing < 0)
//            {
//                break;
//            }
            heightaftersliding  = heightafterclimbing - d ;
//            cout << "day " << days << " initial height " << initialheight << " distance climbed " << distanceclimbed << " height after climbing " << heightafterclimbing << " height after lsidin " << heightaftersliding << endl;
            initialheight = heightaftersliding;
            if(initialheight < 0)
            {
                initialheight = 0;
                break;
            }
        }
        if(heightafterclimbing > h) cout << "success on day "<< days << endl;
        else cout << "failure on day " << days << endl;
    }
}
