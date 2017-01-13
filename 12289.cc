#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string words[3] = {"one", "two", "three"};
    cin >> t;
    while(t--)
    {
        int mis = 0;
        string a;
        cin >> a;
        bool flag = true;
        for(int i=0;i<3; i++)
        {
            if(a==words[i])
            {
                cout << i+1 << endl;
                flag = false;
            }
        }
        if(flag)
        {
            for(int j=0;j<3;j++)
            {
                if(a.size() == words[j].size())
                {
                    for( int i=0;i<a.size();i++)
                    {
                        if(a[i] != words[j][i]) mis++;
                    }
                    if(mis>1) mis =0;
                    else {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
