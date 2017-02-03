#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<pair<int, int> >query;
string in,tmpin;
int findparent(int i)
{
    if(parent[i] == -1)
        return i;
    return findparent(parent[i]);
}
void uniond(int x, int y)
{
    if(x==y) return;
    int xset = findparent(x);
    int yset = findparent(y);
    parent[xset] = yset;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    getline(cin,in);
    getline(cin,in);
    while(t--)
    {
        parent.clear();
        query.clear();
        in.clear();
        int n;
        cin >> n;
        getline(cin, in);
        for(int i=0; i<n; i++)
        {
            parent.push_back(-1);
        }
        int cnt = 0;
        string ab;
        int x,y;
        pair<int,int> tmp;
        while(getline(cin,in) && in!="")
        {
//            cout << in << " her " << endl;
            istringstream as(in);
            cnt  =0;
            while(getline(as,tmpin, ' '))
            {
                if(cnt ==0)
                {
//                    cout << tmpin << "cahr " << endl;
                    ab = tmpin;
                    cnt++;
                }
                else
                {
//                    cout << atoi(tmpin.c_str()) << " int " << endl;
                    if(cnt==1)
                        x = atoi(tmpin.c_str());
                    if(cnt == 2)
                        y = atoi(tmpin.c_str());
                    cnt++;
                }
            }
            x--;
            y--;
            if(ab=="c")
            {
                uniond(x, y);
            }
            else
            {
                tmp.first = x;
                tmp.second = y;
                query.push_back(tmp);
            }
        }
        int p=0,q=0;
        for(int i=0; i<query.size(); i++)
        {
            int x,y;
            x = query[i].first;
            y = query[i].second;
            if(findparent(x) == findparent(y))
                p++;
            else
                q++;
        }
        cout << p<<"," << q << endl;
        if(t) cout << endl;
    }
    return 0;
}
