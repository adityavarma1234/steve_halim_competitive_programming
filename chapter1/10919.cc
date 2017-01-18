#include<bits/stdc++.h>

using namespace std;

bool present(vector<int> v, int a)
{
    for(int i=0;i<v.size(); i ++)
    {
        if(v[i] == a)
            return true;
    }
    return false;
}

int main()
{
    int k,m;
    vector<int> v;
    while(1)
    {
        cin >> k;
        if(k == 0)
            break;
        cin >> m;
        v.clear();
        int tmp;
        for(int i=0;i<k;i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        bool flag = true;
        for(int i=0;i<m;i++)
        {
            int total, min_req;
            cin >> total >> min_req;
            int cnt = 0;
            for(int j = 0;j< total;j++)
            {
                cin >> tmp;
                if(present(v, tmp))
                {
                    cnt++;
                }
            }
            if(cnt < min_req)
            {
                flag = false;
            }
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
