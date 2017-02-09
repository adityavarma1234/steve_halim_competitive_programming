#include<bits/stdc++.h>
using namespace std;
map<string,string> old,new1;
map<string,string>::iterator it;
set<string> add, sub, change;
string a, b;
set<string>::iterator itt;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    getline(cin,a);
    while(t--)
    {
        old.clear();
        new1.clear();
        add.clear();
        sub.clear();
        change.clear();
        getline(cin, a);
//        cout << a << endl;
        getline(cin, b);
//        cout << b << endl;
        if(a.size() > 2)
        {
            a = a.substr(1, a.size() - 2);
        }
        if(b.size() > 2)
        {
            b = b.substr(1, b.size() - 2);
        }
        istringstream ss(a);
        string tmp;
        if(a.size()>2)
        while(getline(ss, tmp, ','))
        {
            istringstream sa(tmp);
            string b;
            int cnt = 0;
            string key,value;
            while(getline(sa, b, ':'))
            {
                if(cnt == 0)
                {
                    key = b;
                }
                if(cnt == 1)
                {
                    value = b;
                }
                cnt++;
            }
            old[key] = value;
        }
        istringstream sb(b);
        if(b.size()>2)
        while(getline(sb, tmp, ','))
        {
            istringstream sa(tmp);
            string b;
            int cnt = 0;
            string key,value;
            while(getline(sa, b, ':'))
            {
                if(cnt == 0)
                {
                    key = b;
                }
                if(cnt == 1)
                {
                    value = b;
                }
                cnt++;
            }
            new1[key] = value;
        }
        for(it = new1.begin(); it != new1.end(); it++)
        {
            if(old.find(it->first) == old.end())
            {
                add.insert(it->first);
//                cout << "addition " << it->first << endl;
            }
            else if(old[it->first] != new1[it->first])
            {
                change.insert(it->first);
//                cout << "change " << it->first << endl;
            }
        }
        for(it = old.begin(); it != old.end(); it++)
        {
            if(new1.find(it->first) == new1.end())
            {
                sub.insert(it->first);
//                cout << "subtractuion " << it->first << endl;

            }
        }
        int cnt = 0;
        if(add.size() + sub.size() + change.size() == 0)
        {
            cout << "No changes" << endl;
        }
        else
        {
            int cnt = 0;
            if(add.size() > 0)
            {
                cout << "+";
                for(itt=add.begin(); itt!= add.end(); itt++)
                {
                    if(cnt==0)
                    cout << *itt;
                    else
                        cout << "," << *itt;
                    cnt++;
                }
                cout << endl;
            }
            if(sub.size() > 0)
            {
                cout << "-";
                cnt = 0;
                for(itt=sub.begin(); itt != sub.end(); itt++)
                {
                    if(cnt == 0)
                    cout << *itt;
                    else cout << "," << *itt;
                    cnt++;
                }
                cout << endl;
            }
            if(change.size() > 0)
            {
                cout << "*";cnt=0;
                for(itt = change.begin(); itt!= change.end(); itt++)
                {
                    if(cnt == 0)
                    cout << *itt;
                    else cout << "," << *itt;
                    cnt++;
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
