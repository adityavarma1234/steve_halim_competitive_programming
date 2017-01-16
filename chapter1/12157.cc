#include<bits/stdc++.h>

using namespace std;

int mile(int a)
{
    int ans = 0;
    ans = 10 * (a/30 + 1) ;
    return ans;
}

int juice(int a)
{
    int ans = 0;
    ans = 15 * (a/60 + 1);
    return ans;
}

int arr[123];
int main()
{
    int t,n;
    cin >> t;
    for(int i=1; i <=t ;i++)
    {
        cin >> n;
        int tmp;
        int mile1=0,juice1=0;
        for(int j=1;j<=n;j++)
        {
            cin >> tmp;
            mile1 += mile(tmp);
            juice1 += juice(tmp);
        }
        printf("Case %d: ", i);
        if(mile1 == juice1)
        {
            printf("Mile Juice %d\n", mile1);
        }
        else if( mile1 < juice1)
        {
            printf("Mile %d\n", mile1);
        }
        else
        {
            printf("Juice %d\n", juice1);
        }
    }
    return 0;
}
