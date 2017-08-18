#include<bits/stdc++.h>
using namespace std;
map<string, vector< pair< string, string> > >bloodtypeswithalles;
string in,tmp,parent1, parent2, child;
vector<pair<string, string> > p1, p2, ch;
void calcchild()
{
  string x,y;
  pair<string, string> ptmp;
  ch.clear();
  p1.clear();
  p2.clear();
  p1 = bloodtypeswithalles[];
  for(int i=0;i<p1.size();i++)
  {
    for(int j=0; j< p2.size(); j++)
    {
      for(int k=0; k<p1[i].first.size(); k++)
      {
        for(int l=0; l<p2[j].first.size(); l++)
        {
          x = string(1, p1[i]
        }
      }
    }
  }
}
void calcparent()
{
  
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while(getline(cin,in))
  {
    istringstream ss(in);
    bool f=true; int cnt=0;
    whlie(getline(ss, tmp, ' ')
    {
      if(cnt == 0) parent1 = tmp;
      else if(cnt == 1) parent2 = tmp;
      else if(cnt == 2) child = tmp;
      cnt++;
    }
    if(parent1 == "?" || parent2 == "?")
    {
      calcchild();
    }
    else if(child == "?")
    {
      calcparent();
    }
    else
    {
      break;
    }
  } 
  return 0;    
}
