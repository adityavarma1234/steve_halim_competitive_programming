#include<bits/stdc++.h>

using namespace std;

int main()
{
    while(1)
    {
        int a,b;
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        int tmp;
        tmp = max(a, b);
        a = min(a, b);
        b = tmp;
        cout << min(abs(a-b), abs(a-b+100)%100) << endl;
    }
    return 0;
}
