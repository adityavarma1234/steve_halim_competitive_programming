#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10], b[10];
    cout << "Lumberjacks:" << endl;
    while(n--)
    {
        for(int i=0;i<10;i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b+10);
        bool flag = true;
        for(int i=0;i<10;i++)
        {
            if(a[i] != b[i])
            {
                flag = false;
                break;
            }
        }
        sort(b, b+10, greater<int>());
        bool flag1 = true;
        for(int i=0;i<10;i++)
        {
            if(a[i]!=b[i])
            {
                flag1 = false;
                break;
            }
        }
        if(flag || flag1) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
    return 0;
}
