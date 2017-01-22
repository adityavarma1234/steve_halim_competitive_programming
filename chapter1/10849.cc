#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	long long int a,b,c,d;
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n;
		cin >> m;
		while(n--)
		{
			cin >> a >> b >> c>> d;
//			cout << a << b << c << d << endl;
			if((a+b)%2 != (c+d)%2 || c > m || d>m || a>m || b>m)
			{
				cout << "no move" << endl;
			}
			else if(a==c && b == d)
            {
                cout << 0 << endl;
            }
			else if((abs(a-c) == abs(d-b)))
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
		}
//		if(t!=0)cout << endl;
	}
}
