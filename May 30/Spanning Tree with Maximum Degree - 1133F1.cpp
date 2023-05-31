//https://codeforces.com/contest/1133/problem/F1
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
int n ,m;
vector<vector<int>> adj;
void solve(){
	cin >> n >> m;
	rsz(adj , n);
	for(int i = 0;i<m;i++){
		int a , b;
		cin >> a >> b;
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int max =0 , ind = 0;
	for(int i = 0 ; i<n;i++){
		if(adj[i].size()>max){
			max = adj[i].size();
			ind = i;
		}
	}
	queue<int> q;
	q.push(ind);
	vector<bool> visited(n);
	visited[ind] = 1;
	while(!q.empty()){
		int item = q.front();
		q.pop();
		for(int neigh : adj[item]){
			if(!visited[neigh]){
				cout << item+1 <<" " << 1+neigh << "\n";
				visited[neigh] = 1;
				q.push(neigh);
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
