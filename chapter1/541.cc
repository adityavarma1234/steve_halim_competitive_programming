#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int row[101],col[101];
void init()
{
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            a[i][j] = 0;
        }
        row[i] = 0;
        col[i] = 0;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    while(cin >> n && n)
    {
        int rowsum = 0, colsum = 0;
        for(int i=0;i<n;i++)
        {
            rowsum = 0;
            for(int j=0;j<n;j++)
            {
                cin >> a[i][j];
                if(a[i][j]) rowsum ++;
            }
            row[i] = rowsum;
        }
        for(int i=0;i<n;i++)
        {
            colsum=0;
            for(int j=0;j<n;j++)
            {
                if(a[j][i])
                    colsum++;
            }
            col[i] = colsum;
        }
        bool f = true;
        int rowodd=0, colodd=0,ro=0,co=0;
        for(int i=0;i<n;i++)
        {
            if(row[i]%2 )
                {
                    ro = i;
                    rowodd++;
                }
        }
        for(int i=0;i<n;i++)
        {
            if(col[i]%2)
            {
                co = i;
                colodd++;
            }
        }
        if(rowodd == 0 && colodd == 0) cout << "OK" << endl;
        else if(rowodd == 1 && colodd == 1) printf("Change bit (%d,%d)\n",ro+1,co+1);
        else cout << "Corrupt\n";
    }
    return 0;
}
