
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define f first
#define s second
#define clr(x) x.clear()
#define rsz(x ,n) x.resize(0); x.resize(n);
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
	int n , x;
	cin >> n >> x;
	vector<int> arr(n);
	for(int i = 0 ;i<n;i++)
		cin >> arr[i];
	sort(arr.begin() , arr.end());
	vector<int> dp(x+1 , INT_MAX-1);
	dp[0] = 0;
	for(int i = 1 ; i<=x;i++){
		for(int coin : arr){
			if(coin<=i)
				dp[i] = min(dp[i] , dp[i-coin]+1);
			else
				break;
		}
	}
	cout << (dp[x]==INT_MAX-1?-1:dp[x]) << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
