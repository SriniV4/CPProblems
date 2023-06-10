/*
	Date: 
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define trav(ds , name) for(auto&name : ds)
#define f first
#define s second
#define clr(x) x.clear()
#define all(a) a.begin() , a.end()
#define pi pair<int , int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define rsz(ds ,size , val) ds.assign(size , val);
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
	int n , k;
	cin >> n >> k;
	vi moves(n);
	trav(moves , a){
			char d;
			cin >> d;
			a = (d=='H'?0:d=='P'?1:2);
	}
	vector<vector<vi>> dp(n+1 , vector<vi>(3 , vi(k+1 , 0)));// dp[i][j][k] -> Number of games won in the first i games with current move j and k swaps used
	for(int i = 1;i<=n;i++){
			int fJ = moves[i-1];
			dp[i][0][0] = dp[i-1][0][0]+(fJ==2?1:0);
						dp[i][2][0] = dp[i-1][2][0]+(fJ==1?1:0);

			dp[i][1][0] = dp[i-1][1][0]+(fJ==0?1:0);

			for(int j = 1;j<=min(i-1 , k);j++){
					dp[i][0][j] = max({dp[i-1][0][j] , dp[i-1][1][j-1] , dp[i-1][2][j-1]}) + (fJ==2?1:0);
					dp[i][1][j] = max({dp[i-1][1][j] , dp[i-1][0][j-1] , dp[i-1][2][j-1]}) + (fJ==0?1:0);
					dp[i][2][j] = max({dp[i-1][2][j] , dp[i-1][1][j-1] , dp[i-1][0][j-1]}) + (fJ==1?1:0);


			}	
	}
	int answer = 0;
	for(int i = 0 ;i<=k;i++)
		answer = max({answer , dp[n][0][i] , dp[n][1][i] , dp[n][2][i]});
	cout << answer;
}
int main(){
	setIO("hps");
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
