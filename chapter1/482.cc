#include<bits/stdc++.h>
using namespace std;
vector<pair<string, string> >v;
vector<string> ind;
vector<string> nums;
pair<string, string> p;
int main()
{
    freopen("input.txt",  "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    string in,fin;
    getline(cin, in);
    getline(cin, in);
    while(t--)
    {
        getline(cin, in);
        v.clear();
        ind.clear();
        nums.clear();
        istringstream ss(in);
        string tmp;
        while(getline(ss, tmp, ' '))
        {
            ind.push_back(tmp);
        }
        getline(cin, in);
        istringstream sa(in);
        while(getline(sa, tmp, ' '))
        {
            nums.push_back(tmp);
        }
        for(int i=0;i<nums.size();i++)
        {
            p.first = ind[i];
            p.second = nums[i];
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++)
        {
            cout << v[i].second << endl;
        }
        getline(cin, in);
        if(t)
        cout << endl;
    }
    return 0;
}
