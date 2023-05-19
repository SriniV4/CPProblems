//https://codeforces.com/problemset/problem/1375/A
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
void solve(){
	cin >> n;
	vector<int> arr(n);
	cin >> arr[0]; 
	cout <<abs( arr[0]) << " ";
	for(int i =1 ; i<n;i++){
		cin >> arr[i];
		if(i%2){
			cout <<-abs( arr[i]) << " ";
		} else {
			cout << abs(arr[i]) << " ";	
		}
	}
	cout << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
