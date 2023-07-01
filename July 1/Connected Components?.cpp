/*
	Date: 1
	Time: ??
	Learnt: DSU -> >=0 in parent function if 0 indexed 
	Rating: 2100
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
	dsu(int n){
		rsz(parent , n+1 , -1);
	}
	int get(int a){
			return parent[a]>=0?parent[a] = get(parent[a]):a;
	}
	int size(int a)
	{
			return -parent[get(a)];
	}
	bool connected(int a , int b){
			return get(a) == get(b);
	}
	void connect(int a , int b){
		int pA = get(a) , pB = get(b);
		if(pA==pB)
			return;
		if(parent[pA] > parent[pB])
			swap(pA , pB);
		parent[pA]+=parent[pB];
		parent[pB] = pA;
	}	
};
int n , m;
vector<set<int>> adj;
void solve(){
	cin >> n >> m;
	set<int> yet;
	adj.resize(n);
	for(int i=0 ;i<m;i++){
			int a , b;
			cin >> a >> b , --a , --b , adj[a].insert(b) , adj[b].insert(a);
			//yet.insert(i);
	}
	for(int i =0;i<n;i++)
		yet.insert(i);
	dsu graph(n);
	vi visited(n);
	for(int i =0;i<n;i++){
			if(!visited[i]){
					queue<int> q;
					q.push(i);
					visited[i] = 1;
					yet.erase(i);
					while(sz(q)){
							auto next = q.front();
							//cout << next << " ";
							q.pop();
							vi erasing;
							for(int t : yet){
								if(adj[next].count(t)==0 && !visited[t]){
										visited[t] = 1;
										erasing.pb(t);
										graph.connect(next  ,t);
										q.push(t);
								}
							}
							for(int& d : erasing)
								yet.erase(d);
					}
			}
	}
	set<int> parents;
	vi ans;
	for(int i =0;i<n;i++){
			if(parents.count(graph.get(i)))
				continue;
			//cout << i << " " << graph.get(i) << " " <<graph.size(i) << " " << "\n";;
			parents.insert(graph.get(i));
			ans.pb(graph.size(i));
	}
	sort(all(ans));
	cout << sz(ans) << "\n";
	for(int& d : ans)
		cout << d<< " ";
	
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}
 
