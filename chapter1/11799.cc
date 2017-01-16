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
        int max_val = -1, tmp;
        while(n--)
        {
            cin >> tmp;
            max_val = max(max_val, tmp);
        }
        printf("Case %d: %d\n",i,max_val);
    }
    return 0;
}
