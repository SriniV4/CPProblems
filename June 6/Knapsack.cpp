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
int s, n;
map<int , multiset<int>> items;
void solve(){
	cin >> s>> n;
	for(int i =0;i<n;i++){
		int v , w, k;
		cin >> v >> w >> k;
		int mxS = s/w;
		auto& item = items[w];
		while(k>0 && (int)item.size() < mxS){
			k--;
			item.insert(v);
		}	
		while(k>0){
				auto it = item.begin();
				if(*it < v){
						item.erase(it);
						item.insert(v);
				} else
					break;
				k--;
		}
	}
	//cout << "YES\n";
	//cout.flush();
	
	vll cost , gain;
	trav(wght , items){
			trav(g , wght.s){
					gain.pb(g);
					cost.pb(wght.f);
			}
	}
	n= cost.size();
	//for(int i = 0;i<n;i++){
			//cout << cost[i] << " " << gain[i] << "\n";
	//}
	vector<vll> dp(n , vll(s+1));
	//dp[i][j] -> best value using first i elements with weight j
	for(int i = 0;i<n;i++){
		if(i==0){
				if(cost[i]<=s)
					dp[0][cost[i]] = gain[i];
				continue;
		}
		for(int j = 0;j<=s;j++){
				dp[i][j] = dp[i-1][j];
				if(cost[i]<=j)
					dp[i][j] = max(dp[i][j] , dp[i-1][j-cost[i]] + gain[i]);
					
		}
	}	
	ll answer = 0;
	for(int i = 0 ;i<=s;i++)
		answer = max(answer , dp[n-1][i]);
	cout << answer << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
