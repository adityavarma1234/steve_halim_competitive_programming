#include<bits/stdc++.h>
using namespace std;
vector<int> in;
map<int,int>m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tmp;
    while(cin>>tmp)
    {
        if(m.find(tmp) == m.end())
        {
            in.push_back(tmp);
            m[tmp] = 1;
        }
        else
        {
            m[tmp] += 1;
        }
    }
    for(int i=0;i<in.size();i++)
    {
        cout << in[i] << " " << m[in[i]] << endl;
    }
    return 0;
}
