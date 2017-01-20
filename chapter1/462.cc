#include<bits/stdc++.h>

using namespace std;
vector<string> scards, hcards, dcards, ccards;
int res = 0;

bool high_value(string card)
{
	char a = card[0];
	if(a == 'A' || a == 'J' || a == 'Q' || a == 'K')
	{
		return true;
	}
	return false;
}

int value_cards(string card)
{
	char a = card[0];
	if(a == 'A')
		return 4;
	if(a == 'K')
		return 3;
	if(a == 'Q')
		return 2;
	if(a == 'J')
		return 1;
	return 0;
}

void rule1()
{
	for(int i=0;i<scards.size();i++)
	{
		if(high_value(scards[i]))
		{
			res += value_cards(scards[i]);
		}
	}
	for(int i=0;i<hcards.size();i++)
	{
		if(high_value(hcards[i]))
		{
			res += value_cards(hcards[i]);
		}
	}
	for(int i=0;i<ccards.size();i++)
	{
		if(high_value(ccards[i]))
		{
			res += value_cards(ccards[i]);
		}
	}
	for(int i=0;i<dcards.size();i++)
	{
		if(high_value(dcards[i]))
		{
			res += value_cards(dcards[i]);
		}
	}

}

bool has_king_card(vector<string> cards)
{
	for(int i=0;i<cards.size();i++)
	{
		if(cards[i][0] == 'K')
				return true;
	}
	return false;
}
bool has_queen_card(vector<string> cards)
{
	for(int i=0;i<cards.size();i++)
	{
		if(cards[i][0] == 'Q')
				return true;
	}
	return false;
}
bool has_jack_card(vector<string> cards)
{
	for(int i=0;i<cards.size();i++)
	{
		if(cards[i][0] == 'J')
				return true;
	}
	return false;
}
bool has_ace_card(vector<string> cards)
{
	for(int i=0;i<cards.size();i++)
	{
		if(cards[i][0] == 'A')
				return true;
	}
	return false;
}
void rule2()
{
	if(has_king_card(scards) && scards.size() == 1)
		res--;
	if(has_king_card(hcards) && hcards.size() == 1)
		res--;
	if(has_king_card(dcards) && dcards.size() == 1)
		res--;
	if(has_king_card(ccards) && ccards.size() == 1)
		res--;
}
void rule3()
{
	if(scards.size() < 3 && has_queen_card(scards))
		res--;
	if(hcards.size() < 3 && has_queen_card(hcards))
		res--;
	if(dcards.size() < 3 && has_queen_card(dcards))
		res--;
	if(ccards.size() < 3 && has_queen_card(ccards))
		res--;
}
void rule4()
{
	if(scards.size() < 4 && has_jack_card(scards))
		res--;
	if(hcards.size() < 4 && has_jack_card(hcards))
		res--;
	if(dcards.size() < 4 && has_jack_card(dcards))
		res--;
	if(ccards.size() < 4 && has_jack_card(ccards))
		res--;
}
bool trump_helper(vector<string> cards)
{
	if(has_ace_card(cards))
		 return true;
	if(cards.size() > 1 && has_king_card(cards))
		return true;
	if(cards.size() > 2 && has_queen_card(cards))
		return true;
	return false;
}
bool trumpPossible()
{
    if(trump_helper(scards) && trump_helper(hcards) && trump_helper(dcards) && trump_helper(ccards))
        return true;
    return false;
}
void rule6()
{
	if(scards.size() == 1) res += 2;
	if(dcards.size() == 1) res += 2;
	if(hcards.size() == 1) res += 2;
	if(ccards.size() == 1) res += 2;
}
void rule5()
{
	if(scards.size() == 2) res += 1;
	if(dcards.size() == 2) res += 1;
	if(hcards.size() == 2) res += 1;
	if(ccards.size() == 2) res += 1;
}
void rule7()
{
	if(scards.size() == 0) res += 2;
	if(dcards.size() == 0) res += 2;
	if(hcards.size() == 0) res += 2;
	if(ccards.size() == 0) res += 2;
}
void getInput(string tmp)
{
	for(int i=0;i<tmp.size();i++)
	{
		while(tmp[i] ==' ')i++;
		if(tmp[i+1] == 'S')
		{
			scards.push_back(string(1, tmp[i]) +string(1, tmp[i+1]));
		}
		else if(tmp[i+1] == 'H')
		{
			hcards.push_back(string(1, tmp[i]) +string(1, tmp[i+1]));
		}
		else if(tmp[i+1] == 'D')
		{
			dcards.push_back(string(1, tmp[i]) +string(1, tmp[i+1]));
		}
		else if(tmp[i+1] == 'C')
		{
			ccards.push_back(string(1, tmp[i]) +string(1, tmp[i+1]));
		}
	}
}

void clearData()
{
	scards.clear();
	hcards.clear();
	dcards.clear();
	ccards.clear();
	res = 0;
}
char fetchMaxSuit()
{
	int max_size = max(max(scards.size(), dcards.size()), max(ccards.size(), hcards.size()));
	if(scards.size() == max_size) return 'S';
	if(hcards.size() == max_size) return 'H';
	if(dcards.size() == max_size) return 'D';
	if(ccards.size() == max_size) return 'C';

}
int main()
{
    freopen("input.txt", "r", stdin); // redirects standard input
freopen("output.txt", "w", stdout); // redirects standard output
	string tmp;
	while(getline(cin, tmp))
	{
		clearData();
		getInput(tmp);
		rule1();
//		cout << res << " ";
		rule2();
//        cout << res << " ";
		rule3();
//		cout << res << " ";
		rule4();
//		cout << res << " ";
		if(trumpPossible() && res > 15)
		{
			cout << "BID NO-TRUMP" << endl;
			continue;
		}
		rule5();
//		cout << res << " ";
		rule6();
//		cout << res << " ";
		rule7();
//		cout << res << " " ;
		if(res < 14)
		{
			cout << "PASS" << endl;
			continue;
		}
		cout << "BID " << fetchMaxSuit() << endl;
	}
	return 0;
}
