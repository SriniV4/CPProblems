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
const int LOG = 21;
vector<vi> adj;
vi depth;
vector<vi> ancestors;//[i][j] -> 2^jth ancestor of i;
void dfs(int curr , int par){
		depth[curr] = depth[par]+1;
		for(int child : adj[curr]){
				if(child==par)
					continue;
				ancestors[child][0] = curr;
				dfs(child , curr);
		}
}
void binLift(){
	for(int i = 1;i<LOG;i++){
		for(int j=0;j<n;j++){
				ancestors[j][i] = ancestors[ancestors[j][i-1]][i-1];
		}
	}
}
int getLCA(int a , int b){
		if(depth[a] < depth[b])
			swap(a,b);
		int diff = depth[a] - depth[b];
		//cout << diff << "a ";
		int counter =0;
		while(diff){
				if(diff & 1){
						a = ancestors[a][counter];
				}
				counter++;
				diff>>=1;
		}
		//cout << a << " " << b << "c ";
		for(int i = LOG-1;i>=0;--i){
				if(ancestors[a][i]!=ancestors[b][i]){
						a = ancestors[a][i];
						b = ancestors[b][i];
				}
		}
		return a==b?a:ancestors[a][0];
}
void solve(){
	int q;
	cin >> n >> q;
	rsz(ancestors , n , vi(LOG));
	rsz(adj , n , vi(0));
	rsz(depth , n , -1);
	for(int i =0;i<n-1;i++){
			int a , b;
			cin >> a >> b;
			--a;--b;
			adj[b].pb(a);
			adj[a].pb(b);
	}
	dfs(0 , 0);
	binLift();
	for(int i =0;i<q;i++){
			int a , b;
			cin >> a >> b;
			--a;--b;
			int lca = getLCA(a , b);
			//cout << a << " " << b << " ";cout << lca <<  " ";
			cout << depth[a]-depth[lca] + depth[b]-depth[lca] << "\n";
	}
	
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

