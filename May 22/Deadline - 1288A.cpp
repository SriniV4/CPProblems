//https://codeforces.com/problemset/problem/1288/A
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
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
	int n ,d;
	cin >> n >> d;
	int days = (int)sqrt(d);
	int days1 = days+1;
	bool p = n>=d || days-1 + (ceil(d/(days+0.0)))<=n;
	cout << (p || days1-1 + (ceil(d/(days1+0.0)))<=n?"YES":"NO") << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
