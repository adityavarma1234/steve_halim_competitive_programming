#include<bits/stdc++.h>

using namespace std;
int dx[8] = {1,1, 1, -1, -1, -1, 0, 0};
int dy[8] = {0,-1, 1, -1, 0, 1, -1, 1};

int mins[122][122];
vector<string> board;
int main()
{
	int n,m,cnt=0;
//	freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	while(1)
	{

		cin >> n >> m;
		if(n==0 && m==0)
			break;
			if(cnt) cout <<  endl;
		cnt++;
		string tmp;
		board.clear();
		for(int i=0;i<123;i++)for(int j=0;j<123;j++) mins[i][j] = 0;
		for(int i=0;i<n;i++)
		{
			cin >> tmp;
			board.push_back(tmp);
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(board[i][j] == '*')
				{
					for(int k=0;k<8;k++)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						if(x >= 0 && x < n && y >= 0 && y < m)
						{
							mins[x][y]++;
						}
					}
				}
			}
		}
		printf("Field #%d:\n", cnt);
		for(int i=0;i<n;i++)
        {
            int j=0;
            for(j=0;j<m;j++)
            {
                if(board[i][j] == '*')
                printf("*");
                else
                    printf("%d", mins[i][j]);
            }
            printf("\n");
        }
	}
	return 0;
}
