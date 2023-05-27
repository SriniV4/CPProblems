//https://codeforces.com/contest/1338/problem/A
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
ll get(int num){
	ll count = 0;
	while(num){
		num = num>>1;	
		count++;
	}
	return count;
}
void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int &d : arr)
		cin >> d;
	ll best =0;
	int prev = arr[0];
	for(int i = 1;i<n;i++){
		int needed = prev - arr[i];
		if(needed<=0){
			prev = arr[i];
			continue;
		}
		best = max(best , get(needed));
	}
	cout << best << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
