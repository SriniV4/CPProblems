//https://codeforces.com/contest/1828/problem/B
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
	vector<int> arr(n);
	vector<int> ind(n);
	for(int i = 0;i<n;i++){
		cin >> arr[i];
		ind[arr[i]-1] = i+1;
	}
	vector<int> diff(n);
	for(int i = 0 ;i<n;i++){
		diff[i] = abs(ind[i]-i-1);
	}		
	ll ans = -1;
	for(int i = 0; i<n;i++){
		if(diff[i]==0)
			continue;
		if(ans==-1)
			ans = diff[i];
		else 
			ans = gcd(ans , diff[i]);
	}
	cout << (ans==-1?n:ans) << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
