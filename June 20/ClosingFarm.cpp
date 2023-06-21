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
int n ,m;
struct dsu{
		vi parent;
		dsu(int size){
				rsz(parent , size , -1);
		}
		int get(int curr){
				return parent[curr]>=0?parent[curr] = get(parent[curr]):curr;
		}
		int size(int a){
				return -parent[get(a)];
		}
		bool connected(int a , int b){
				return get(a) == get(b);
		}
		void connect(int a , int b){
				int pA = get(a) , pB = get(b);
				if(pA==pB)
					return;
				if(parent[pA]<parent[pB])
					swap(pA , pB);
				parent[pB]+=parent[pA];
				parent[pA] = pB;
		}
};
vector<vi> adj;
void solve(){
	cin >> n >> m;
	rsz(adj , n , vi(0));
	for(int i =0;i<m;i++){
			int a , b;
			cin >> a >> b;
			--a;--b;
			adj[a].pb(b);
			adj[b].pb(a);
	}
	dsu graph(n+1);
	vi barns(n);
	trav(a , barns)
		cin >> a;
	reverse(all(barns));
	vector<string> ans(n);
	vi open(n);
	for(int i=0;i<n;i++){
			open[barns[i]-1] = 1;
			for(int neigh : adj[barns[i]-1]){
				if(open[neigh]){
						graph.connect(neigh , barns[i]-1);
				}
			}	
			ans[i] = ((graph.size(barns[0]-1)==i+1)?"YES\n":"NO\n");
	}
	reverse(all(ans));
	trav(a , ans)
		cout << a;
}

int main(){
	setIO("closing");
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

