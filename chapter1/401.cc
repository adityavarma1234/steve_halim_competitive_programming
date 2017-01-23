#include<bits/stdc++.h>

using namespace std;
string in;
int rev[255];
void init()
{
	rev[65] = 65;
	rev[69] = 51;
	rev[51] = 69;
	rev[72] = 72;
	rev[73] = 73;
	rev[74] = 76;
	rev[76] = 74;
	rev[77] = 77;
	rev[79] = 79;
	rev[83] = 50;
	rev[50] = 83;
	rev[84] = 84;
	rev[85] = 85;
	rev[86] = 86;
	rev[87] = 87;
	rev[88] = 88;
	rev[89] = 89;
	rev[90] = 53;
	rev[53] = 90;
	rev[49] = 49;
	rev[56] = 56;
}

bool ispalindrome()
{
	int start = 0, end1 = in.size()-1;
	bool f = true;
	while(start < end1)
	{
		if(in[start] != in[end1])
		{
			f = false;
			break;
		}
		start++;
		end1--;
	}
	if(f) return true;
	return false;
}
string mir;
bool ismirror()
{
	mir = "";
	bool cons=false;
	for(int i=0;i<in.size();i++)
	{
		if(rev[in[i]])
		{
			mir += string(1,rev[in[i]]);
            cons = true;
		}
		else
			mir += string(1, ' ');
	}
	if(!cons) return false;
	int len = in.size()-1;
	bool f =true;
	for(int i=0;i<in.size();i++)
	{
		if(in[i] != mir[len])
		{
			f =false;
			break;
		}
		len--;
	}
	if(f) return true;
	else return false;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	init();
	int cnt=0;
	while(getline(cin, in))
	{
		if(!ispalindrome() && !ismirror())
		{
			cout << in << " -- " << "is not a palindrome." << endl;
		}
		else if(ispalindrome() && !ismirror())
		{
			cout << in << " -- " << "is a regular palindrome." << endl;
		}
		else if(!ispalindrome() && ismirror())
		{
			cout << in << " -- " << "is a mirrored string." << endl;
		}
		else if(ispalindrome() && ismirror())
		{
			cout << in << " -- " << "is a mirrored palindrome." << endl;
		}
            cout << endl;
	}
	return 0;
}
