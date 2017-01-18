#include<bits/stdc++.h>

using namespace std;
string a;
int arr[100];
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int T=1; T<=t; T++)
    {
        getline(cin,a);
        for(int i=0; i<100; i++) arr[i] = 0;
        int len = a.size();
        int j =0;
        for(int i=0; i<len; i++)
        {
            if(a[i] == '.')
                continue;
            else if(a[i] == '+')
            {
                arr[j]++;
                if(arr[j]>255) arr[j] = 0;
            }
            else if(a[i]=='-')
            {
                arr[j]--;
                if(arr[j]<0) arr[j] = 255;
            }
            else if(a[i] == '>')
            {
                j++;
                if(j==100) j = 0;
            }
            else if(a[i] == '<')
            {
                j--;
                if(j==-1) j=99;
            }
        }
        printf("Case %d: ", T);
        for(int i=0; i<99; i++)
        {
            printf("%02X ",arr[i]);
        }
        printf("%02X\n",arr[99]);

    }
    return 0;
}
