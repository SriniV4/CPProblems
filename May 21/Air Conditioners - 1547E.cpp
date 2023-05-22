//https://codeforces.com/contest/1547/problem/E
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
	vector<int> airInd(k) , air(n , INT_MAX);
	vector<int> l(n , INT_MAX) , r(n , INT_MAX);
	for(int i = 0 ; i<k;i++)
		cin >> airInd[i];
	for(int i = 0 ; i<k;i++)
	{
		cin >> air[airInd[i]-1];
	}
	for(int i = 0;i<n;i++){
		if(i==0 || l[i-1]==INT_MAX){
			l[i] = air[i];
		} else {
			l[i] = min(air[i] , l[i-1] + 1);
		}
	}
	for(int i = n-1;i>=0;i--){
		if(i==n-1 || r[i+1]==INT_MAX)
			r[i] = air[i];
		else
			r[i] = min(air[i] , r[i+1]+1);
	}
	for(int i = 0; i<n;i++){
		cout << min(l[i] , r[i]) << " ";
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
