//https://codeforces.com/contest/1798/problem/C
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
ll lcm(ll a , ll b){
	return (a*b)/(gcd(a,b));
}
void solve(){
	int n;
	cin >>n;
	vector<ll> a(n) , b(n);
	for(int i = 0 ;i<n;i++)
		cin >> a[i] >> b[i];
	int ans = 1;
	ll g = a[0]*b[0], l = b[0];
	for(int i = 0 ; i<n;i++){
		g = gcd(a[i]*b[i] , g);
		l = lcm(b[i] , l);
		if(g%l){
			ans++;
			g = a[i]*b[i];
			l = b[i];
		}
	}
	cout << ans << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
