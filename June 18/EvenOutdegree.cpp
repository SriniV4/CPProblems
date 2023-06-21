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
vpi answer;
bool comp(pi a, pi b){
	return a.f>b.f;
}
void solve(){
	cin >> n >> m;
	if(m%2){
			cout << "IMPOSSIBLE" <<"\n";
			return;
	}

	//adj.resize(n);
	rsz(adj , n ,vi(0));
	for(int i = 0;i<m;i++)
	{
			int a , b;
			cin >> a >> b;
			adj[--a].pb(--b);
			adj[b].pb(a);
	}
	
	/*
	 * 
	 * 	Any node with 1 edge left -> process
	 * 	No such node -> randomly assign
	 * 
	 */ 
	//vi processed(n , 0);
	unordered_map<pi , bool , function<size_t(pi)>> done(2 , hF);
	vi edges(n , 0);
	vi parity(n , 0);//0 -> even , 1  -> odd
	priority_queue<pi , vpi , function<bool(pi a, pi b)>> pq(comp);
	for(int i =0;i<n;i++){
			pq.push({sz(adj[i]) , i});
			edges[i] = sz(adj[i]);
	}
	while(pq.size()){
			auto next= pq.top();
			pq.pop();
			if(edges[next.s] == 0 )
				continue;
			if(edges[next.s]==1){
					for(int neigh : adj[next.s]){
							if(!done[{neigh , next.s}]){
									done[{neigh , next.s}] = 1;
									done[{next.s , neigh}] = 1;
									//processed[next.s] = 1;
									if(!parity[next.s]){
										answer.pb({neigh , next.s});
										parity[neigh] = !parity[neigh];
									}
									else{
										answer.pb({next.s , neigh});
										parity[next.s] = !parity[next.s];
									}
									edges[neigh]--;
									edges[next.s]--;
									if(edges[neigh])
										pq.push({edges[neigh] , neigh});
							}
					}
			} else {
						for(int neigh : adj[next.s]){
							if(!done[{neigh , next.s}]){
									done[{neigh , next.s}] = 1;
									done[{next.s , neigh}] = 1;
									if(!parity[next.s]){
										answer.pb({neigh , next.s});
										parity[neigh] = !parity[neigh];
									}
									else{
										answer.pb({next.s , neigh});
										parity[next.s] = !parity[next.s];
									}
									edges[neigh]--;
									edges[next.s]--;
									if(edges[neigh])
										pq.push({edges[neigh] , neigh});
									if(edges[next.s])
										pq.push({edges[next.s] , next.s});
									break;
							}
					}
			}
	}
	trav(a , parity){
			if(a%2)
			{
					cout << "IMPOSSIBLE\n";
					return;
			}
	}
	trav(a , answer){
			cout << a.f+1 << " " << a.s+1 << "\n";
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

