//https://codeforces.com/contest/818/problem/B
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
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	for(int i = 0 ;i<m;i++)
		cin >> l[i];
	vector<int> ans(n) , ind(n);
	for(int i = 1;i<m;i++){
		int ele = (l[i]>l[i-1]?l[i]-l[i-1]:l[i]+n-l[i-1]);
		if(ind[ele-1] && ind[ele-1]!=l[i-1] || ans[l[i-1]-1] && ans[l[i-1]-1]!=ele){
			cout << -1;
			return;
		}	
		ans[l[i-1]-1] = ele;
		ind[ele-1] = l[i-1];
	}
	for(int i= 0 ; i<n;i++){
		if(!ind[i]){
			for(int j = 0 ;j<n;j++)
				if(ans[j]==0){
					ans[j] = i+1;
					break;
				}
		}
	}
	for(int d : ans)
		cout << d << " ";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
