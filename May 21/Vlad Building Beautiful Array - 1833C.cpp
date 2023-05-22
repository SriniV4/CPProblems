//https://codeforces.com/problemset/problem/1833/C
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
	vector<ll> arr(n);
	for(int i = 0 ; i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin() , arr.end());
	int parity = arr[0]%2;
	vector<int> prefix(n);
	prefix[0] = arr[0]%2;
	for(int i = 1 ; i<n;i++)
		prefix[i] = prefix[i-1] + arr[i]%2;
	if(parity){
		for(int i =1 ; i<n;i++){
			if(arr[i]%2==0 && prefix[i-1]==0){
				cout << "NO\n";
				return;
			}
		}
	} else {
		for(int i =1 ; i<n;i++){
			if(arr[i]%2 && prefix[i-1]==0 )
							{
				cout << "NO\n";
				return;

			}
		}
	}
	cout << "YES\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
