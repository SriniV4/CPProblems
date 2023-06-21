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
	#define vpii vector<pii>
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
	int n , m;
	vector<vi> adj;
	vpii edges;
	bool comp(pair<ll , ll> a , pair<ll , ll> b){
			return a.s>b.s;
	}
	void solve(){	
		cin >> n >> m;
		rsz(adj , n , vi(0));
		for(int i = 0;i<m;i++){
				int a , b , c;
				cin >> a>> b >> c;
				adj[--a].pb(i);
				edges.pb({--b,c});
		}
		priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , function<bool(pair<ll , ll> , pair<ll , ll>)>> pq(comp);
		const ll INF = 1e18;
		vll dist(n , INF) , visited(n);
		dist[0] = 0;
		for(int i = 0 ; i<n;i++){
				pq.push({i , dist[i]});
		}
		while(pq.size()){
				auto next = pq.top();
				pq.pop();
				if(visited[next.f])
					continue;
				visited[next.f] = 1;
				for(int neigh : adj[next.f]){
						dist[edges[neigh].f] = min(dist[edges[neigh].f] , dist[next.f] + edges[neigh].s);
						pq.push({edges[neigh].f , dist[edges[neigh].f]});
				}
		}
		//cout << dist[n-1] << "\n";
		trav(a , dist)
			cout << a << " ";
		cout << "\n";
	}

	int main(){
		setIO();
		//int t = 1;
	// 	cin >> t;
		//while(t--){
			solve();
		//}	
	}

