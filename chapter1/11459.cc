#include<bits/stdc++.h>
using namespace std;

int ladder[101], snake[101];
int player[1000002];


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,x,y;
        cin >> a >> b >> c;
        for(int i=0;i<a;i++) player[i] = 1;
        for(int i=0;i<101;i++)
        {
            ladder[i] = 0;
            snake[i] = 0;
        }
        while(b--)
        {
            cin >> x >> y;
            if(x>y)
                snake[x] = y;
            else
                ladder[x] = y;
        }
        bool gameover = false;
        for(int i=0;i<c;i++)
        {
            int turn;
            cin >> turn;
            if(!gameover)
            {
                player[i%a] += turn;
//                cout << i << " " << i%a << " " << player[i%a] << endl;
                if(player[i%a] >= 100)
                {
                    player[i%a] = 100;
                    gameover = true;
                }
                if(ladder[player[i%a]])
                {
                    player[i%a] = ladder[player[i%a]];
                    if(player[i%a] >= 100)
                {
                    player[i%a] = 100;
                    gameover = true;
                }
                }
                if(snake[player[i%a]])
                    player[i%a] = snake[player[i%a]];
            }
        }
        for(int i=0;i<a;i++)
        {
            printf("Position of player %d is %d.\n", i+1, player[i]);
        }
    }
    return 0;
}
