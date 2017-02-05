#include<bits/stdc++.h>
using namespace std;
deque<int> dq;
vector<int> seq;
int main()
{
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(cin >> n && n)
    {
        dq.clear();
        seq.clear();
        for(int i=1;i<=n;i++)
            dq.push_back(i);
        while(dq.size() > 1)
        {
            seq.push_back(dq.front());
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout << "Discarded cards: ";
        int len = seq.size();
        for(int i=0;i<len;i++)
        {
            cout << seq[i];
            if(i != len-1)
                cout  << ", ";
        }
        cout << endl;
        cout << "Remaining card: " << dq.front() << endl;
    }
    return 0;
}
