#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int j=0;j<n;j++)
    {
        vector<string> s;
        int a[10];
        string tmp;
        int max_val = -1;
        for(int i=0;i<10;i++)
        {
            cin >> tmp;
            s.push_back(tmp);
            cin >> a[i];
            max_val= max(a[i], max_val);
        }
        printf("Case #%d:\n", j+1);
        for(int i=0;i<10;i++)
        {
            if(a[i] == max_val)
            {
                cout << s[i] << endl;
            }
        }
    }
    return 0;
}
