#include<bits/stdc++.h>

using namespace std;
char board[8][8];
char tmpboard[8][8];

bool valid(int r, int c)
{
    if(r>=0 && r<8 && c>=0 && c<8)
        return true;
    return false;
}

void pawnattackwhite(int r, int c)
{
    int x,y;
    x = r-1;
    y = c+1;
    if(valid(x,y) && (board[x][y]=='.'))
        board[x][y] = 'A';
    y = c-1;
    if(valid(x,y) && (board[x][y]=='.'))
        board[x][y] = 'A';
}

void pawnattackblack(int r, int c)
{
    int x,y;
    x = r+1;
    y = c+1;
    if(valid(x,y) && (board[x][y]=='.'))
        board[x][y] = 'A';
    y = c-1;
    if(valid(x,y) && (board[x][y]=='.'))
        board[x][y] = 'A';
}

void rookattack(int r, int c)
{
    int x = r;
    int y = c-1;
    while(y>=0)
    {
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            y--;
        }
        else
            break;
    }
    y= c+1;
    while(y<8)
    {
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] ='A';
            y++;
        }
        else
            break;
    }
    y = c;
    x = r-1;
    while(x>=0)
    {
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            x--;
        }
        else
            break;
    }
    x = r+1;
    while(x<8)
    {
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            x++;
        }
        else
            break;
    }
}

void bishopattack(int r, int c)
{
    int x = r+1;
    int y = c+1;
    while(valid(x, y))
    {
        if((board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            x++;y++;
        }
        else
        {
            break;
        }
    }
    x = r-1;
    y = c-1;
    while(valid(x, y))
    {
        if((board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            x--;y--;
        }
        else
        {
            break;
        }
    }
    x = r+1;
    y = c-1;
    while(valid(x, y))
    {
        if((board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            x++;y--;
        }
        else
        {
            break;
        }
    }
    x = r-1;
    y = c+1;
    while(valid(x, y))
    {
        if((board[x][y]=='.' || board[x][y] == 'A'))
        {
            board[x][y] = 'A';
            x--;y++;
        }
        else
        {
            break;
        }
    }
}
void knightattack(int r, int c)
{
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for(int i=0;i<8;i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if(valid(x, y) && (board[x][y]=='.'))
            board[x][y] = 'A';
    }
}
void kingattack(int r, int c)
{
    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {-1,0,1,1,-1,-1,0,1};
    for(int i=0;i<8;i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if(valid(x, y) && board[x][y] == '.')
            board[x][y] = 'A';
    }
}
void queenattack(int r, int c)
{
    bishopattack(r, c);
    rookattack(r, c);
    kingattack(r, c);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string tmp;
    while(1)
    {

        int i=0,j=0;
        for(i=0;i<8;i++)
        {
            getline(cin,tmp;)
            for(j=0;j<8;j++)
            {

                board[i][j] = tmp[j];
            }
        }
        bool f = true;
        for(i =0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][i] != '.')
                {
                    f= false;break;
                }
            }
            if(!f) break;
        }
        if(f) break;
        getline(cin, tmp);
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j] == 'p')
                {
                    pawnattackblack(i, j);
                }
                else if(board[i][j] == 'P')
                {
                    pawnattackwhite(i, j);
                }
                else if(board[i][j] == 'r' || board[i][j] == 'R')
                {
                    rookattack(i, j);
                }
                else if(board[i][j] == 'N' || board[i][j] == 'n')
                {
                    knightattack(i,j);
                }
                else if(board[i][j] == 'B' || board[i][j] == 'b')
                {
                    bishopattack(i, j);
                }
                else if(board[i][j] == 'Q' || board[i][j] == 'q')
                {
                    queenattack(i,j);
                }
                else if(board[i][j] == 'K' || board[i][j]=='k')
                {
                    kingattack(i,j);
                }
            }
        }
        int ans = -1;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j] == 'k')
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}



