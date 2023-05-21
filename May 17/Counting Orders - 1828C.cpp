//https://codeforces.com/contest/1828/problem/C
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
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
int n;
int MOD = 1e9+7;
void solve(){
	cin >> n;
	vector<int> a(n) , b(n);
	for(int i = 0 ; i<n;i++)
		cin >> a[i];
	for(int i = 0 ;i<n;i++)
		cin >> b[i];
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	ll ans = 1;
	for(int i = 0 ; i<n;i++){
		if(a[i]<=b[i])
		{
		cout << 0 << "\n";
		return;
		}
	}
		int p1 = n-1 , p2 =n-1;
		while(p1>=0 && p2>=0){
			while(b[p2]>=a[p1])
				p2--;
			ans*=(p2-p1+1);
			ans%=MOD;
			p1--;
		}
		cout << ans%MOD << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
