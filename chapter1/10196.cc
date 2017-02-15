#include<bits/stdc++.h>

using namespace std;
char board[8][8];
char tmpboard[8][8];
int ans=-2;
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
    if(valid(x,y) && (board[x][y]=='.' || board[x][y]=='k'))
        board[x][y] = 'A';
    y = c-1;
    if(valid(x,y) && (board[x][y]=='.'|| board[x][y]=='k'))
        board[x][y] = 'A';
}

void pawnattackblack(int r, int c)
{
    int x,y;
    x = r+1;
    y = c+1;
    if(valid(x,y) && (board[x][y]=='.'|| board[x][y]=='K'))
        board[x][y] = 'A';
    y = c-1;
    if(valid(x,y) && (board[x][y]=='.'|| board[x][y]=='K'))
        board[x][y] = 'A';
}

void rookattackwhite(int r, int c)
{
    int x = r;
    int y = c-1;
    while(y>=0)
    {
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
        {
            board[x][y] = 'A';
            x++;
        }
        else
            break;
    }
}

void rookattackblack(int r, int c)
{
    int x = r;
    int y = c-1;
    while(y>=0)
    {
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
        if(valid(x, y) && (board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
        {
            board[x][y] = 'A';
            x++;
        }
        else
            break;
    }
}

void bishopattackwhite(int r, int c)
{
    int x = r+1;
    int y = c+1;
    while(valid(x, y))
    {
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='k'))
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

void bishopattackblack(int r, int c)
{
    int x = r+1;
    int y = c+1;
    while(valid(x, y))
    {
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
        if((board[x][y]=='.' || board[x][y] == 'A'|| board[x][y]=='K'))
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
void knightattackwhite(int r, int c)
{
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for(int i=0;i<8;i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if(valid(x, y) && (board[x][y]=='.'|| board[x][y]=='k'))
            board[x][y] = 'A';
    }
}
void knightattackblack(int r, int c)
{
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    for(int i=0;i<8;i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if(valid(x, y) && (board[x][y]=='.'|| board[x][y]=='K'))
            board[x][y] = 'A';
    }
}
void kingattackwhite(int r, int c)
{
    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {-1,0,1,1,-1,-1,0,1};
    for(int i=0;i<8;i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if(valid(x, y) && (board[x][y] == '.'|| board[x][y]=='k'))
            board[x][y] = 'A';
    }
}
void kingattackblack(int r, int c)
{
    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {-1,0,1,1,-1,-1,0,1};
    for(int i=0;i<8;i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if(valid(x, y) && (board[x][y] == '.'|| board[x][y]=='K'))
            board[x][y] = 'A';
    }
}
void queenattackwhite(int r, int c)
{
    bishopattackwhite(r, c);
    rookattackwhite(r, c);
    kingattackwhite(r, c);
}
void queenattackblack(int r, int c)
{
    bishopattackblack(r, c);
    rookattackblack(r, c);
    kingattackblack(r, c);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string tmp;
    int cnt=1;
    while(1)
    {

        int i=0,j=0,p=-1,q=-1,r=-1,s=-1;
        for(i=0;i<8;i++)
        {
            getline(cin,tmp);
            for(j=0;j<8;j++)
            {

                board[i][j] = tmp[j];
                if(board[i][j] == 'k')
                {
                    p=i,q=j;
                }
                if(board[i][j] == 'K')
                {
                    r=i,s=j;
                }
            }
        }
//        cout << p << q << r << s << endl;
        bool f = true;
        for(i =0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j] != '.')
                {
                    f= false;break;
                }
            }
            if(!f) break;
        }
        if(f) break;
        getline(cin, tmp);
        ans = -2;
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
                else if(board[i][j] == 'R')
                {
                    rookattackwhite(i, j);
                }
                else if(board[i][j] == 'r')
                {
                    rookattackblack(i, j);
                }
                else if(board[i][j] == 'N')
                {
                    knightattackwhite(i,j);
                }
                else if(board[i][j] == 'n')
                {
                    knightattackblack(i,j);
                }
                else if(board[i][j] == 'B')
                {
                    bishopattackwhite(i, j);
                }
                else if(board[i][j] == 'b')
                {
                    bishopattackblack(i, j);
                }
                else if(board[i][j] == 'Q')
                {
                    queenattackwhite(i,j);
                }
                else if(board[i][j] == 'q')
                {
                    queenattackblack(i,j);
                }
                else if(board[i][j] == 'K')
                {
                    kingattackwhite(i,j);
                }
                else if(board[i][j]=='k')
                {
                    kingattackblack(i,j);
                }
            }
        }
//        int ans = -1;
//        for(i=0;i<8;i++)
//        {
//            for(j=0;j<8;j++)
//            {
//                if(board[i][j] == 'k')
//                    ans++;
//            }
//        }
//        cout << ans << endl;
        if(p!=-1 && board[p][q] == 'A')
        {
            printf("Game #%d: black king is in check.\n",cnt);
        }
        else if(r!=-1 && board[r][s] == 'A')
        {
            printf("Game #%d: white king is in check.\n",cnt);
        }
        else
        {
            printf("Game #%d: no king is in check.\n",cnt);
        }
        cnt++;
    }
    return 0;
}



