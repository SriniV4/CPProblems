//https://codeforces.com/contest/1732/problem/D1
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
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
	int q;
	cin >> q;
	set<ll> exists;
	map<ll , ll> prev;
	exists.insert(0);
	for(int i = 0; i<q;i++){
		ll num;
		char d;
		cin >> d >> num;
		
		if(d=='+')
			exists.insert(num);
		else if(exists.size()==1)
			cout << num << "\n";
		else
		{
			ll base = num;
			num =(prev.count(num)? prev[num]:num);
			while(exists.count(num))
				num+=base;
			prev[base] = num;
			cout << num << "\n";
		}
	}		
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
