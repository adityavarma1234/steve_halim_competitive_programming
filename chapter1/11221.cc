#include<bits/stdc++.h>

using namespace std;

string tmp,in;
int squares[10001];
char tmpsqr[101][101];
bool magicpossible()
{
    int len = in.size();
    int k= squares[len];
    int i=0,j=0;
    bool f = false;
    for(int z=0; z<len; z++)
    {
        if(j!=0 && z%k == 0)
        {
            i++;
            j=0;
        }
        tmpsqr[i][j] = in[z];
        j++;
    }
    string tmp = "";
    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++)
        {
            tmp += string(1, tmpsqr[i][j]);
        }
    }
    if(tmp != in)
        return false;
    tmp.clear();
    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++)
        {
            tmp += string(1, tmpsqr[j][i]);
        }
    }
    if(tmp != in)
        return false;
            tmp.clear();

    for(i=k-1; i>=0; i--)
    {
        for(j=k-1; j>=0; j--)
        {
            tmp += string(1, tmpsqr[i][j]);
        }
    }
    if(tmp != in)
        return false;
            tmp.clear();

    for(i=k-1; i>=0; i--)
    {
        for(j=k-1; j>=0; j--)
        {
            tmp += string(1, tmpsqr[j][i]);
        }
    }
    if(tmp != in)
        return false;
    return true;
}
int main()
{
    int t;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for(int i=0; i<1000; i++)
    {
        if(i*i > 10000)
            break;
        squares[i*i] = i;
    }
    cin >> t;
            getline(cin, tmp);

    for(int T=1; T<=t; T++)
    {
        getline(cin, tmp);
        in.clear();
        in = "";
        for(int i=0; i<tmp.size(); i++)
        {
            if(tmp[i]>='a' && tmp[i]<='z')
                in += string(1, tmp[i]);
        }
//        cout << in << endl;
        int len = in.size();
//        cout << len << squares[len] << endl;
        printf("Case #%d:\n", T);
        if(squares[len] == 0)
        {
            printf("No magic :(\n");
        }
        else if(magicpossible())
        {
            printf("%d\n",squares[len]);
        }
        else
        {
            printf("No magic :(\n");
        }
    }
    return 0;
}
