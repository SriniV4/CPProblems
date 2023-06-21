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
vector<vi> adj;
vi diameter;
int dfs(int curr , int parent){
		int children = (adj[curr].size()-(parent==curr?0:1));//one edge = parent
		//cout << curr << " " << children << "\n";
		if(children==0){
				diameter[curr] = 1;
				return 1;
		} else {
			int mx = 0 , mx2 = 0;
				for(int child : adj[curr])
				{
						if(child==parent)
							continue;
						int c = dfs(child , curr);
						if(c >= mx)
						{
								swap(mx , mx2);
								mx = c;
						} else if(c>=mx2)
							mx2 = c;
				}

				diameter[curr] = mx+mx2+1;
				return mx+1;
				
		}
}
void solve(){
	int n;
	cin >> n;
	rsz(diameter , n , 0);
	rsz(adj , n , vi(0));
	for(int  i = 0;i<n-1;i++){
			int a , b;
			cin >> a >> b;
			adj[--a].pb(--b);
			adj[b].pb(a);
	}
	dfs(0 , 0);
	int mx = 0;
	trav(a , diameter){
		mx= max(a , mx);
		//cout << a << " ";
	}
	cout << mx-1 << "\n";
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

