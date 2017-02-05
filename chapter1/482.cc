#include<bits/stdc++.h>
using namespace std;
vector<pair<int, string> >v;
vector<int> ind;
vector<string> nums;
pair<int, string> p;
int main()
{
    freopen("input.txt",  "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    string in,fin;
    getline(cin, in);
     while(t--)
    {
            getline(cin, in);
        getline(cin, in);
        v.clear();
        ind.clear();
        nums.clear();
        stringstream ss(in);
        int tmp;
        while(ss >> tmp)
        {
            ind.push_back(tmp);
        }

        string tm;
        getline(cin, in);
        istringstream sa(in);
        while(getline(sa, tm, ' '))
        {
            nums.push_back(tm);
        }
        for(int i=0;i<min(nums.size(),ind.size());i++)
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
        if(t)
        cout << endl;
    }
    return 0;
}
