#include<bits/stdc++.h>

using namespace std;
int y;
vector<string> stop;
stack<string> ftop, ptop;
void clear_data()
{
	while(!ftop.empty()) {
        ftop.pop();
	}
	while(!ptop.empty()){
        ptop.pop();
	}
	stop.clear();
	y = 0;
}
void fetch_input()
{
	int i =0;
	string tmp;
	for(i=0;i<27;i++)
	{
		cin >> tmp;
		ftop.push(tmp);
	}
	for(i=0;i<25;i++)
	{
		cin >> tmp;
		stop.push_back(tmp);
	}
}
int get_val(string card)
{
	switch(card[0])
	{
		case 'A':
				return 10;
		case 'J':
				return 10;
		case 'Q':
				return 10;
		case 'K':
				return 10;
        case 'T':
                return 10;
		default:
				return card[0] - '0';
	}
}
void play()
{
	y = 0;
	int x = 0;
	while(!ftop.empty())
	{
		x = get_val(ftop.top());
		ptop.push(ftop.top());
		ftop.pop();
		y += x;
		int rm=10-x;
		while(rm-- && !ftop.empty()) {
            ptop.push(ftop.top());
            ftop.pop();
		}
	}
	for(int i=0;i<25;i++)
    {
        ptop.push(stop[i]);
    }
}
int case_num = 0;
void print_ans()
{
	case_num++;
	printf("Case %d: ", case_num);
	cout << y << endl;
	while(ptop.size() > y) ptop.pop();
	cout << ptop.top() << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		clear_data();
		fetch_input();
		play();
		print_ans();
	}
	return 0;
}
