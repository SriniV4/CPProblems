//https://codeforces.com/problemset/problem/1351/B
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
	int a , b , c , d;
	cin >> a >> b >> c >> d;
	bool p = (a==c && b+d==a) || (b==d && a+c==b) || (b==c && d+a==b) || (a==d && b+c==a);   
	cout << (p?"YES":"NO") << "\n";
	return;
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
