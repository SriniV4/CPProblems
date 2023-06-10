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
#define trav(name , ds) for(auto&name : ds)
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
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
	int n , m , c;
	cin >> n >> m >> c;
	vi cost(n);
	trav(a , cost)
		cin >> a;
	vector<vi> adj(n);
	for(int i = 0;i<m;i++){
			int  a, b;
			cin >> a >> b;
			adj[--a].pb(--b);
	}
	vector<vi> dp(1001 , vi(n , INT_MIN));
	int answer = 0;
	dp[0][0] = 0;
	for(int d = 1;d<=1000;d++){
			for(int i =0;i<n;i++){
					if(dp[d-1][i]!=INT_MIN){
						trav(neigh , adj[i]) {
								dp[d][neigh] = max(dp[d][neigh] , dp[d-1][i] + cost[neigh]);
						}
					}
			}
			answer = max(answer , (dp[d][0]<0?0:dp[d][0]) - c*d*d);
	}
	cout << answer << "\n";
}
int main(){
	setIO("time");
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
