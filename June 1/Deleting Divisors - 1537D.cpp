/*
  Time: ????
  Num Submissions: 1
  Learnt: Look for pattern -> Try and isolate into cases. Think of special cases and analyze sample
  Time Complexity : O(log(N))
  Editorial : Same
  Rating: 1700
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define f first
#define s second
#define clr(x) x.clear()
#define rsz(x ,n) x.resize(0); x.resize(n);
using namespace std;

size_t hF(pair<int , int> a){
	return (a.first + a.second)*(a.first + a.second + 1)/2 + a.second;
}
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve(){
	int n;
	cin >> n;
	if(n&1)
		cout << "Bob\n";
	else if(bits(n)!=1){
		cout << "Alice\n";
	} else{
		int p = 0;
		while(n!=1)
		{
			n>>=1;
			p++;
		}
		if(p&1)
			cout << "Bob\n";
		else 
			cout << "Alice\n";
	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
