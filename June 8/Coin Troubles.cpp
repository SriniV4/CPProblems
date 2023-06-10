/*
	Date: 07.06.2023
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
bool cycle(map<int ,int>& adj , vi& indeg){
		int counter = 0;
		for(int i = 1; i<indeg.size();i++){
				if(indeg[i])
					continue;
				int temp = i;
				while(adj[temp]){
						counter++;
						temp = adj[temp];
				}
				counter++;
		}
		return counter!=indeg.size()-1;
}
void solve(){
	int n , q , t;
	cin >> n >> q >> t;
	vi arr(n);
	trav( d , arr)
		cin >> d;
	map<int , int> queries;
	vi indeg(n+1);
	for(int i =0 ;i<q;i++){
			int b , c;
			cin >> b >> c;
			queries[b] = c;
			indeg[c]++;
	}
	if(cycle(queries , indeg)){
			cout << 0;
			return;
	}
	vi coins;
	ll mustHave = 0;
	for(int i = 1;i<=n;i++){
			if(indeg[i])
				continue;
			coins.pb(arr[i-1]);
			int temp = i;
			stack<int> visited;
			int denom = arr[i-1];
			while(queries[temp]){
					visited.push(arr[temp-1]);
					temp = queries[temp];
					denom+=arr[temp-1];
					coins.pb(denom);
			}
			visited.push(arr[temp-1]);
			ll counter = 0;
			while(visited.size()){
				//cout<< visited.top() << "   ";
					mustHave+=visited.top()*counter;
					visited.pop();
					counter++;
			}
	}
	//trav(coin , coins)
		//cout << coin << " ";
// 	t-=mustHave;
	if(t<=mustHave){
			cout << (t==mustHave?1:0) << "\n";
			return;
	}
// 	if(q==279){
// 	    cout << mustHave << " " << t << "\n";
// 	    exit(10);
// 	}
    t-=mustHave;
	const int MOD = 1e9+7;
	vll dp(t+1);
	dp[0] = 1;
	trav(coin , coins){
			for(int i = coin;i<=t;i++){

						dp[i] = (dp[i]+dp[i-coin])%MOD;
			}
	}
	cout << dp[t] << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}

