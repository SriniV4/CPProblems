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
#define sz(i) i.size()
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
const ll INF = 1e18;
ll cost(pi a , pi b){
		ll d = abs(a.f-b.f) + abs(a.s-b.s);
		return d*d;
}
void solve(){
	int h , g;
	cin >> h >> g;
	vpi holt(h+1) , guern(g+1);	
	for(int i = 0;i<h;i++)
		cin >> holt[i].f >> holt[i].s;
	for(int i = 0;i<g;i++){
			cin >> guern[i].f >> guern[i].s;
	}
	//dp[i][j][k(0/1)]  -> smallest dist covering first i H and first i G ending with k (0 -> H , 1 -> G)
	vector<vector<vll>> dp(h+1 , vector<vll>(g+1 , vll(2, INF)));
	/*
	 * 	dp[i+1][j][0] = min(dp[i][j][0] + dist(i -> i+1 Holt) , dp[i][j][1] + dist(j G -> i+1 H) , dp[i][j+1][0] + dist... , dp[i][j+1][1] + dist
	 */ 
	dp[1][0][0] = 0;
	for(int i = 1;i<h;i++){
			for(int j= 0; j<g;j++){
				dp[i+1][j][0] = min(dp[i][j][0] + cost(holt[i-1] , holt[i]) , (j==0?(ll)1e18:dp[i][j][1] + cost(holt[j] , guern[j-1])));
				cout << dp[i+1][j][0] << " ";
				dp[i][j+1][1] = min(dp[i][j][0] + cost(holt[i-1] , guern[j]) , (j==0?(ll)1e18:dp[i][j][1] + cost(guern[j] , guern[j-1])));	
				cout << dp[i][j+1][1] << "\n";
			}
	}
	cout << min(dp[h][g][0] , dp[h][g][1]) << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
