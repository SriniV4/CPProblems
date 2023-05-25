//https://codeforces.com/contest/1499/problem/C
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
	int n;
	cin >> n;
	vector<ll> even , odd;
	for(int i = 0 ,a;i<n;i++){
		cin >> a;
		if(i%2)
			odd.push_back(a);
		else
			even.push_back(a);
	}
	ll eSum = INT_MAX , oSum = eSum , eMin = eSum , oMin = eMin;
	ll ans = INT_MAX;
	eSum = even[0];
	oSum = odd[0];
	eMin = even[0];
	oMin = oSum;
	ans = n*eMin + n*oMin;
	for(int i = 2 ; i<n;i+=2){
		eSum+=even[i/2];
		eMin = min(eMin , even[i/2]);
		ans = min(ans , oSum + oMin*(n-1-(i-1)/2) + eSum + eMin*(n-1-(i/2)));
		if(i==n-1 && n%2)
			continue;
		oSum+=odd[i/2];
		oMin = min(oMin , odd[i/2]);
		
		ans = min(ans , oSum + oMin*(n-1-(i)/2) + eSum + eMin*(n-1-(i/2)));
	}
	cout << ans  << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	cout << fixed;
	cout << setprecision(0);
	while(t--){
		solve();
	}	
}
