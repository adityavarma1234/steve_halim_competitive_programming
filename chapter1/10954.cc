#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
int main()
{
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(1)
    {
        cin >> n;
                while(!min_heap.empty())min_heap.pop();
        if(n == 0)
            break;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            min_heap.push(tmp);
        }
        int ans = 0;
        while(min_heap.size()>1)
        {
            int top = min_heap.top();
            min_heap.pop();
            int stop = min_heap.top();
            min_heap.pop();
            ans += top + stop;
//            cout << ans << " " << top << " " << stop << endl;
            min_heap.push(top+stop);
        }
        cout << ans << endl;
    }
    return 0;
}
