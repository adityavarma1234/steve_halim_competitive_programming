#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 0;
    string ab = "good";
    string ba = "bad";
    while(t--)
    {
        c++;
        int a;
        bool flag = false;
        for(int i=0;i<3; i++)
        {
            cin >> a;
            if(a > 20)
                flag = true;
        }
        if(!flag)
        {
            printf("Case %d: %s\n", c, ab.c_str());
        }
        else
        {
            printf("Case %d: %s\n", c, ba.c_str());
        }
    }
    return 0;
}
