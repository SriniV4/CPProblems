/*
	Date: 28.06.2023
	Time: 30
	Learnt:	If you are looking for odd cycles -> Bipartite. Notice patterns and if you have pairs -> graph??
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
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<ll , ll>
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
bool bad = 0;
vi visited;
void dfs(int curr , int parent , int step){
	visited[curr] = step;
	if(bad)
		return;
	for(int neigh : adj[curr]){
			if(neigh!=parent){
				if(visited[neigh]){
						if((step - visited[neigh])%2==0)
							bad = 1;
				} else
					dfs(neigh , curr , step+1);
			}	
	}
	
}
void solve(){
	cin >> n;
	rsz(adj , n , vi(0));
	rsz(visited ,n , 0);
	bad = 0;
	for(int i =0;i<n;i++){
			int a , b;
			cin >> a >> b;
			--a;--b;
			if(a==b)
				bad = 1;
			adj[a].pb(b);
			adj[b].pb(a);
	}
	for(int i=0;i<n;i++){
			if(sz(adj[i])>=3)
			{
					bad = true;
					break;
			}
	}
	if(bad)
		goto print;
		
	for(int i =0;i<n;i++){
		if(!visited[i])
			dfs(i , -1 , 1);
		if(bad)
			break;
	}
	print:;
	cout << (bad?"NO\n":"YES\n");
}

int main(){
	setIO();
	int t = 1;
 	cin >> t;
	while(t--){
		solve();
	}	
}

