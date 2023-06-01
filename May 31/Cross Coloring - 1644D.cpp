//https://codeforces.com/contest/1644/problem/D
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
const int MOD = 998244353;
void solve(){
	int n ,m  , q , k;
	cin >> n >> m >> k >> q;
	ll ans = 1;
	set<int> row , col;
	vector<int> xx(q) , yy(q);
	for(int i  = 0 ;i<q;i++)
		cin >> xx[i] >> yy[i];
	bool valid = true;
	for(int i = q-1;i>=0;i--){
		int x = xx[i] , y  = yy[i];
		if(!valid)
			continue;
		if(!row.count(x) ||!col.count(y))
			{
				ans = (ans*k)%MOD;
				row.insert(x);
				col.insert(y);
			}
		if(row.size()==n || col.size()==m)
			valid = false;
	}
	cout << ans << "\n";
	/*
	 *   4 4 4 5 
	 *   5 5 5 5
	 *
	 */
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
