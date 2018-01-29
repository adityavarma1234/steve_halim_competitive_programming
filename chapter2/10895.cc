//
//  main.cpp
//  10895 uva
//
//  Created by Aditya  Varma on 29/01/18.
//  Copyright © 2018 Aditya  Varma. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > >graph;
vector<pair<int, int> > tmp_pairs;
pair<int, int> p, q;

int main() {
    int m,n;
    freopen("/Users/adityavarma/Documents/workspace/steve_halim_competitive_programming/chapter2/input.txt", "r", stdin);
    freopen("/Users/adityavarma/Documents/workspace/steve_halim_competitive_programming/chapter2/output.txt", "w", stdout);

    while(cin >> m >> n)
    {
        graph.clear();
        graph.resize(n, vector<pair<int,int> > (0));
      for(int row=0; row<m; row++)
      {
        int r;
        cin >> r;
        if(r != 0)
        {
          tmp_pairs.clear();
          for(int i=0; i<r; i++)
          {
            int tmp;
            cin >> tmp;
            p.first = tmp-1;
            p.second = 0;
            tmp_pairs.push_back(p);
          }
          for(int i=0; i<r; i++)
          {
            int tmp;
            cin >> tmp;
            tmp_pairs[i].second = tmp;
          }
          for(int i=0; i<r; i++)
          {
            p = tmp_pairs[i];
            q.first = row;
            q.second = p.second;
            graph[p.first].push_back(q);
          }
        }
      }
      cout << n << " " << m << endl;
      for(int i=0; i<n; i++)
      {
        cout << graph[i].size();
          if(!graph[i].empty())
        for(int j=0; j<graph[i].size() - 1; j++)
        {
          cout <<  " " << graph[i][j].first + 1;
        }
          if(!graph[i].empty())  cout << " " << graph[i][graph[i].size()-1].first + 1 ;
          cout << endl;
          if(!graph[i].empty())
        for(int j=0; j<graph[i].size()-1; j++)
        {
          cout <<  graph[i][j].second << " ";
        }
          if(!graph[i].empty())  cout << graph[i][graph[i].size()-1].second ;
        cout << endl;
      }
    }
    return 0;
}
