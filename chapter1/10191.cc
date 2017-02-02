#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,cnt = 0;
    while(cin >> t)
    {
        cnt++;
        int max_h = 10, max_m = 0, max_t_h = 0, max_t_m = 0,prev_h=0,prev_m=0, max_t_h_m = 0,tmp_t_h_m=0,a,b,c,d;
        while(t--)
        {
            string str;
            scanf("%d:%d %d:%d",&a, &b, &c, &d);
            getline(cin, str);
            if(prev_h == 0)
            {
                max_t_h = a - max_h;
                max_t_m = b - max_m + 60;
                tmp_t_h_m = max_t_h * 60 + max_t_m%60;
                prev_h = c;
                prev_m = d;
                if(tmp_t_h_m > max_t_h_m)
                {
                    max_h = 10;
                    max_m = 0;
                    max_t_h_m = tmp_t_h_m;
                }
            }
            else
            {
                max_t_h = a - prev_h;
                max_t_m = b - prev_m+60;
                tmp_t_h_m = max_t_h * 60 + max_t_m%60;
                if(tmp_t_h_m > max_t_h_m)
                {
                    max_h = prev_h;
                    max_m = prev_m;
                    max_t_h_m = tmp_t_h_m;
                }
                prev_h = c;
                prev_m = d;
            }
            cout << a << ":" << b << " " << c << ":" << d << endl;
            cout << prev_h << ":" << prev_m << " " << tmp_t_h_m << " curr diff " << max_t_h_m << " highest diff " << endl;
            cout << max_h<<":" << max_m << endl;
        }
        max_t_h = 18 - prev_h;
        max_t_m = 0 - prev_m + 60;
        tmp_t_h_m = max_t_h * 60 + max_t_m%60;
        prev_h = c;
        prev_m = d;
        if(tmp_t_h_m > max_t_h_m)
        {
            max_h = prev_h;
            max_m = prev_m;
        }
        cout << prev_h << ":" << prev_m << " " << tmp_t_h_m << " curr diff " << max_t_h_m << " highest diff " << endl;
        cout << max_h<<":" << max_m << endl;
        printf("Day #%d: the longest nap starts at %d:%.2d and will last for %d minutes\n",cnt, max_h,max_m, max_t_m);
    }
    return 0;
}
