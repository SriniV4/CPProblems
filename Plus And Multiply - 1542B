//https://codeforces.com/contest/1542/problem/B
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
 
void solve(){
	int n , a , b;
	cin >> n >> a >> b;
	// smallest number that has same (mod) b as n -> add b's
	ll num = 1;
	if(a==1){
		cout <<((n-1)%b==0?"YES":"NO") << "\n";
		return;
	}
	while(num<=n){
		if(num%b==n%b){
			cout << "YES\n";
			return;
		}
		num*=a;
 
	}
	cout << "NO\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
