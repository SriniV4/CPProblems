//https://codeforces.com/contest/1213/problem/D2
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
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	vector<vector<int> > amount(2*(int)(1e5));
	for(int d : arr){
		int moves = 0;
		while(d){
			amount[d-1].push_back(moves);
			d/=2;
			moves++;
		}
	}
	ll ans = INT_MAX;
	for(int i = 0;i<2*(int)1e5;i++){
		if(amount[i].size()>=k){
			sort(amount[i].begin() , amount[i].end());
			ll sum = 0;
			for(int j = 0;j<k;j++)
				sum+=amount[i][j];
			ans = min(ans , sum);
		}
	}
	cout << ans << "\n";

}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
