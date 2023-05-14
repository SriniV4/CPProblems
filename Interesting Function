//https://codeforces.com/problemset/problem/1538/F
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
	string a , b;
	cin >> a >> b;
	while(a.length() < b.length())
		a = '0' + a;
	while(a.length() > b.length())
		b = '0' + b;
	int n = a.length();
	ll answer = 0;
	ll prev = -1;
	for(int i = 0; i<n;i++){
		if(i==0){
			answer+=b[i] - a[i];
			prev = answer;
		} else {
			ll temp = prev*10 - (a[i] - b[i]);
			prev = temp;
			answer+=prev;
		}
	}
	cout << answer << "\n";


	
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
