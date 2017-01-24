#include<bits/stdc++.h>

using namespace std;
int seen[5][5], bingo[5][5], val[75],ans ;
bool mark(int a)
{
    seen[2][2] = 1;
    bool f = true;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(bingo[i][j] == a)
            {
                seen[i][j] = 1;
                return true;
            }
        }
    }
    return false;
}
bool checkbingo()
{
    int i,j;
    bool f =  true;
    for(i=0; i<5; i++)
    {
        f = true;
        for(j=0; j<5; j++)
        {
            if(seen[i][j] == 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            return true;
    }
    for(j = 0; j<5; j++)
    {
        f = true;
        for(i=0; i<5; i++)
        {
            if(seen[i][j] == 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            return true;
    }
    i = 0;
    j=0;
    f=true;
    while(i<5 && j<5)
    {
        if(seen[i][j] == 0)
        {
            f = false;
            break;
        }
        i++;
        j++;
    }
    if(f) return true;
    i=4;
    j=0;
    f=true;
    while(i>=0 && j<5)
    {
        if(seen[i][j] == 0)
        {
            f = false;
            break;
        }
        i--;
        j++;
    }
    if(f) return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,cnt=0;
    cin >> t;
    while(t--)
    {
        cnt++;
        int i,j;
        ans = 0;
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                bingo[i][j] = 0;
                seen[i][j] = 0;
            }
        }
        for(i = 0; i<2; i++)
        {
            for(j=0; j<5; j++)
            {
                cin >> bingo[i][j];
            }
        }
        i = 2;
        for(j=0; j<5; j++)
        {
            if(j==2)
            {
                bingo[i][j] = 0;
                j++;
            }
            cin >> bingo[i][j];
        }
        for(i=3; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                cin >> bingo[i][j];
            }
        }
        for(i=0; i<75; i++)
        {
            cin >> val[i];
        }
//        if(cnt==29){
//                for(i=0;i<5;i++)
//                    {
//                        for(j=0;j<5;j++)
//                        {
//                            cout << bingo[i][j] << " ";
//                        }
//                        cout << endl;
//                    }
        for(i=0; i<75; i++)
        {
            ans++;
            if(mark(val[i]) && checkbingo())
            {
                cout << "BINGO after " << ans << " numbers announced\n";
                break;
            }
        }
//        }
    }
    return 0;
}
