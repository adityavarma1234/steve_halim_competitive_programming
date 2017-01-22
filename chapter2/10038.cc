#include<bits/stdc++.h>

using namespace std;

vector<int> diff;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	int n;
	diff.clear();
	while(cin >> n)
	{
        diff.clear();
//		cout << n << endl;
		for(int i=0;i<n;i++)
		{
			int m;
			cin >> m;
//			cout << m << endl;
			diff.push_back(m);
		}
		vector<int> diff1;
		diff1.clear();
		for(int i=0;i<n-1;i++)
		{
			diff1.push_back(abs(diff[i+1]-diff[i]));
		}
		sort(diff1.begin(), diff1.end());
		bool flag = true;
		for(int i=1;i<n;i++)
		{
			if(diff1[i-1] != i)
			{
				flag = false;
				break;
			}
		}
		if(flag) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}
