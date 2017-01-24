#include<bits/stdc++.h>

using namespace std;

int words[1001];
vector<string> v,tmpv,sv;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string tmp,in="";
    while(1)
    {
        getline(cin, tmp);
        if(tmp == "#")
            break;
        string tmpi;
        istringstream ss(tmp);
        while(getline(ss, tmpi, ' '))
        {
            if(tmpi == " ") continue;
            v.push_back(tmpi);
            transform(tmpi.begin(), tmpi.end(), tmpi.begin(), ::tolower);
            tmpv.push_back(tmpi);
            sort(tmpv.back().begin(), tmpv.back().end());
        }
    }
    int i=0,j=0;
    for(i=0;i<tmpv.size();i++)
    {
        for(j=0;j<tmpv.size();j++)
        {
            if(i!=j && tmpv[i] == tmpv[j])
            {
                words[i] = 1;
                words[j] = 1;
            }
        }
    }
    for(int i=0;i<tmpv.size();i++)
    {
        if(words[i] == 0)
        {
            sv.push_back(v[i]);
        }
    }
    sort(sv.begin(), sv.end());
    for(int i=0;i<sv.size();i++)
    {
        cout << sv[i] << endl;
    }
    return 0;
}
