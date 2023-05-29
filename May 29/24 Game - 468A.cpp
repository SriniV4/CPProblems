//https://codeforces.com/contest/468/problem/A
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
	if(n<=3)
		cout << "NO\n";
	else {
		if(n%2){
			cout << "YES\n";
			cout << "5 * 4 = 20\n";
			cout << "3 - 1 = 2\n";
			cout << "2 + 2 = 4\n";
			cout << "20 + 4 = 24\n";
			for(int i = 6 ;i<n;i+=2){
				cout << i+1 << " - " << i <<" = 1\n";
				cout << "24 * 1 = 24\n";
			}
		} else {
			cout << "YES\n";
			cout << "4 * 3 = 12\n";
			cout << "12 * 2 = 24\n";
			cout << "24 * 1 = 24\n";
			for(int i = 5;i<n;i+=2){
				cout << i+1 << " - " << i <<" = 1\n";
				cout << "24 * 1 = 24\n";

			}
		}	
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
