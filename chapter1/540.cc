#include<bits/stdc++.h>

using namespace std;
vector<queue<int> >tq;
map<int,int> teams;
map<int,int> tqn;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    int cnt=0;
    while(cin>> t && t)
    {
        if(cnt)         cout << endl;

        cnt++;
        printf("Scenario #%d\n",cnt);
        int n;
        tq.clear();
        teams.clear();
        tqn.clear();
        for(int i=0; i<t; i++)
        {
            cin >> n;
            for(int j=0; j<n; j++)
            {
                int tmp;
                cin >> tmp;
//                cout << tmp << endl;
                teams[tmp] = i;
            }
            tqn[i] = -1;
        }
        int startq = 0;
        string op;
        while(cin >> op && op!= "STOP")
        {
            if(op == "ENQUEUE")
            {
                int tnum;
                cin >> tnum;
                if(tqn[teams[tnum]] == -1)
                {
//                    cout << "first time enque "<< tnum  << endl;
//                    cout << "team " << teams[tnum] << endl;
                    tq.push_back(queue<int>());
                    tq[tq.size()-1].push(tnum);
                    tqn[teams[tnum]] = tq.size()-1;
//                    cout << "queue val " << tqn[teams[tnum]] << " queue size " << tq[teams[tnum]].size() << endl;
                }
                else
                {
//                    cout << "enque at " << tnum << " " << teams[tnum] << " team in queu " << tqn[teams[tnum]] <<endl;
                    tq[tqn[teams[tnum]]].push(tnum);
//                    cout << "size after enque " << tq[tqn[teams[tnum]]].size() << endl;
                }
            }
            else if(op=="DEQUEUE")
            {
//                cout << "dequeu " << endl;
//                cout << "queue start " << startq << endl;
                int val = tq[startq].front();
                cout << val << endl;
                tq[startq].pop();
                if(tq[startq].empty())
                {
                    tqn[teams[val]] = -1;
                    startq++;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
