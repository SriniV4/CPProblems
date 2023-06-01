
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
	vector<string> grid(n);
	for(int i = 0 ;i<n;i++)
		cin >> grid[i];
	int MOD = (int)1e9+7;
	vector<vector<ll>> dp(n , vector<ll>(n , 0));
	dp[0][0] = 1;
	for(int i = 0;i<n;i++){
		for(int j =0 ;j<n;j++){
			if(i==0 && j==0 || grid[i][j]=='*')
				continue;
			if(j==0)
				dp[i][j]+=dp[i-1][j];
			else if(i==0)
				dp[i][j]+=dp[i][j-1];
			else
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
			dp[i][j]%=MOD;
		}
	}
	if(grid[0][0]=='*')
		cout << 0;
	else 
	cout << dp[n-1][n-1];
 
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
