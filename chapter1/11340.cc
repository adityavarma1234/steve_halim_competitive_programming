#include<bits/stdc++.h>
using namespace std;
int val[256];
char str[10003];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        for(int i=0;i<256;i++)
            val[i] = 0;
        int k;
        scanf("%d\n",&k);
        for(int i=0;i<k;i++)
        {
            char tmp;
            int cost;
            scanf("%c %d\n",&tmp, &cost);
            val[tmp] = cost;
//            printf("tmp cost val[tmp] %c %d %d\n", tmp, cost, val[tmp]);
        }
        int m;
        scanf("%d\n",&m);
        long long int ans = 0;
        for(int i=0;i<m;i++)
        {
            gets(str);
            int len = strlen(str);
            for(int j=0;j<len;j++)
            {
//                printf("ans %d str[j] %c val %d\n", ans, str[j], str[j]);
                ans += val[str[j]];
            }
        }
        printf("%lld.%.2lld$\n",ans/100, ans%100);
    }
    return 0;
}
