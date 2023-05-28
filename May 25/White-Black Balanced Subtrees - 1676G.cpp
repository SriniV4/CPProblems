//https://codeforces.com/contest/1676/problem/G
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
string line;
vector<vector<int> > adj;
int n;
int answer = 0;
pair<int , int> dfs(int curr , int parent){
	int b = 0 , w = 0;
	if(line[curr]=='B')
		b++;
	else w++;
	for(int d : adj[curr]){
		if(d!=parent)
		{
			auto item = dfs(d , curr);
			b+=item.first;
			w+=item.second;
		}
	}
	if(b==w)
		answer++;
	return {b,w};
}
void solve(){
	cin >> n;
	adj.resize(0);
	adj.resize(n);
	answer = 0;
	for(int i = 0 ;i<n-1;i++)
	{
		int a;
		cin >> a;
		a--;
		adj[a].push_back(i+1);
		adj[i+1].push_back(a);
	}
	cin >> line;
	dfs(0 , -1);
	cout<< answer << "\n";

}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
