//https://codeforces.com/contest/1831/problem/C
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
unordered_map<pair<int , int> , int , function<size_t(pair<int , int>)>> order(2 , hF);
vector<vector<int> > adj;
int answer = 0;
void dfs(int curr ,int parent , int reading){
	answer = max(answer , reading);
	for(int neigh : adj[curr]){
		if(neigh==parent)
			continue;
		if(order[{curr , parent}] < order[{neigh , curr}]){
			dfs(neigh , curr , reading);
		} else
			dfs(neigh ,curr , reading+1);
	}
}
void solve(){
	cin >>n;
	adj.resize(0);
	adj.resize(n);
	answer = 0;
	for(int i =1;i<n;i++){
		int a , b;
		cin >> a >> b;
		a--;b--;
		order[{a,b}] = i;
		order[{b,a}] = i;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0 , 0 , 1);
	cout << answer << "\n";

}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
