#include<bits/stdc++.h>

using namespace std;
bool pass,fail;
int h[26];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n,cnt=0;
	string ans,gue;
	while(1)
	{
		cin >> n;
		cnt++;
		pass=false;
		fail = false;
		for(int i=0;i<26;i++) h[i] = 0;
		if(n==-1)
			break;
		cin >> ans;
		for(int i=0;i<ans.size();i++)
		{
			h[ans[i]-'a']++;
		}
		cin >> gue;
		int f = 0;
		for(int i=0;i<gue.size();i++)
		{
			if(h[gue[i]-'a'] == 0)
					f++;
			else
			{
				h[gue[i]-'a'] = -1;
			}
			if(f == 7)
			{
				fail = true;
				break;
			}
		}
		cout << "Round " << cnt << endl;
		if(fail)
        {
             cout << "You lose." << endl;
             continue;
        }
		pass = true;
		for(int i=0;i<26;i++)
		{
			if(h[i] != 0 && h[i] != -1)
			{
				pass = false;
				break;
			}
		}
		if(pass) cout << "You win." << endl;
		else cout << "You chickened out." << endl;
	}
	return 0;
}
