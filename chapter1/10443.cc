#include<bits/stdc++.h>

using namespace std;
vector<string> in, tin;
char findwinner(char a, char b)
{
    if(a == 'R' && b == 'S')
        return 'R';
    if(a == 'S' && b == 'R')
        return 'R';
    if(a == 'R' && b == 'P')
        return 'P';
    if(a == 'P' && b == 'R')
        return 'P';
    if(a == 'S' && b == 'P')
        return 'S';
    if(a == 'P' && b == 'S')
        return 'S';
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,cnt;
        cin >> n >> m >> cnt;
        in.clear();
        tin.clear();
        for(int i=0; i<n; i++)
        {
            string tmp;
            cin >> tmp;
            in.push_back(tmp);
            tin.push_back(tmp);
        }
        while(cnt--)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    char winner = in[i][j];
                    int dx[4] = {0, 0, 1, -1};
                    int dy[4] = {1, -1, 0, 0};
                    for(int k=0; k<4; k++)
                    {
                        int x = i+dx[k];
                        int y = j+dy[k];
                        if(x >=0 && x <n && y>=0 && y<m && winner != in[x][y])
                        {
                            char cwinner = findwinner(winner, in[x][y]);
                            if(winner == cwinner)
                            {
                                continue;
                            }
                            else
                            {
                                winner = cwinner;
                                break;
                            }
                        }
                    }
                    tin[i][j] = winner;
                }
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    in[i][j] = tin[i][j];
                }
            }
//            cout << cnt << "cnt " << endl;
//            for(int i=0; i<n; i++)
//            {
//                for(int j=0; j<m; j++)
//                {
//                    cout << in[i][j];
//                }
//                cout << endl;
//            }
//            cout << endl;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << in[i][j];
            }
            cout << endl;
        }
        if(t)cout << endl;
    }
    return 0;
}
