#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
map<string,int>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    string a;
    cin >> t;
    getline(cin, a);
    getline(cin, a);
    while(t--)
    {
        m.clear();
        int total = 0;
        while(getline(cin, a) && a!="")
        {
            total++;
            if(m.find(a) == m.end())
            {
                m[a] = 1;
            }
            else
            {
                m[a] += 1;
//                cout << a << " " << m[a] << endl;
            }
        }
//        cout << total << " total" << endl;
        for(it = m.begin(); it != m.end(); it++)
        {
            double per = it->second ;
//            cout << per << " per" << endl;
            per *= 100.0;
            per = per/(double)total;
            printf("%s %.4f\n",it->first.c_str(), per);
        }
        if(t) cout << endl;
    }
    return 0;
}
