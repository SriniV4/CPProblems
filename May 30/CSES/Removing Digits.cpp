
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
	int n;
	cin >> n;
	vector<int> dp(n+1 , INT_MAX);
	dp[0] = 0;
	for(int i = 1  ;i<=n;i++){
		int temp = i;
		while(temp){
			int dig = temp%10;
			temp/=10;
			dp[i] = min(dp[i] , dp[i-dig]);
		}
		dp[i]++;
	}
	cout << dp[n] << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
