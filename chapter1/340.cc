#include<bits/stdc++.h>

using namespace std;
int sec[10], gue[10], secd[1000], gued[1000], tmpsec[10];


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n=1,cnt=0;
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        cnt++;
        for(int i=0; i<10; i++) {
            tmpsec[i] = gue[i] = sec[i] = 0;
        }
        for(int i=0; i<n; i++)
        {
            cin>> secd[i];
            sec[secd[i]]++;
            tmpsec[secd[i]]++;
        }
        cout << "Game " << cnt << ":" << endl;
        while(1)
        {
            for(int i=0; i<10; i++)
            {
                gue[i] = 0;
                tmpsec[i] = sec[i];
            }
            for(int i=0; i<n; i++)
            {
                cin >> gued[i];
                gue[gued[i]]++;
            }
            bool f=true;
            for(int i=1; i<10; i++)
            {
                if(gue[i] != 0)
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                break;
            }
            int strong = 0, weak = 0;
            for(int i=0; i<n; i++)
            {
                if(secd[i] == gued[i])
                {
                    strong++;
                    gue[gued[i]]--;
                    tmpsec[secd[i]]--;
                }
            }
            for(int i=1; i<10; i++)
            {
                if(tmpsec[i])
                {
                    weak += min(tmpsec[i], gue[i]);
                }
            }
            printf("    (%d,%d)\n",strong, weak);
        }
    }
    return 0;
}
