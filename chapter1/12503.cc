#include<bits/stdc++.h>

using namespace std;

int steps[123];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x=0,n, tmp;
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            string a;
            cin >> a;
            if(a[0] == 'L')
            {
                steps[i] = -1;
                x--;
            }
            else if(a[0] == 'R')
            {
                steps[i] = 1;
                x++;
            }
            else
            {
                cin >> a;
                cin >> tmp;
                x += steps[tmp];
                steps[i] = steps[tmp];
            }
//            cout << x << endl;
        }
        cout << x << endl;
    }
    return 0;
}
