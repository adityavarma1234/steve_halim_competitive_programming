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
    if(val[j] != ' ')
    out[r][i] = val[j];
  }
}
void lc1()
{
  for(int i=1,j=0; i<min(61,val.size());i++,j++)
  {
    if(val[j] != ' ')
    out[r][i] = val[j]; 
  }
}
void rc1()
{
  for(int i=60,j=val.size()-1; i>=0 && j >=0; i--,j--)
  {
    if(val[j] != ' ')
    out[r][i] = val[j]; 
  }
}
void cc1()
{
  int mid = val.size()/2;
  for(int i=31,j=mid;i<61 && j<val.size();i++,j++)
  {
    if(val[j] != ' ')
    out[r][i] = val[j]; 
  }
  for(int i=30,j=mid-1; i>=0 && j>=0; i--,j--)
  {
    if(val[j] != ' ')
    out[r][i] = val[j]; 
  }
}
void pc5()
{}
void lc5()
{}
void rc5()
{}
void cc5()
{}
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
  for(i=1;i<61;i++)cout << "-";
  cout << endl;
  cout << endl;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  while(getline(cin,in) && in != ".EOP")
  {
    val = "";
    istringstream ss(in);
    string tmp;
    ss>>op;
    if(op == ".P")
    {
      ss >> font; 
      ss >> r;
      ss >> c;
      while(ss>>tmp)
      {
        if(!val.empty()) val += " ";
        val += tmp;
      }
      val = val.substr(1,val.size()-2);
      //cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
        pc1();
    }
    else if(op == ".L")
    {
      ss >> font;
      ss >> r;
      c = 1;
      while(ss>>tmp)
      {
        if(!val.empty()) val += " ";
        val += tmp;
      }
      val = val.substr(1,val.size()-2);
      //cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
      {
        lc1();
      }
    }
    else if(op == ".R")
    {
      ss >> font;
      ss >> r;
      c = 60;
      while(ss>>tmp)
      {
        if(!val.empty()) val += " ";
        val += tmp;
      }
      val = val.substr(1,val.size()-2);
      //cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
      {
        rc1();
      }
    }
    else if(op == ".C")
    {
      ss >> font;
      ss >> r;
      c = 60;
      while(ss>>tmp)
      {
        if(!val.empty()) val += " ";
        val += tmp;
      }
      val = val.substr(1,val.size()-2);
      //cout << op << " " << font << " " << r << " " << c << " " << val << endl;
      if(font == "C1")
      {
        cc1();
      }
    }
  }
  output();
  return 0;    
}
