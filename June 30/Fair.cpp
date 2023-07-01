/*
	Date: 
	Time:
	Learnt: Remember to see what you need -> If you need shortest paths to s values, you can take to all k ( k is small ) -> when bfsing from many nodes, you have to update inside neighbor visits and not at start ( keep queue distinct -> many nodes can be 1 away from some node A )
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
vector<vi> adj;
int n , m , s , k;
void solve(){
	cin >> n >> m >> k >> s;
	rsz(adj , n  , vi(0));
	vi type(n);
	for(auto& item : type)
		cin >> item , --item;
	for(int i =0 , a , b ;i<m;i++){	
		cin >> a >> b , --a , --b , adj[a].pb(b) , adj[b].pb(a);
	}
	vector<vi> closest(n);
	vi visited(n);
	for(int i =0;i<k;i++){
			queue<pi> q;
			rsz(visited , n , 0);
			for(int j =0 ;j<n;j++)
			{
				if(type[j]==i){
					q.push({j,0});
					closest[j].pb(0);
					visited[j] = 1;
				}
			}
		while(sz(q)){
				auto next = q.front();
				q.pop();
				for(int neigh : adj[next.f]){
						if(!visited[neigh]){
							q.push({neigh , next.s+1});
							closest[neigh].pb(next.s+1);
							visited[neigh] = 1;
						}
				}
		}
	}
	for(int i =0;i<n;i++){
		//for(int j= 0;j<sz(closest[i]);j++)
			//cerr << closest[i][j] << " ";
		//cerr << "\n";
		sort(all(closest[i]));
		ll ans = 0;
		for(int j = 0;j<s;j++){
			ans+=closest[i][j];
			//cout << closest[i][j] << " ";
		}
		cout << ans <<" ";
		//cout << "\n";
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

