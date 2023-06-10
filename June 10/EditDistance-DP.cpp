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
#define sz(i) (int)i.size()
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
	string a , b;
	cin >> a;
	cin >> b;
	const ll INF = 1e18;
	vector<vll> dp(sz(a)+1 , vll(sz(b)+1 , INF));
	dp[0][0] = 0;
	for(int i = 0;i<=sz(a);i++)
		for(int j =0 ;j<=sz(b);j++){
				if(i)
					dp[i][j] = dp[i-1][j]+1;
				if(j)
					dp[i][j] = min(dp[i][j-1]+1 , dp[i][j]);
				if(i && j)
					dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + (a[i-1]==b[j-1]?0:1));
		}
	//trav(a , dp)
	//{
			//trav(b , a)
				//cout << b << " ";
			//cout << "\n";
	//}
	cout << dp[sz(a)][sz(b)];
}


int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
