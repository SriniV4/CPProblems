/*
	Date: 
	Time:
	Learnt:
	Rating: 2000
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
	int n,  q;
	cin >> n >> q;
	vector<pair<ll , ll>> arr(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i].f;
	for(int i = 0;i<n;i++)
		cin >> arr[i].s;
	while(q--){
			ll a , b;
			cin >> a >> b;
			vll dp(n , -1e18);
			ll mx  = 0 ,mx2 = 0;
			for(int i = 0 ;i<n;i++){
					ll col = arr[i].s;
					col--;
					ll val = arr[i].f;
					ll item = max((dp[col]==mx?mx2:mx)+val*1ll*b , dp[col]+val*1ll*a);
					if(dp[col]==mx){
							if(item > mx)
							{
									dp[col] = item;
									mx = item;
							}	
					} else {
							dp[col] = max(dp[col] , item);
							if(dp[col]>mx2)
								mx2 = dp[col];
							if(mx2>mx)
								swap(mx2 , mx);
					}
			}
			cout << mx << "\n";
	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
