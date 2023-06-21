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
				rsz(parent , n , -1);
		}
		int get(int a){
				return parent[a]>0?parent[a] = get(parent[a]):a;
		}
		int size(int a){
				return -parent[get(a)];
		}
		bool connected(int a , int b){
				return get(a)==get(b);
		}
		void connect(int a, int b){
				int pA = get(a) , pB = get(b);
				if(pA==pB)
					return;
				if(parent[pA]>parent[pB])
					swap(pA , pB);
				parent[pA]+=parent[pB];
				parent[pB] = pA;
		}
};
void solve(){
	int n , m;
	cin >> n >> m;
	vi arr(n);
	trav(a , arr)
		cin >> a;
	dsu graph(n+1);
	priority_queue<pair<int , pi>> edges;
	for(int i =0 ;i<m;i++){
			int a,b ,c;
			cin >> a >> b >> c;
			edges.push({c,{a,b}});
	}
	int bad = 0;
	int bI = -1;
	for(int i =0;i<n;i++)
		if(arr[i]!=i+1){
			bad++;
			bI = i+1;
		}
	if(bad==0){
			cout << -1 << '\n';
			return;
	}
	int good = 0;
	while(sz(edges)){
			//goal is to get componenetSize == bad
			auto next=  edges.top();
			edges.pop();
			int a = next.s.f , b = next.s.s;
			if(arr[a-1]==a && arr[b-1]==b)
				continue;
			if(graph.connected(a,b))
				continue;
			if(arr[a-1]==a){
				if(graph.size(a)==1)
					good++;
			} else if(arr[b-1]==b){
				if(graph.size(b)==1)
					good++;

			}
			graph.connect(a , b);
			if(graph.size(bI) == bad + good){
					cout << next.f << '\n';
					return;
			}
	}
}

int main(){
	setIO("wormsort"	);
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

