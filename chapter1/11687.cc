  #include <iostream>
using namespace std;
string a,b;
int main() {
	int ans = 0;
	while(getline(cin, a) && a!= "END")
	{
		int ans = 1;
		b = to_string(a.size());
		while(a!=b)
		{
			a = b;
			b = to_string(a.size());
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
} 
