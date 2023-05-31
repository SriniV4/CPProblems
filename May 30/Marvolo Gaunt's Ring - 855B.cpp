//https://codeforces.com/contest/855/problem/B
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
	ll n , p , q , r;
	cin >> n >> p >> q >> r;
	vector<ll> arr(n);
	for(int i = 0 ; i<n;i++)
		cin >> arr[i];
	vector<vector<ll>> dp(n , vector<ll>(3 , INT64_MIN));
	dp[0][0] = p*arr[0];
	dp[0][1] = q*arr[0]+dp[0][0];
	dp[0][2] = dp[0][1] + r*arr[0];
	for(int i = 1 ;i<n;i++){
		dp[i][0] = max(dp[i-1][0] , arr[i]*p);
		dp[i][1] = max(dp[i-1][1] , dp[i][0]+arr[i]*q);
		dp[i][2] = max(dp[i-1][2] , dp[i][1] + arr[i]*r);
	}
	cout << dp[n-1][2] << '\n';
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
