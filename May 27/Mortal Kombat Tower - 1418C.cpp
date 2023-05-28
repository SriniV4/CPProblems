//https://codeforces.com/contest/1418/problem/C
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
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	vector<array<ll,2>> dp(n+1 , {INT_MAX , INT_MAX});
	dp[0][1] = 0;
	for(int i = 0 ;i<n;i++){
		for(int p = 0 ; p<2;p++){
			for(int f = 1;f<=(min(n-i , 2));f++){
				int boss = arr[i] + (f==1?0:arr[i+1]);
				dp[i+f][!p] = min(dp[i+f][!p] , dp[i][p] + boss*p);
			}
		}
	}
	cout << min(dp[n][0] , dp[n][1]) << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
