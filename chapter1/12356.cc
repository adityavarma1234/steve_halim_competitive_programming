#include<bits/stdc++.h>

using namespace std;
int alive[100002][2];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cnt =0;
    while(1)
    {
        int s,b;
        scanf("%d %d",&s, &b);
        if(s == 0 && b==0) break;
        for(int i=1; i<=s; i++)
        {
            alive[i][0] = i-1;
            alive[i][1] = i+1;
        }
        alive[s][1] = 0;
        for(int i=0; i<b; i++)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            int left=0, right=0;
            left = alive[l][0];
            right = alive[r][1];
            if(left)
            {
                alive[left][1] = right;
            }
            if(right)
            {
                alive[right][0] = left;
            }
            if(left)
            {
                printf("%d", left);
            }
            else
            {
                printf("*");
            }
            if(right)
            {
                printf(" %d\n", right);
            }
            else
            {
                printf(" *\n");
            }
        }
        printf("-\n");
    }
    return 0;
}
