//https://codeforces.com/contest/1396/problem/A
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define f first
#define s second
#define clr(x) x.clear()
#define rsz(x ,n) x.resize(0); x.resize(n);
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
	vector<ll> arr(n);
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	if(n==1){
		cout << "1 1\n";
		cout << -arr[0] << "\n";
		cout << "1 1\n0\n1 1\n0";
		return;
	}
	cout << 1 << " " << n << '\n';
	for(ll& d : arr){
		ll k = -d%(n-1);
		d+=k*n;
		cout << k*n << ' ';
	}
	cout << "\n";
	cout << 1 << " " << n-1 << "\n";
	for(int i = 0 ;i<n-1;i++){
		cout << -(arr[i]) << " ";
	}
	cout << "\n";
	cout << n << " " << n << "\n";
	cout << -arr[n-1];
	
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
