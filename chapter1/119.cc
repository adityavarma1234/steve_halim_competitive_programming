#include<bits/stdc++.h>

using namespace std;

int spent[10], rec[10], balance[10];
vector<string> v;
int return_index(string a)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == a)
            return i;
    }
}

int main()
{
    int n;
    bool flag=false;
    while(scanf("%d",&n) != EOF)
    {
        v.clear();
        int i, j;
        string tmp;
        for(i=0; i<n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
            spent[i] = rec[i] = balance[i] = 0;
        }
        for(i=0; i<n; i++)
        {
            cin >> tmp;
            j = return_index(tmp);
            int spend, friends;
            cin >> spend >> friends;
            spent[j] += spend;
            if(friends!=0)
            balance[j] += spend%friends;
            else
            balance[j] += spend;
            for(int k=0; k<friends; k++)
            {
                cin >> tmp;
                j = return_index(tmp);
                rec[j] += spend/friends;
            }
        }
         if(flag)
            cout << endl;
        else flag = true;
        for(i =0; i<n; i++)
        {
            cout << v[i] << " " << rec[i] + balance[i] - spent[i] << endl ;
        }
    }
    return 0;
}
