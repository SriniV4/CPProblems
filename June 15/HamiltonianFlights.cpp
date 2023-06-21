/*
	Date: 
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcount(x)
#define tbits(total_size , num) total_size - __builtin_clz(num)
#define pb push_back
#define trav(name , ds) for(auto&name : ds)
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<int , int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
#define rsz(ds ,size , val) ds.assign(size , val);
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
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
const int MOD = (int)1e9+7;
void solve(){
	int n;
	cin >> n;
	vector<vi> adj(n);
	int m;
	cin >> m;
	for(int i =0;i<m;i++){
			int a , b;
			cin >> b >> a;
			adj[--a].pb(--b);
	}
	vector<vll> dp(1ll<<n , vll(n , 0));
	dp[1][0] = 1;
	//dp[mask][i] = number of ways to visit masked nodes and end at i
	for(int i = 2 ; i<1ll<<n;i++){
			if(i & (1ll<<(n-1)) && i!=((1ll<<n)-1))
				continue;
			for(int lastCity = 1;lastCity<n;lastCity++){
					if(i & 1<<lastCity){
							int withoutLast = i-(1<<lastCity);
							for(int neigh : adj[lastCity]){
									dp[i][lastCity] += dp[withoutLast][neigh];
									dp[i][lastCity]%=MOD;
							}
					}
			}
	}
	cout << dp[(1ll<<n)-1][n-1];
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

