#include<bits/stdc++.h>
using namespace std;
vector<pair<string, set<string> > >in;
map<string, int> seen;
set<string> ignor;
vector<string> tmp;
pair<string, set<string> > p;
vector<pair<int, string> >ans;
pair<int, string> pp;
bool compare(pair<int, string> a, pair<int, string> b)
{
    if(a.first > b.first)
        return true;
    if(a.first < b.first)
        return false;
    if(a.second < b.second)
        return true;
    return false;
}
void printans()
{
    for(int i=0;i<in.size();i++)
    {
        tmp.clear();
        set_difference(in[i].second.begin(), in[i].second.end(), ignor.begin(), ignor.end(), ::back_inserter(tmp));
        pp.second = in[i].first;
        pp.first = tmp.size();
        ans.push_back(pp);
//        cout << pp.first << " " << pp.second << " " << in[i].second.size() << endl;
    }
    sort(ans.begin(), ans.end(),compare);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i].second << " " << ans[i].first << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cnt = 0;
    string a;
    while(getline(cin, a) && a != "0")
    {
//        cout << a << endl;
        if(a == "1")
        {
            printans();
            in.clear();
            seen.clear();
            ignor.clear();
            tmp.clear();
            ans.clear();
            cnt = 0;
            continue;
        }
        if(a[0] >= 'A' && a[0] <= 'Z')
        {
//            cout << "project " << a << endl;
            p.first = a;
            p.second = set<string>();
            in.push_back(p);
            cnt++;
        }
        else
        {
//            cout << "student " << a << endl;
            if(seen.find(a) != seen.end() && seen[a] != cnt)
            {
//                cout << "already seen " << a << " " << seen[a] << endl;
                ignor.insert(a);
            }
            else if(seen.find(a) == seen.end())
            {
                seen[a] = cnt;
//                cout << "first time seeen " << a << " " << seen[a] << endl;

            }
            in[in.size()-1].second.insert(a);
        }
    }
    return 0;
}
