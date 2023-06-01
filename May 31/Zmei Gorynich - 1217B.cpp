//https://codeforces.com/contest/1217/problem/B
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
	int n ,x;
	cin >> n >> x;
	int maxDam = 0;
	pair<int , int> best;
	int cnt  = 0;
	for(int i =0 ; i<n;i++){
		int a , b;
		cin >> a >> b;
		if(a-b<=0)
			cnt++;
		maxDam = max(maxDam , a);
		if(a-b>best.f-best.s)
			best = {a,b};
	}
	if(cnt==n && maxDam<x)
		{
			cout << -1 << "\n";;
			return;
		}
	if(maxDam>=x){
		cout << 1 << "\n";
		return;
	}
	cout << fixed << setprecision(0);
	cout << ceil(max(0,(x-max(maxDam , best.first)))/(ld)(best.f-best.s))+1 << "\n";

}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
