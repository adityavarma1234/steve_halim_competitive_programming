#include<bits/stdc++.h>
using namespace std;
int play[101][2];
bool win(string a, string b)
{
    if(a == "rock" && b == "paper")
        return false;
    if(a == "rock" && b == "scissors")
        return true;
    if(a == "paper" && b == "rock")
        return true;
    if(a == "paper" && b == "scissors")
        return false;
    if(a == "scissors" && b == "rock")
        return false;
    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cnt = 0;
    while(1)
    {
        int n,k;
        cin >> n ;
        if(n == 0)
            break;
        if(cnt) cout << endl;
        cin >> k;
        int val = k*(n-1)*n/2;
        for(int i=0;i<101;i++) play[i][0] = play[i][1] = 0;
        for(int i=0;i<val;i++)
        {
            int p1, p2;
            string a, b;
            cin >> p1 >> a >> p2 >> b;
            if(a!=b)
            {
                if(win(a,b))
                {
                    play[p1][0]++;
                    play[p2][1]++;
                }
                else
                {
                    play[p1][1]++;
                    play[p2][0]++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            int w,l;
            w = play[i][0];
            l = play[i][1];
            if(w+l == 0)
                printf("-\n");
            else
            {
                float f;
                f = (float)w/(float)(w+l);
                printf("%.3f\n", f);
            }
        }
        cnt++;
    }
    return 0;
}
