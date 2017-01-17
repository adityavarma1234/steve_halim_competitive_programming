#include<bits/stdc++.h>

using namespace std;

int reserves[123];
int credits[123];
int deb[123];
int main()
{
    while(1)
    {
        int b,n;
        cin >> b >> n;
        if(b==0 && n==0)
        {
            break;
        }
        for(int i=1; i<=123; i++)
        {
            reserves[i] = 0;
            credits[i] = 0;
            deb[i] = 0;
        }
        for(int i=1; i<=b; i++)
        {
            cin >> reserves[i];
        }
        bool flag = true;
        for(int i=1; i<=n; i++)
        {
            int x, y ,z;
            cin >> x >> y >> z;
            credits[y] += z;
            deb[x] += z;
        }
        for(int i=1; i<=b; i++)
        {
            if(reserves[i] + credits[i]< deb[i])
            {
                flag = false;
                break;
            }
        }
        if(flag) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
