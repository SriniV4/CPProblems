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
	int n;
	cin >> n;
	int sum = (n*(n+1))/2;
	if(sum%2)
		cout << 0 << "\n";
	else {
			sum/=2;
			const int MOD = (int)1e9+7;
			vector<vll> dp(n+1 , vll(sum+1));
			//dp[i][j] = number of ways to make sum j using first i elements
			dp[0][0] = 1;
			for(int i = 1;i<=n;i++){
					for(int j = 0;j<=sum;j++){
							dp[i][j] = (dp[i][j] + dp[i-1][j] + (i<=j?dp[i-1][j-i]:0))%MOD;
					}
			}
			/*
			 *	// dp[n][sum] = 2*ans ( mod M )
				   dp[n][sum]*inv(2)MODM = ans MOD M
				  inv(2) MOD M = 2 * inv(2)MOD M = 1 MOD M
				  (n+1)/2 MOD M * 2 = n+1 (mod m) = 1;
			 */
			cout <<( dp[n][sum] * (MOD+1)/2)%MOD;
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
