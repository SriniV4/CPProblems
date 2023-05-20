//https://codeforces.com/problemset/problem/1481/A
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
	int x , y;
	cin >> x >> y;
	string line;
	cin >> line;
	int u = 0 , l  = 0 , d = 0 , r = 0;
	for(char t : line)
		if(t=='U')
			u++;
		else if(t=='L')
			l++;
		else if(t=='R')
			r++;
		else 
			d++;
	if(x>=0){
		if(y>=0){
			cout << (u>=y && r>=x?"YES\n":"NO\n");
		} else {
			cout << (d>=-y && r>=x?"YES\n":"NO\n");
			
		}
	} else {
		if(y>=0){
			cout << (u>=y && l>=-x?"YES\n":"NO\n");
		} else {
			cout << (d>=-y && l>=-x?"YES\n":"NO\n");
		}

	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
