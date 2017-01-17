#include<bits/stdc++.h>

using namespace std;

int arr[123];
bool toggle[123];

int main()
{
    int n,m,c;
    int con = 0;
    while(1)
    {
        con++;
        cin >> n >> m >> c;
        if(n==0 && m==0 && c==0) break;
        for(int i=0;i<25;i++)
        {
            arr[i] = 0;
            toggle[i] = false;
        }
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i] ;
        }
        bool blast = false;
        int max_cons = 0,curr=0;
        for(int i=1;i<=m;i++)
        {
            int tmp;
            cin >> tmp;
            if(toggle[tmp])
            {
                curr -= arr[tmp];
                toggle[tmp] = false;
            }
            else
            {
                curr += arr[tmp];
                toggle[tmp] = true;
            }
            if(curr>c)
            {
                blast = true;
            }
            max_cons = max(max_cons, curr);
        }
        printf("Sequence %d\n",con);
        if(blast) cout << "Fuse was blown." << endl << endl;
        else
        {
            cout << "Fuse was not blown." << endl ;
            printf("Maximal power consumption was %d amperes.\n\n", max_cons);
        }
    }
    return 0;
}
