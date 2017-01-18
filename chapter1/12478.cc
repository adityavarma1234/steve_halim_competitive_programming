#include<bits/stdc++.h>
using namespace std;

const char *vinit[]  = {"RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};
vector<string> names(vinit, vinit+8);
//[] = {"RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};
const char *sinit[] = {"OBIDAIBKR", "RKAULHISP", "SADIYANNO", "HEISAWHIA", "IRAKIBULS", "MFBINTRNO", "UTOYZIFAH", "LEBSYNUNE", "EMOTIONAL"};
vector<string> mat(sinit, sinit+9);
//[] = {"OBIDAIBKR", "RKAULHISP", "SADIYANNO", "HEISAWHIA", "IRAKIBULS", "MFBINTRNO", "UTOYZIFAH", "LEBSYNUNE", "EMOTIONAL"};

int names_h[26];
int mat_h[26];
int seen[8];

bool is_correct()
{
    for(int i=0;i<26;i++)
        if(names_h[i] != mat_h[i])
            return false;
    return true;
}

bool reset_name()
{
  for(int i=0;i<26;i++) names_h[i] = 0;
}

bool reset_mat()
{
  for(int i=0;i<26;i++) mat_h[i] = 0;
}

bool present(string a)
{
  int len = a.size();
  int row = mat.size();
  int col = mat[0].size();
  int cnt = 0;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      reset_mat();
      int k;
      for(k=j;k<min(col, j + len);k++)
      {
          int tmp = mat[i][k]-'A';
        mat_h[tmp]++;
      }
      if(is_correct()) cnt++;
      reset_mat();
      for(k=i;k<min(row, i + len);k++)
      {
          int tmp = mat[k][j]-'A';
        mat_h[tmp]++;
      }
      if(is_correct()) cnt++;
    }
  }
  if(cnt>1) return true;
  return false;
}

int main()
{
    for(int i = 0;i < names.size(); i++)
    {
        reset_name();
        for(int j = 0;j < names[i].size(); j++)
        {
            int tmp=names[i][j]-'A';
            names_h[tmp]++;
        }
        if(present(names[i]))
        {
          cout << names[i] << endl;
        }
    }
    return 0;
}
