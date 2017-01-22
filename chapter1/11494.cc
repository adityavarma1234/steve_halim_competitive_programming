#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	int a=1, b=1, c=1, d=1;
	while(1)
	{
		cin >> a >> b >> c >> d;
		if(a==0 && b==0 && c==0 && d==0)
		{
			break;
		}
		if(a==c && b==d)
		{
			cout << 0 << endl;
		}
		else if(abs(a-c) == abs(d-b))
		{
			cout << 1 << endl;
		}
		else if(a==c || b==d)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
}
