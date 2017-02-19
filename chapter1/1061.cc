#include<bits/stdc++.h>
using namespace std;
vector<pair<string, string > >P1, P2, ch;
string in, tmp, parent1, parent2, child;
pair<string, string> p;
map<string, vector< pair<string, string> > > bloodtypeswithalles;
map<string, vector< pair<string, string> > >::iterator itb;
map<string, string> bloodtype;
vector<pair<string,string> > v;
int case1;
void init()
{
  vector<pair<string,string> > tmp = { {"AA", "+-"}, {"AO", "+-"}, {"AO", "-+"}, {"AA", "++"}, {"AO", "++"}};
  bloodtypeswithalles["A+"] = tmp;
  vector<pair<string,string> > t2 = {{ "BB", "+-"}, {"BB", "++"}, {"BO", "+-"}, {"BO", "-+"}, {"BO", "++"}};
  bloodtypeswithalles["B+"] = t2;
  vector<pair<string,string> > t3 = {{"OO", "+-"}, {"OO", "++"}};
  bloodtypeswithalles["O+"] = t3;
  vector<pair<string,string> > t4 = {{"AA", "--"}, { "AO", "--"}};
  bloodtypeswithalles["A-"] = t4;
  vector<pair<string,string> > t5 = {{"BB", "--"}, {"BO", "--"}};
  bloodtypeswithalles["B-"] = t5;
  vector<pair<string,string> > t6 = {{"OO", "--"}};
  bloodtypeswithalles["O-"] = t6;
  vector<pair<string,string> > t7 = { {"AB", "+-"}, {"AB", "-+"}, {"AB", "++"}};
  bloodtypeswithalles["AB+"] = t7;
  vector<pair<string,string> > t8 = {{"AB", "--"}};
  bloodtypeswithalles["AB-"] = t8;
  bloodtype["AA"] = "A";
  bloodtype["AB"] = "AB";
  bloodtype["BA"] = "AB";
  bloodtype["AO"] = "A";
  bloodtype["OA"] = "A";
  bloodtype["BB"] = "B";
  bloodtype["BO"] = "B";
  bloodtype["OB"] = "B";
  bloodtype["OO"] = "O";
}
bool ispositive(string x)
{
  if(x[0] == '-' && x[1] == '-') return false;
  return true;
}
string getbloodtype(pair<string, string> p)
{
//  cout << " blood " << p.first << endl;
  if(ispositive(p.second))
    return bloodtype[p.first] + "+";
  else
    return bloodtype[p.first] + "-";
}
void calcparent()
{
 string parent;
 if(parent1 == "?")
   parent = parent2;
 else
   parent = parent1;
 ch.clear();P1.clear();P2.clear();
 set<string>::iterator it;
 set<string> anschild;
 bool f=true;
 for(itb = bloodtypeswithalles.begin(); itb != bloodtypeswithalles.end(); itb++)
 {
  f = false;
  P1 = itb->second;
  P2 = bloodtypeswithalles[parent];
  string x,y;
  for(int i=0;i<P1.size();i++)
  {
    for(int j=0;j<P2.size(); j++)
    {
      for(int k=0;k<P1[i].first.size(); k++)
      {
        for(int l=0;l<P2[j].first.size(); l++)
        {
//          cout << P1[i].first << " " << P1[i].second << endl;
//          cout << P2[j].first << " " << P2[j].second << endl;
          // blood
          x = "";
          x.push_back(P1[i].first[k]);
          x.push_back(P2[j].first[l]);
          // allele
          y = "";
          y.push_back(P1[i].second[k]);
          y.push_back(P2[j].second[l]);
//          cout << x << " x y " << y << endl;
          if(getbloodtype(make_pair(x,y)) == child)
          {
//            cout << "match " << itb->first << endl;
            anschild.insert(itb->first);
            f = true;
            break;
          }
        }
        if(f) break;
      }
      if(f) break;
    }
    if(f) break;
  }
 }
  if(anschild.size() == 0)
  {
    if(parent1=="?") parent1 = "IMPOSSIBLE";
    if(parent2=="?") parent2 = "IMPOSSIBLE";
    printf("Case %d: %s %s %s\n", case1, parent1.c_str(), parent2.c_str() ,child.c_str());
  }
  else if(anschild.size() == 1)
  {
    if(parent1=="?") parent1 = *anschild.begin();
    if(parent2=="?") parent2 = *anschild.begin();
    printf("Case %d: %s %s %s\n", case1, parent1.c_str(), parent2.c_str() ,child.c_str());
  }
  else
  {
    if(parent1 == "?")
    {
      cout << "Case " << case1 << ": " << "{";
      for(it = anschild.begin() ; it != anschild.end() ; it++)
      {
        if(it != anschild.begin()) cout << ", " ;
        cout << *it;
      }
      cout << "} " ;
      cout << parent2 << " " << child << endl;
    }
    if(parent2 == "?")
    {
      cout << "Case " << case1 << ": " << parent1 << " " <<  "{";
      for(it = anschild.begin() ; it != anschild.end() ; it++)
      {
        if(it != anschild.begin()) cout << ", " ;
        cout << *it;
      }
      cout << "} " ;
      cout <<  child << endl;
    }
  }

}
void calchild()
{
  ch.clear();P1.clear();P2.clear();
  P1 = bloodtypeswithalles[parent1];
  P2 = bloodtypeswithalles[parent2];
  string x,y;
  for(int i=0;i<P1.size();i++)
  {
    for(int j=0;j < P2.size(); j++)
    {
      for(int k=0; k<P1[i].first.size(); k++)
      {
        for(int l=0;l<P2[j].first.size(); l++)
        {
           // cout << P1[i].first << " " << P1[i].second << endl;
          // cout << P2[j].first << " " << P2[j].second << endl;
          // blood
          x = "";
          x.push_back(P1[i].first[k]);
          x.push_back(P2[j].first[l]);
          // allele
          y = "";
          y.push_back(P1[i].second[k]);
          y.push_back(P2[j].second[l]);
           // cout << x << " x y " << y << endl;
          ch.push_back(make_pair(x,y));
        }
      }
    }
  }
  set<string> anschild;
  set<string>::iterator it;
  for(int i=0;i<ch.size();i++)
  {
    anschild.insert(getbloodtype(ch[i]));
  }
  if(anschild.size() == 0)
  {
  cout << "Case " << case1 << ": " << parent1 << " " << parent2 << " " << "IMPOSSIBLE" << endl;
  }
  else if(anschild.size() == 1)
  {
    cout << "Case " << case1 << ": " << parent1 << " " << parent2 << " " << *anschild.begin() << endl;
  }
  else
  {
    cout << "Case " << case1 << ": " << parent1 << " " << parent2 << " " << "{";
    for(it = anschild.begin() ; it != anschild.end() ; it++)
    {
      if(it != anschild.begin()) cout << ", " ;
      cout << *it;
    }
    cout << "}" << endl;
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  case1 = 0;
  init();
  while(getline(cin,in))
  {
//    cout << in << endl;
    case1++;
    istringstream ss(in);
    bool f = true;
    int cnt = 0;
    while(ss >> tmp)
    {
      if(cnt == 0) parent1 = tmp;
      else if(cnt == 1) parent2 = tmp;
      else if(cnt == 2) child = tmp;
      cnt++;
    }
//    cout << parent1 << parent2 << child << endl;
    if(parent1=="E" && parent2 == "N" && child == "D") break;
    if(parent1 == "?" || parent2 == "?")
      calcparent();
    else
      calchild();
  }

  return 0;
}
