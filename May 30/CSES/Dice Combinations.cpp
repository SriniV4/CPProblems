
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
int MOD = (int)1e9+7;
void solve(){
	int n;
	cin >> n;
	vector<ll> dp(n);
	for(int i = 0; i<min(6 , n);i++)
		dp[i] = 1;
	for(int i = 0; i<n-1;i++){
		for(int j=  1;j<min(7 , n-i);j++){
			dp[i+j] = (dp[i]+dp[i+j])%MOD;;
		}
	}
	cout << dp[n-1];
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
