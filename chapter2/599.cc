#include<iostream>
#include<vector>
#include<cstdio>
#include<string>

using namespace std;

vector<vector<int> > graph;
bool seen[26], present[26];
int acorns, trees;

void init()
{
  acorns = 0;
  trees = 0;
  graph.clear();
  graph.resize(26, vector<int> (0));
  for(int i=0;i<26;i++)
  {
    seen[i] = false;
    present[i] = false;
  }
}

void findAcorns()
{
  for(int i=0;i<26;i++)
  {
    if(present[i] && graph[i].empty())
    {
      seen[i] = true;
      acorns++;
    }
  }
}

void dfs(int x)
{
  if(seen[x]) return;
  seen[x] = true;
  for(int i=0; i<(int)graph[x].size(); i++)
  {
    int y = graph[x][i];
    if(!seen[y])
    {
      dfs(y);
    }
  }
  return;
}

void calculateTreesAndAcorns()
{
  findAcorns();
  for(int i=0; i<26; i++)
  {
    if(!seen[i] && present[i])
    {
      trees++;
      dfs(i);
    }
  }
  cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
}

int main()
{
  int t;
  cin >> t;
  string edge_string;
  getline(cin, edge_string);
  while(t--)
  {
    init();
    getline(cin, edge_string);
    while(edge_string[0] == '(')
    {
      int u = edge_string[1] - 'A';
      int v = edge_string[3] - 'A';

      graph[u].push_back(v);
      graph[v].push_back(u);

      present[u] = true;
      present[v] = true;
        
      getline(cin, edge_string);
    }
  getline(cin, edge_string);
  for(int i=0;i<edge_string.size();i+=2)
   {
        int u = edge_string[i] - 'A';
        present[u] = true;
   }
  calculateTreesAndAcorns();
  }
  return 0;
}
