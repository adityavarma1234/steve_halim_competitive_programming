#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int princess[3], prince[2];
    int gpr[3], gp[2];
    while(1)
    {
        bool eof = false;
        for(int i=0; i<3; i++)
        {
            cin >> princess[i];
            gpr[i] = 0;
            if(princess[i] == 0)
            {
                eof = true;
                break;
            }
        }
        for(int i=0; i<2; i++)
        {
            cin >> prince[i];
            gp[i] = 0;
        }
        if(eof)
            break;
        sort(prince, prince+2);
        sort(princess, princess+3);
        int cnt = 0;
        for(int i=0; i<2; i++)
        {
            for(int j=2; j>=0; j--)
            {
                if(prince[i] < princess[j] && gpr[j] == 0)
                {
                    gpr[j] = 1;
                    gp[i] = 1;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == 2)
        {
            cout << -1 << endl;
        }
        else if(cnt == 0)
        {
            int res = 1;
            while(1)
            {
                bool f = true;
                for(int i=0; i<3; i++) if(princess[i] == res)
                    {
                        f=false;
                        break;
                    }
                for(int i=0; i<2; i++) if(prince[i] == res)
                    {
                        f = false;
                        break;
                    }
                if(f) break;
            }
            cout << res << endl;
        }
        else
        {
            int res = princess[2];
            for(int i=2; i>=0; i--)
            {
                if(gpr[i] == 0)
                {
                    res = princess[i] + 1;
                    break;
                }
            }
            while(1)
            {
                bool f = true;
                for(int i=0; i<3; i++)
                {
                    if(princess[i] == res)
                    {
                        f=false;
                        break;
                    }
                }
                for(int i=0; i<2; i++)
                {
                    if(prince[i] == res)
                    {
                        f = false;
                        break;
                    }
                }
                if(f) break;
            }
            cout << res << endl;
        }
    }
}
