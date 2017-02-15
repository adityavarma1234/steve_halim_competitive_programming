#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//    int t;
//    cin >> t;
    string in,a,tmp;
//    getline(cin,in);
//    getline(cin,in);
//    while(t--)
//    {
        int n;
//        m.clear();
//        cin >> n;
        while(getline(cin, a) && a != "XXXXXX")
        {
            string tmp = a;
            sort(tmp.begin(), tmp.end());
            if(m.find(tmp) != m.end())
            {
                m[tmp].push_back(a);
//                cout << tmp << " ss " << m[tmp].size() << endl;
            }
            else
            {
                m[tmp] = vector<string>();
                m[tmp].push_back(a);
//                cout << tmp << " ff " << m[tmp].size() << endl;
            }
        }
        while(getline(cin, a) && a != "XXXXXX")
        {
            tmp = a;
            sort(tmp.begin(), tmp.end());
//            cout << "Anagrams for: " << a << endl;
            if(m.find(tmp) == m.end())
            {
                cout << "NOT A VALID WORD"<< endl;
            }
            else
            {
                sort(m[tmp].begin(), m[tmp].end());
                for(int i=0; i<m[tmp].size(); i++)
                {
                    cout << m[tmp][i] << endl;
                }
            }
            cout << "******" << endl;
        }
//        if(t) cout << endl;
//    }
    return 0;
}

