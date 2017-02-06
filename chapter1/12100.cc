#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> > q;
priority_queue<int> pq;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    pair<int,int> p;
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        while(!pq.empty()) pq.pop();
        while(!q.empty()) q.pop();
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            p.first = tmp;
            p.second = i;
            q.push(p);
            pq.push(tmp);
        }
        int ans =0;
        while(!q.empty())
        {
            p = q.front();
            if(p.first >= pq.top())
            {
                pq.pop();
                ans++;
                if(p.second == m)
                {
                    cout << ans << endl;
                    break;
                }
                q.pop();
            }
            else
            {
                q.pop();
                q.push(p);
            }
        }
    }
    return 0;
}
