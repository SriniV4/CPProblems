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
#define pii pair<int , int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
#define rsz(ds ,size , val) ds.assign(size , val);
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
using namespace std;
uint64_t time() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
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
vector<vi> adj;
vll leaves;
int dfs(int curr , int parent){
		int children = sz(adj[curr]) - (parent==curr?0:1);
		if(children==0){
			
			return leaves[curr] = 1;
		}
		int sum = 0;
		trav(neigh , adj[curr]){
				if(parent==neigh)
					continue;
				else
					sum+=dfs(neigh , curr);
		}
		return leaves[curr] = sum;
}
void solve(){
	cin >> n;
	rsz(adj , n , vi(0));
	rsz(leaves , n , 0);
	for(int i =0;i<n-1;i++){
			int a , b;
			cin >> a >> b;
			adj[--a].pb(--b);
			adj[b].pb(a);
	}
	dfs(0  , 0);
	int q;
	cin >> q;
	for(int i =0;i<q;i++){
			int x , y;
			cin >> x >> y;
			cout << leaves[--x]*leaves[--y] << "\n";
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

