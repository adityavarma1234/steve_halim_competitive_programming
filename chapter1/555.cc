#include<bits/stdc++.h>

using namespace std;
vector<vector<int> >v(4);

int convert_card_to_int(string card)
{
    int card_num = 0;
    char club, suit_num;
    club = card[0];
    suit_num = card[1];
    switch(club)
    {
    case 'C':
        card_num = 0;
        break;
    case 'D':
        card_num = 13;
        break;
    case 'S':
        card_num = 26;
        break;
    case 'H':
        card_num = 39;
        break;
    }
    switch(suit_num)
    {
    case '2':
        card_num += 0;
        break;
    case '3':
        card_num += 1;
        break;
    case '4':
        card_num += 2;
        break;
    case '5':
        card_num += 3;
        break;
    case '6':
        card_num += 4;
        break;
    case '7':
        card_num += 5;
        break;
    case '8':
        card_num += 6;
        break;
    case '9':
        card_num += 7;
        break;
    case 'T':
        card_num += 8;
        break;
    case 'J':
        card_num += 9;
        break;
    case 'Q':
        card_num += 10;
        break;
    case 'K':
        card_num += 11;
        break;
    case 'A':
        card_num += 12;
    }
    return card_num;
}

string get_value_card(int card)
{
    switch(card)
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
        return "T";
    case 9:
        return "J";
    case 10:
        return "Q";
    case 11:
        return "K";
    case 12:
        return "A";
    }
}

string convert_card_to_string(int card)
{
    string club_card_num = "";
    int club = card/13;
    switch(club)
    {
    case 0:
        club_card_num += "C";
        break;
    case 1:
        club_card_num += "D";
        break;
    case 2:
        club_card_num += "S";
        break;
    case 3:
        club_card_num += "H";
    }
    club_card_num += get_value_card(card%13);
    return club_card_num;
}
void handle_input(string tmp, int dealer)
{
    int cnt = 0;
    for(int i =0 ; i< tmp.size() ; i++)
    {
        if(cnt%4 == 0)
        {
            v[(dealer + 1)%4].push_back(convert_card_to_int(string(1,tmp[i]) + string(1, tmp[i+1])));
            cnt++;
            i++;
        }
        else if(cnt%4 == 1)
        {
            v[(dealer + 2)%4].push_back(convert_card_to_int(string(1, tmp[i])+ string(1, tmp[i+1])));
            cnt++;
            i++;
        }
        else if(cnt%4 == 2)
        {
            v[(dealer + 3)%4].push_back(convert_card_to_int(string(1, tmp[i])+ string(1, tmp[i+1])));
            cnt++;
            i++;
        }
        else if(cnt%4 == 3)
        {
            v[(dealer + 4)%4].push_back(convert_card_to_int(string(1, tmp[i]) + string(1, tmp[i+1])));
            cnt++;
            i++;
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string tmp;
    char d;
    while(1)
    {
        cin >> d;
        if(d == '#')
            break;
        for(int i=0; i<4; i++) v[i].clear();
        cin >> tmp;
        int dealer = 0;
        switch(d)
        {
        case 'S':
            dealer = 0;
            break;
        case 'W':
            dealer = 1;
            break;
        case 'N':
            dealer = 2;
            break;
        case 'E':
            dealer = 3;
        }
        handle_input(tmp, dealer);
        cin >> tmp;
        handle_input(tmp, dealer+2);
        for(int i =0; i<4; i++)
        {
            sort(v[i].begin(), v[i].end());
        }
        for(int i=0; i < 4; i++)
        {
            if(i==0)
            {
                cout << "S: ";
            }
            if(i == 1)
            {
                cout << "W: ";
            }
            if(i == 2)
            {
                cout << "N: ";
            }
            if(i == 3)
            {
                cout << "E: ";
            }
            for(int j = 0; j< v[i].size() - 1; j++)
            {
                cout << convert_card_to_string(v[i][j]) << " ";
            }
            cout << convert_card_to_string(v[i][v[i].size() - 1 ] );
            cout << endl;
        }
    }
    return 0;
}
