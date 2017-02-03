#include<bits/stdc++.h>

using namespace std;
priority_queue<int> g,b;
vector<int> battleg,battleb;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    while(n--)
    {
        int ba, sg, sb;
        cin >> ba >> sg >> sb;
        int tmp;
        while(!g.empty()) g.pop();
        while(!b.empty()) b.pop();
        for(int i=0; i<sg; i++)
        {
            cin >> tmp;
            g.push(tmp);
        }
        for(int i=0; i<sb; i++)
        {
            cin >> tmp;
            b.push(tmp);
        }
        while(!g.empty() && !b.empty())
        {
            battleb.clear();
            battleg.clear();
            for(int i=0; i<ba; i++)
            {
                if(g.empty() || b.empty())
                    break;
                battleb.push_back(b.top());
                b.pop();
                battleg.push_back(g.top());
                g.pop();
            }
            for(int i=0;i<battleb.size();i++)
            {
                if(battleb[i] > battleg[i])
                {
                    b.push(battleb[i] - battleg[i]);
                }
                else if(battleg[i] > battleb[i])
                {
                    g.push(battleg[i] - battleb[i]);
                }
            }
        }
        if(b.empty() && g.empty())
        {
            cout << "green and blue died" << endl;
        }
        else if(b.empty())
        {
            cout << "green wins" << endl;
            while(!g.empty())
            {
                cout << g.top() << endl;
                g.pop();
            }
        }
         else if(g.empty())
        {
            cout << "blue wins" << endl;
            while(!b.empty())
            {
                cout << b.top() << endl;
                b.pop();
            }
        }
        if(n) cout << endl;
    }
    return 0;
}
