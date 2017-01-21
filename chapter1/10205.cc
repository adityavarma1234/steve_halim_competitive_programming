#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >shuffles(100);

vector<int> cases;

int tmp_deck[52], deck[52];

void init_data()
{
	cases.clear();
	for(int i=0;i<100;i++)
	{
		shuffles[i].clear();
	}
	for(int i=0;i<52;i++)
	{
		deck[i] = i;
	}
}
void get_shuffles(int cnt)
{
	int shuffles_index = 0;
	bool flag = true;
	for(int i=0; i< cnt ; i++)
	{
	    if(i==52) flag = false;
		if(i%52 == 0 && !flag)
			{
			    shuffles_index++;
//                cout << endl;
			}
		int tmp;
		cin >> tmp;
		tmp--;
		shuffles[shuffles_index].push_back(tmp);
//		cout << tmp << " ";
	}
//	cout << endl;
}
void get_cases()
{
	string num;
	getline(cin,num);
	while(getline(cin, num) && num != "")
	{
		int val = atoi(num.c_str());
		val--;
		cases.push_back(val);
	}
}
void apply_case(int shuffles_index)
{
	int tmp_pos[52];
	for(int i=0;i<52;i++)
	{
		tmp_pos[i] = deck[shuffles[shuffles_index][i]];
	}
	for(int i=0; i< 52; i++)
	{
		deck[i] = tmp_pos[i];
	}
}
string get_club(int card)
{
	switch(card/13)
	{
		case 0:
				return "Clubs";
		case 1:
				return "Diamonds";
		case 2:
				return "Hearts";
		case 3:
				return "Spades";
	}
}
string get_value(int card)
{
	switch(card%13)
	{
		case 0:
				return "2";
		case 1:
				return "3";
		case 2:
				return "4";
		case 3:
				return "5";
		case 4:
				return "6";
		case 5:
				return "7";
		case 6:
				return "8";
		case 7:
				return "9";
		case 8:
				return "10";
		case 9:
				return "Jack";
		case 10:
				return "Queen";
		case 11:
				return "King";
		case 12:
			return "Ace";
	}
}
string value_of(int card)
{
	string club = get_club(card);
	string value = get_value(card);
 	return value + " of " + club;
}
void print_cards()
{
	for(int i =0 ;i<52; i++)
	{
		cout << value_of(deck[i]) << endl;
	}
}
int main()
{
	int t;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	string tmp;
	getline(cin, tmp);
	int cnt = 0;
	while(t--)
	{
		init_data();
		int n;
		if(cnt) cout << endl;
		cnt++;
		cin >> n;
		get_shuffles(52*n);
		get_cases();
		for(int i=0;i<cases.size();i++)
		{
//		    cout << cases[i] << " ";
			 apply_case(cases[i]);
		}
//		cout << endl;
		print_cards();
	}
}
