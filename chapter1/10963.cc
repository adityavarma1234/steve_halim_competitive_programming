#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;
        int gap;
        bool flag = true;
        int a,b;
        cin >> a >> b;
        gap = abs(a-b);
        n--;
        while(n--)
        {
            cin >> a >> b;
            if(gap != abs(a-b))
                flag = false;
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
        if(i!=t)cout << endl;
    }
    return 0;
}
