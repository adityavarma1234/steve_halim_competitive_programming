#include<bits/stdc++.h>

using namespace std;

int sum[1000005];
char a[1000005];
int main()
{
    int c=0;
    while(scanf("%s", a) != EOF)
    {
        c++;
        int len = strlen(a);
        for(int i=0;i<len;i++)
        {
            int value = 0;
            if(a[i] == '1') value = 1;
            sum[i+1] = sum[i] + value;
        }
        int q;
        cin >> q;
        printf("Case %d:\n", c);
        while(q--)
        {
            int x, y, tmp;
            cin >> x >> y;
            x++;y++;
            tmp = max(x,y);
            x = min(x, y);
            y = tmp;
            if(sum[y]-sum[x-1] == 0 || sum[y] - sum[x-1] == y-x+1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
