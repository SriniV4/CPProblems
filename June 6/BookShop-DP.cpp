/*
	Date: 05.06.2023
	Time:
	Learnt:
	Rating: CSES
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
#define pi pair<int , int>
#define vi vector<int>
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
	int n , x;
	cin >> n >> x;
	vector<pi> arr(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i].s;
	for(int i = 0;i<n;i++)
		cin >> arr[i].f;
	sort(arr.begin() , arr.end());
	vector<vector<int>> dp(n+1 , vector<int>(x+1 , 0));
	for(int i = 1;i<=n;i++){
			for(int j = 1;j<=x;j++){
				if(j>=arr[i-1].s)
					dp[i][j] = max(dp[i-1][j] , dp[i-1][j-arr[i-1].s] + arr[i-1].f);
			else
				dp[i][j] = dp[i-1][j];
			}
	}
	cout << dp[n][x];
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
