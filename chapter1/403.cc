#include<bits/stdc++.h>
using namespace std;
#define pb push_back
char out[62][62];
string in,op,val,font;
int r,c;
map<char, vector<string> > m;
vector<string> tmp;
void init()
{
  int i,j;
  for(i=0;i<62;i++)
    for(j=0;j<62;j++)
      out[i][j] = '.';
}
void initc5()
{

  m['A'] = {".***..",
            "*...*.",
            "*****.",
            "*...*.",
            "*...*."};

  m['B'] = { "****..",
             "*...*.",
             "****..",
             "*...*.",
             "****.." };

  m['C'] = { ".****.",
             "*...*.",
             "*.....",
             "*.....",
             ".****." };

  m['D'] = { "****..",
             "*...*.",
             "*...*.",
             "*...*.",
             "****.."};

  m['E'] = { "*****.",
             "*.....",
             "***...",
             "*.....",
             "*****." };

  m['F'] = { "*****.",
             "*.....",
             "***...",
             "*.....",
             "*....." };

  m['G'] = { ".****.",
             "*.....",
             "*..**.",
             "*...*.",
             ".***.." };

  m['H'] = { "*...*.",
             "*...*.",
             "*****.",
             "*...*.",
             "*...*."};

  m['I'] = { "*****.",
             "..*...",
             "..*...",
             "..*...",
             "*****." };

  m['J'] = { "..***.",
             "...*..",
             "...*..",
             "*..*..",
             ".**..." };

  m['K'] = { "*...*.",
             "*..*..",
             "***...",
             "*..*..",
             "*...*." };

  m['L'] = { "*.....",
             "*.....",
             "*.....",
             "*.....",
             "*****." };

  m['M'] = { "*...*.",
             "**.**.",
             "*.*.*.",
             "*...*.",
             "*...*." };

  m['N'] = { "*...*.",
             "**..*.",
             "*.*.*.",
             "*..**.",
             "*...*." };

  m['O'] = { ".***..",
             "*...*.",
             "*...*.",
             "*...*.",
             ".***.." };

  m['P'] = { "****..",
             "*...*.",
             "****..",
             "*.....",
             "*....." };

  m['Q'] = { ".***..",
             "*...*.",
             "*...*.",
             "*..**.",
             ".****." };

  m['R'] = { "****..",
             "*...*.",
             "****..",
             "*..*..",
             "*...*." };

  m['S'] = {".****.",
             "*.....",
             ".***..",
             "....*.",
             "****.." };

 m['T'] = {"*****.",
           "*.*.*.",
           "..*...",
           "..*...",
           ".***.." };

 m['U'] = {"*...*.",
           "*...*.",
           "*...*.",
           "*...*.",
           ".***.." };

 m['V'] = {"*...*.",
           "*...*.",
           ".*.*..",
           ".*.*..",
           "..*..." };

 m['W'] = {"*...*.",
           "*...*.",
           "*.*.*.",
           "**.**.",
           "*...*." };

 m['X'] = {"*...*.",
           ".*.*..",
           "..*...",
           ".*.*..",
           "*...*." };

 m['Y'] = {"*...*.",
           ".*.*..",
           "..*...",
           "..*...",
           "..*..." };

 m['Z'] = {"*****.",
           "...*..",
           "..*...",
           ".*....",
           "*****." };

 m[' '] = {"......",
           "......",
           "......",
           "......",
           "......" };

}
int min(int a, int b)
{
  return a < b ? a : b;
}
void pc1()
{
  for(int i=c,j=0 ; i<min(61,c+val.size()) ; i++,j++)
  {
    if(val[j] == ' ' ) continue;
    out[r][i] = val[j];
  }
}
void lc1()
{
  for(int i=1,j=0; i<min(61,val.size()+1);i++,j++)
  {
    if(val[j] == ' ' ) continue;
    out[r][i] = val[j];
  }
}
void rc1()
{
  for(int i=60,j=val.size()-1; i>=0 && j >=0; i--,j--)
  {
    if(val[j] == ' ' ) continue;
    out[r][i] = val[j];
  }
}
void cc1()
{
  int mid = val.size()/2;
  for(int i=31,j=mid;i<61 && j<val.size();i++,j++)
  {
    if(val[j] == ' ' ) continue;
    out[r][i] = val[j];
  }
  for(int i=30,j=mid-1; i>=0 && j>=0; i--,j--)
  {
    if(val[j] == ' ' ) continue;
    out[r][i] = val[j];
  }
}
void printc5(int r, int c, char a)
{
  if(a==' ') return;
  if(m.find(a) == m.end()) return;
  int i,j,k,l;
  k=0,l=0;
  vector<string> v = m[a];
  for(i=0;i<5;i++)
  {
    for(j=0;j<6;j++)
    {
//      cout << v[i][j] << " ";
      if(i+r>0 && i+r < 61 && j+c > 0 && j+c < 61 && v[i][j] == '*')
      out[i+r][j+c] = v[i][j];
    }
//    cout << endl;
  }
}
void pc5()
{
  for(int j=0;j<val.size();j++)
  {
    printc5(r, c, val[j]);
    c += 6;
  }
}
void lc5()
{
  for(int j=0;j<val.size();j++)
  {
    printc5(r, c, val[j]);
    c += 6;
  }
}
void rc5()
{
  for(int j=val.size()-1;j>=0;j--)
  {
    printc5(r, c-5, val[j]) ;
    c = c-6;
  }
}
void cc5()
{
  int mid = val.size()/2,x;
  if(val.size()%2) x = 28;
  else x = 31;
  for(int i=x,j=mid; j<val.size();i+=6,j++)
  {
    printc5(r, i, val[j]) ;
  }
  for(int i=x-6, j=mid-1; j >=0 ;i-=6,j--)
  {
    printc5(r, i, val[j]);
  }
}
void output()
{
  int i,j;
  for(i=1;i<61;i++)
  {
    for(j=1;j<61;j++)
    {
      cout << out[i][j] ;
    }
    cout << endl;
  }
  cout << endl;
  for(i=1;i<61;i++)cout << "-";
  cout << endl;
  cout << endl;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  initc5();
  while(getline(cin,in) && in!="")
  {
    if(in == ".EOP")
    {
        output();
        init();
        continue;
    }
    val = "";
    istringstream ss(in);
    string tmp;
    ss>>op;
    if(op == ".P")
    {
      ss >> font;
      ss >> r;
      ss >> c;
//      while(ss>>tmp)
//      {
//        if(!val.empty()) val += " ";
//        val += tmp;
//      }
      getline(ss, val);
      val = val.substr(2,val.size()-3);
//      cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
        pc1();
      else pc5();
    }
    else if(op == ".L")
    {
      ss >> font;
      ss >> r;
      c = 1;
//      while(ss>>tmp)
//      {
//        if(!val.empty()) val += " ";
//        val += tmp;
//      }
      getline(ss, val);
      val = val.substr(2,val.size()-3);
//      cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
      {
        lc1();
      }
      else lc5();
    }
    else if(op == ".R")
    {
      ss >> font;
      ss >> r;
      c = 60;
//      while(ss>>tmp)
//      {
//        if(!val.empty()) val += " ";
//        val += tmp;
//      }
      getline(ss, val);
      val = val.substr(2,val.size()-3);
//      cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
      {
        rc1();
      }
      else rc5();
    }
    else if(op == ".C")
    {
      ss >> font;
      ss >> r;
      c = 60;
//      while(ss>>tmp)
//      {
//        if(!val.empty()) val += " ";
//        val += tmp;
//      }
      getline(ss, val);
      val = val.substr(2,val.size()-3);
//      cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
      {
        cc1();
      }
      else cc5();
    }
  }
  return 0;
}
