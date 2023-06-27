/*
	Date: 27.06.2023
	Time: ?
	Learnt: Think about graph -> What edges/components/cycles/etc. represent in relation to the problem
	Rating: ?
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
struct dsu{
	vi parent;
	dsu(int n)
	{
			rsz(parent , n+1 , -1);
	}
	int get(int a)
	{
			return parent[a]>0?parent[a] = get(parent[a]):a;
	}
	void connect(int a , int b){
		int pA = get(a) , pB = get(b);
		if(pA==pB)
			return;
		if(parent[pA]>parent[pB])
			swap(pA , pB);
		parent[pA]+=parent[pB];
		parent[pB] = pA;
	}	
	bool connected(int a ,int b)
	{
			return get(a)==get(b);
	}
};
int n, m;
vpi edges;// node , weight
vector<vi> adj;
void printMask(int mask){
		bool seen = 0;
		for(int i = 31;i>=0;--i){
				if(mask & (1<<i)){
						seen = 1;
						cout << 1;
				} else if(seen)
					cout << 0;
		}
}
void solve(){
	cin >> n >> m;
	rsz(adj , n , vi(0));
	dsu graph(n);
	for(int i =0 ;i<m;i++){
			int a ,b , c;
			cin >> a >> b >> c;
			//cout << a << " " << b << "\n";
			cout.flush();
			graph.connect(a , b);
			edges.pb({--b , c});
			adj[--a].pb(sz(edges)-1);
			edges.pb({a , c});
			adj[b].pb(sz(edges)-1);
	}
	if(!graph.connected(1, n)){
			cout << "inf" << "\n";
			return;
	}
	set<int> comp;
	comp.insert(0);
	const int INF = 2e9;
	vector<pair<string , ll>> answer;
	while(true){
			//find min edge not in comp
			ll mn = INF;
			for(int i =0;i<n;i++){
					if(comp.count(i)){
							for(int neigh : adj[i]){
								if(!comp.count(edges[neigh].f))
										mn = min(mn , edges[neigh].s);
							}
					}
			}
			//play with current comp for mn minutes
			string mask(n , '0');
			for(int i =0;i<n;i++)
				if(comp.count(i))
					mask[i] = '1';
			answer.pb({mask , mn});
			// add all edges to component
			set<int> temp;
			for(int i =0;i<n;i++){
					if(comp.count(i)){
							for(int neigh : adj[i]){
									if(!comp.count(edges[neigh].f) && edges[neigh].s<=mn){
											temp.insert(edges[neigh].f);
									}
									edges[neigh].s-=mn;
							}
					}
			}
			for(auto &num : temp)
				comp.insert(num);
			if(comp.count(n-1))
				break;
			
	}
	ll total = 0;
	for(auto item : answer)
		total+=item.s;
	cout << total << " " << sz(answer) << "\n";
	for(int i =0;i<sz(answer);i++)
		cout << answer[i].f << " " << answer[i].s << "\n";
	
}		

int main(){
	setIO();
	int t = 1;
 	//cin >> t;
	while(t--){
		solve();
	}	
}

