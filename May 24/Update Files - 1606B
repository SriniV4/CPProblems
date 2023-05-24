//https://codeforces.com/contest/1606/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	ll n , k;
	cin >> n >> k;
	ll sum = 1;
	ll ans = 0;
	while(sum < n  && sum < k){
		sum*=2;
		ans++;
	}
	cout << ans + ceil(max(0ll,(n-sum))/(long double)k) << "\n";
}
int main(){
	int t;
	cin >> t;
	cout << fixed;
	cout << setprecision(0);
	while(t--)
		solve();
}














