/*
	Date: 
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcount(x)
#define tbits(total_size , num) total_size - __builtin_clz(num)
#define pb push_back
#define trav(name , ds) for(auto&name : ds)
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<int , int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
#define rsz(ds ,size , val) ds.assign(size , val);
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
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
vector<vi> adj;
vi visited;
void dfs(int curr , int last , stack<int>& path){
	cout << curr << "\n";
		path.push(curr);
		if(visited[curr] && path.size()-visited[curr]>=3){
			cout << path.size()-visited[curr]+1 << "\n";
				cout << path.top()+1 << " ";
				path.pop();
				while(path.top() != curr)
				{
						cout << path.top()+1 << " ";
						path.pop();
				}
				cout << curr+1 << " ";
				exit(0);
		}
		visited[curr] = sz(path);
		for(int neigh : adj[curr]){
				if(neigh!=last){
						dfs(neigh , curr , path);
				}
		}
}
void solve(){
	cin >> n >> m;
	rsz(visited , n , 0);
	rsz(adj , n , vi(0));
	for(int i =0;i<m;i++){
		int a , b;
		
			cin >> a >> b;
			adj[--a].pb(b-1);
			adj[--b].pb(a);
	}
	for(int i = 0;i<n;i++){
			if(!visited[i]){
				stack<int> temp;
					dfs(i , -1 , temp);
			}
	}
	cout << "IMPOSSIBLE\n";
}
int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

