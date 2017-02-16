#include<bits/stdc++.h>

using namespace std;
int dx[8] = {1,1, 1, -1, -1, -1, 0, 0};
int dy[8] = {0,-1, 1, -1, 0, 1, -1, 1};

int mins[12][12];
vector<string> board, touch;
int main()
{
	int n,m;
	freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
	while(t--)
	{
		cin >> n ;
//		cout << n << endl;
		string tmp;
		board.clear();touch.clear();
		for(int i=0;i<12;i++)for(int j=0;j<12;j++) mins[i][j] = 0;
		for(int i=0;i<n;i++)
		{
			cin >> tmp;
//			cout << tmp << endl;
			board.push_back(tmp);
		}
			for(int i=0;i<n;i++)
		{
			cin >> tmp;
//			cout << tmp << endl;
			touch.push_back(tmp);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j] == '*')
				{
					for(int k=0;k<8;k++)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						if(x >= 0 && x < n && y >= 0 && y < n)
						{
							mins[x][y]++;
						}
					}
				}
			}
		}
    bool minetouch = false;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(touch[i][j] == 'x' && board[i][j] == '*')
          minetouch = true;
        else if(touch[i][j] == '.')
          mins[i][j] = -1;
      }
    }
		for(int i=0;i<n;i++)
        {
            int j=0;
            for(j=0;j<n;j++)
            {
                if(minetouch && board[i][j] == '*')
                printf("*");
                else if(touch[i][j] == 'x')
                    printf("%d", mins[i][j]);
                else
                    cout << '.' ;
            }
            printf("\n");
        }
        if(t) cout << endl;
	}
	return 0;
}
