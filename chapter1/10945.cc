#include<bits/stdc++.h>

using namespace std;

int main()
{
	string res="";
	string in;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(1)
	{
		getline(cin , in);
		res.clear();
		if(in == "DONE")
			break;
		for(int i=0;i<in.size();i++)
		{
			while(i< in.size() && (in[i] == ' ' || in[i] == '.' || in[i] == ',' || in[i] == '!' || in[i] == '?'))
			{
				i++;
			}
			if(i<in.size() && (in[i]>='a' && in[i]<='z'))
			{
				res += string(1, in[i]);
			}
			if(i<in.size() && (in[i] >='A' && in[i] <='Z'))
			{
				res += string(1, in[i]-'A'+'a');
			}
		}
//		cout << res << endl;
		bool f=true;
		int start =0,end1=res.size()-1;
//		cout << start << " " << end1 << endl;
		while(start<end1)
		{
			if(res[start] != res[end1])
			{
				f = false;
				break;
			}
			start++;
			end1--;
		}
		if(f)
						cout << "You won't be eaten!\n";
		else
						cout << "Uh oh..\n";
	}
	return 0;
}
