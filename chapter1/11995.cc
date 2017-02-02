#include<bits/stdc++.h>
using namespace std;
stack<int> s;
queue<int> q;
priority_queue<int> pq;
int st, qu, pqq;
void init()
{
    while(!s.empty()) s.pop();
    while(!q.empty()) q.pop();
    while(!pq.empty()) pq.pop();
    st  =1;
    qu = 1;
    pqq = 1;
}
void one(int a)
{
    s.push(a);
    q.push(a);
    pq.push(a);
}
void two(int a)
{
    if(s.empty() || s.top() != a)
        st = 0;
    else if(!s.empty())
        s.pop();

    if(q.empty() || q.front() != a)
        qu = 0;
    else if(!q.empty())
        q.pop();
    if(pq.empty() || pq.top() != a)
        pqq = 0;
    else if(!pq.empty())
        pq.pop();
}
int main()
{
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(cin >> n)
    {
        init();
        int a,b;
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            if(a == 1) one(b);
            else two(b);
        }
        if(st + qu + pqq > 1)
            cout << "not sure" << endl;
        else if(st + qu + pqq == 0)
            cout << "impossible" << endl;
        else if(st==1)
            cout << "stack" << endl;
        else if(qu == 1)
            cout << "queue" << endl;
        else if(pqq == 1)
            cout << "priority queue" << endl;
    }
    return 0;
}
