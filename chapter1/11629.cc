#include<bits/stdc++.h>
using namespace std;
float l,r;
string correctans = "was correct.";
string incorrectans = "was incorrect.";
string lhs, rhs, op, ans;
map<string, double> m;
string ops[] = {">=", "<=", ">", "<", "="};
bool AreSame(double a, double b)
{
//    double diff = a-b;
//    double EPSILON = numeric_limits<double>::epsilon();
//    return (diff < EPSILON) && (diff > -EPSILON);
    return fabs(a - b) < 1E-3;
}
void setvals(string a)
{
    for(int i=0; i < 5; i++)
    {
        size_t f = a.find(ops[i]);
        if(f != string::npos)
        {
            op = ops[i];
            return;
        }
    }
}

void findans(string a)
{
    string tmp;
    size_t f = a.find(op);
    lhs = a.substr(0, f);
    rhs = a.substr(f+op.size(), a.size());
//    cout << lhs << " lsh " << op << " op " << rhs << endl;

    r = atof(rhs.c_str());
    istringstream ss(lhs);
    l = 0;
    while(getline(ss, tmp, '+'))
    {
        if(tmp[0] == ' ') tmp = tmp.substr(1,tmp.size());
        if(tmp[tmp.size()-1]==' ') tmp = tmp.substr(0, tmp.size()-1);
//        cout << " insisde "<< tmp << " " << m[tmp] << endl;
        l += m[tmp];
    }
//    cout << l << " " << op << " " << r <<  " " << endl;
    if(op == "=")
    {
        ans = AreSame(l,r) ? correctans : incorrectans;
    }
    else if(op == ">")
    {
        ans = l>r ? correctans : incorrectans;
        if(AreSame(l,r)) ans = incorrectans;
    }
    else if(op == "<")
    {
        ans = l<r ? correctans : incorrectans;
                if(AreSame(l,r)) ans = incorrectans;

    }
    else if(op == ">=")
    {
        ans = l>=r ? correctans : incorrectans;
                if(AreSame(l,r)) ans = correctans;

    }
    else if(op == "<=")
    {
        ans = l<=r ? correctans : incorrectans;
                        if(AreSame(l,r)) ans = correctans;

    }
    else{cout << "wet" << endl;}
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int p,g;
    cin >> p >> g;
    string a;
    double b;
    for(int i=0; i<p; i++)
    {
        cin >> a >> b;
        m[a] = b;
//        cout << a << " " << b << " " << m[a]  << endl;
    }
    getline(cin, a);
    for(int i=0; i<g; i++)
    {
        getline(cin, a);
        setvals(a);
        findans(a);
        printf("Guess #%d %s\n", i+1, ans.c_str());
    }
    return 0;
}
