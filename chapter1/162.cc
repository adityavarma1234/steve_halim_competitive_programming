#include<bits/stdc++.h>

using namespace std;

int card_to_int(string card)
{
    int card_value = 0;
    if(card[0] == 'H')
        card_value = 13;
    else if(card[0] == 'D')
        card_value = 26;
    else if(card[0] == 'C')
        card_value = 39;
    if (card[1] == 'J')
        card_value += 10;
    else if(card[1] == 'Q')
        card_value += 11;
    else if(card[1] == 'K')
        card_value += 12;
    else if(card[1] == 'T')
        card_value += 9;
    else if(card[1] == '2')
        card_value += 1;
    else if(card[1] == '3')
        card_value += 2;
    else if(card[1] == '4')
        card_value += 3;
    else if(card[1] == '5')
        card_value += 4;
    else if(card[1] == '6')
        card_value += 5;
    else if(card[1] == '7')
        card_value += 6;
    else if(card[1] == '8')
        card_value += 7;
    else if(card[1] == '9')
        card_value += 8;
    return card_value;
}

bool high_value_card(int card)
{
    int card_value = card%13;
    if(card_value == 0 || card_value == 10 || card_value == 11 || card_value == 12)
        return true;
    return false;
}

int value_of_high_value_card(int card)
{
    int card_value = card%13;
    if(card_value == 0)
        return 4;
    else if(card_value == 10)
        return 1;
    else if(card_value == 11)
        return 2;
    else if(card_value == 12)
        return 3;
    return -1;
}

deque<int> player, dealer, board;
deque<string> d_player, d_dealer, d_board(4);
int t_hash[52];

int curr_player_turn = 0;
bool game_over = 0;
void push_from_board_to_player()
{
    if(curr_player_turn == 0)
    {
        while(board.size())
        {
            player.push_front(board.front());
            d_player.push_front(d_board.front());
//            cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() << " Board to player " << endl;
            board.pop_front();
            d_board.pop_front();
        }
    }
    else
    {
        while(board.size())
        {
            dealer.push_front(board.front());
            d_dealer.push_front(d_board.front());
//            cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() << " Board to dealer " << endl;
            board.pop_front();
            d_board.pop_front();
        }
    }
}

void handle_high_value(int turn_player, int cnt)
{
    if(curr_player_turn == 1)
    {
        while(cnt--)
        {
            if( dealer.size())
            {
                board.push_back(dealer.back());
                d_board.push_back(d_dealer.back());
//                cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() <<" On board Dealer " << board.back() << endl;
                dealer.pop_back();
                d_dealer.pop_back();
                if(high_value_card(board.back()))
                {
                    curr_player_turn = 0;
//                    cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() << " High Value" << endl;
                    handle_high_value(1, value_of_high_value_card(board.back()));
                    return;
                }
            }
            else
            {
                game_over = 0;
                return;
            }
        }
    }
    if(curr_player_turn == 0)
    {
        while(cnt--)
        {
            if(player.size())
            {
                board.push_back(player.back());
                d_board.push_back(d_player.back());
//                cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() << " On board player " << player.back() << endl;
                player.pop_back();
                d_player.pop_back();
                if(high_value_card(board.back()))
                {
                    curr_player_turn = 1;
//                    cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() << " High value" << endl;
                    handle_high_value(0, value_of_high_value_card(board.back()));
                    return;
                }
            }
            else
            {

                game_over = 1;
                return ;
            }
        }
    }
    if(cnt == -1)
    {
        if(curr_player_turn == 0) curr_player_turn = 1;
        else curr_player_turn = 0;
    }
    push_from_board_to_player();
    return ;
}

void play()
{
    while(1)
    {
        if(curr_player_turn == 0)
        {
            if(player.size())
            {
                board.push_back(player.back());
                d_board.push_back(d_player.back());
//            cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() <<" On Board player " << d_board.back() << endl;
                player.pop_back();
                d_player.pop_back();
                if(high_value_card(board.back()))
                {
                    curr_player_turn = 1;
//                cout  << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() <<" High Value!!" << endl;
                    handle_high_value(0, value_of_high_value_card(board.back()));
                }
                else
                {
                    curr_player_turn = 1;
                }
            }
            else
            {
                game_over = 1;
                return;
            }
        }
        if(curr_player_turn == 1)
        {
            if(dealer.size())
            {
                board.push_back(dealer.back());
                d_board.push_back(d_dealer.back());
//            cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() <<" On board dealer " << dealer.back() << endl;
                dealer.pop_back();
                d_dealer.pop_back();
                if(high_value_card(board.back()))
                {
                    curr_player_turn = 0;
//                cout << "Player size " << player.size() << "Dealer Size "<< dealer.size() << "Board size " << board.size() <<" High Value!!" << endl;
                    handle_high_value(1, value_of_high_value_card(board.back()));
                }
                else
                {
                    curr_player_turn = 0;
                }
            }
            else
            {
                game_over = 0;
                return;
            }
        }
    }
}

bool errorin()
{
    for(int i=0; i<52; i++)
    {
        if(t_hash[i] != 1)
            return true;
    }
    return false;
}
int main()
{
//    freopen("input.txt", "r", stdin); // redirects standard input
//    freopen("output.txt", "w", stdout); // redirects standard output
    bool eoi = false;
    bool flag = false;
    string tmp;
    while(1)
    {
        curr_player_turn = 0;
        player.clear();
        d_player.clear();
        dealer.clear();
        d_dealer.clear();
        board.clear();
        d_board.clear();
        flag = false;
        game_over = 0;
        for(int i=0; i<52; i++)t_hash[i] = 0;
        for(int i=0; i < 4; i++)
        {
            for(int j=0; j < 13; j++)
            {
                cin >> tmp;
                if(tmp == "#")
                {
                    eoi = true;
                    break;
                }
                if(flag)
                {
                    dealer.push_back(card_to_int(tmp));
                    d_dealer.push_back(tmp);
                    t_hash[card_to_int(tmp)]++;
                }
                else
                {
                    player.push_back(card_to_int(tmp));
                    d_player.push_back(tmp);
                    t_hash[card_to_int(tmp)]++;
                }
                flag = !flag;
            }
            if(eoi)
                break;
        }
        if(eoi)
            break;
        if(errorin())
        {
            printf("%d%3d\n", 1, 0);
            continue;
        }
        else if(!errorin())
            play();
        if(game_over)
        {
            printf("%d%3d\n", 1, dealer.size());
        }
        else
        {
            printf("%d%3d\n", 2, player.size());
        }
    }
    return 0;
}
