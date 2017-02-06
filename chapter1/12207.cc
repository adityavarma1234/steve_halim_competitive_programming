#include<bits/stdc++.h>
using namespace std;
deque<int> dq;
deque<int>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,cnt=0;
    while(cin >> n  >>m && n+m)
    {
        cnt++;
        while(!dq.empty()) dq.pop_back();
        for(int i=1;i<=min(1002,n);i++)
        {
            dq.push_back(i);
        }
        printf("Case %d:\n",cnt);
        for(int i=0;i<m;i++)
        {
            char a;
            int x;
            cin >> a;
            if(a == 'N')
            {
                cout << dq.front() << endl;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                cin >> x;
                for(it = dq.begin(); it!=dq.end();it++)
                {
                    if(*it == x)
                    {
                        dq.erase(it);
                        break;
                    }
                }
                dq.push_front(x);
            }
        }
    }
    return 0;
}
