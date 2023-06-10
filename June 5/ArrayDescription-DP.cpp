/*
	Date: 05.06.2023
	Time:
	Learnt:
	Rating: DP - CSES
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define trav(a , b) for(auto&b : a)
#define f first
#define s second
#define all(x) x.begin() , x.end()
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
	int n, m;
	const int MOD = (int)1e9+7;
	cin >>n >> m;
	vi arr(n);
	trav(arr , num)
		cin >> num;
	vector<vi> dp(n+1 , vi(m+1 , 0));
	if(arr[0]==0)
		fill(all(dp[1]) , 1);
	for(int i = 1 ;i<=n;i++){
		int num = arr[i-1];
		if(i==1){
				dp[i][num] = 1;
				continue;
		}
		if(num){
			int j= num;
				for(int poss : {j-1,j,j+1}){
						if(poss>=1 && poss<=m)
							dp[i][num]=(dp[i][num]+dp[i-1][poss])%MOD;
				}
		} else {
				for(int j=1;j<=m;j++){
					for(int poss : {j-1,j,j+1}){
						if(poss>=1 && poss<=m)
						dp[i][j]=((dp[i-1][poss])%MOD+dp[i][j])%MOD;
				}
				}
		}
		
	}
	int sum = 0;
	for(int i =1;i<=m;i++)
		sum=(sum+dp[n][i])%MOD;
	cout << sum%MOD << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
