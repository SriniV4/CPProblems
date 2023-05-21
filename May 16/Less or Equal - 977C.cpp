//https://codeforces.com/problemset/problem/977/C
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
	int n , k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0 ; i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin() , arr.end());
	int num = arr[k-1];
	if(k==0){
		cout << (arr[0]!=1?1:-1) << "\n";
		return;
	}
	if(k==n && num>1e9){
		cout << -1 << "\n";
	} else if(k==n){
		cout << num << "\n";
	} else {
		cout << (arr[k]>num?num:-1) << "\n";
	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
