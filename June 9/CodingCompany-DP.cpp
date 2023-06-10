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
const int MOD = (int)1e9+7;
const int K = 5e3;
void solve(){
	int n , x;
	cin >> n >> x;
	vll arr(n);
	for(int i = 0 ;i<n;i++)
		cin >> arr[i];
	sort(all(arr));
	vector<vll> dp1(n+1 , vll(K+x+1)) , dp2(n+1 , vll(K+x+1));
	dp1[0][K] = 1;
	for(ll i = 0 ;i<n;i++){
			for(ll j= 0 ;j<=n;j++){
					for(ll k = 0;k<=K+x;k++){
							if(!dp1[j][k])
								continue;
							// group of own or extend previous group ( 1 + j ) options 
							dp2[j][k] += (j+1) * dp1[j][k];
							//finish group
							if(j && k+arr[i]<=K+x)
								dp2[j-1][k + arr[i]] += j * dp1[j][k];
							//start own group
							if(k>=arr[i] && j<n){
								dp2[j+1][k-arr[i]] += dp1[j][k];
								//cout<< dp2[j+1][k-arr[i]] << "\n";
							}							
					}
			}
			for(int j =0 ;j<n;j++){
					for(int k =0 ;k<=x+K;k++){
							dp1[j][k] = dp2[j][k]%MOD;
							//cout << dp1[j][k] << " ";
							dp2[j][k] = 0;
					}
					//cout << '\n';
			}
			//cout << "\n";
	}
	ll ans = 0;
	for(int i = K;i<=x+K;i++){
			ans = (ans + dp1[0][i])%MOD;
	}
	cout << ans << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
