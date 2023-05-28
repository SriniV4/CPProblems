//https://codeforces.com/problemset/problem/1822/A
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
	int n, t;
	cin >> n >> t;
	vector<int> a(n) , b(n);
	for(int i = 0;i<n;i++)
		cin >> a[i];
	for(int i = 0;i<n;i++)
		cin >> b[i];
	int answer = -1 , e = -1;
	for(int i = 0 ;i<n;i++){
		if(a[i]+i<=t && b[i] >e){
			answer = i+1;
			e= b[i];
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
