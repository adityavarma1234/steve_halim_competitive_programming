#include<bits/stdc++.h>


using namespace std;

int a[123];

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> a[j];
        }
        int up=0,down=0, prev=-1;
        for(int j=1;j<n;j++)
        {
            if(a[j]-a[j-1] > 0) up++;
            if(a[j] - a[j-1] < 0) down++;
        }
        printf("Case %d: %d %d\n", i, up, down);
    }
    return 0;
}
