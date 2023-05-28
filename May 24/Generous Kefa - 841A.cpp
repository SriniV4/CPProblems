//https://codeforces.com/problemset/problem/841/A
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
	string line;
	cin >> line;
	unordered_map<int , int> count;
	for(auto d : line)
		count[d]++;
	for(auto item : count)
		if(item.second>k){
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
