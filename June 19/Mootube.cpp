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
	dsu(int n)
	{
			rsz(parent , n , -1);
	}
	int get(int a){
			return parent[a]>0?parent[a] = get(parent[a]):a;
	}
	int size(int a){
			return -parent[get(a)];
	}
	bool connected(int a, int b){
			return get(a)==get(b);
	}
	void connect(int a, int b){
			int pA = get(a), pB = get(b);
			if(pA==pB)
				return;
			if(parent[pA]>parent[pB])
				swap(pA , pB);
			parent[pA]+=parent[pB];
			parent[pB] = pA;
	}
};
void solve(){
	int n ,q;
	cin >> n >> q;
	priority_queue<pair<int , pi> , vector<pair<int ,pi>>> edges , queries;
	for(int i =0;i<n-1;i++){
			int a , b , w;
			cin >> a >> b >> w;
			edges.push({w , {a,b}});
	}
	for(int i =0;i<q;i++){
			int a , b;
			cin >> a >> b;
			queries.push({a,{b,i}});
	}
	dsu graph(n+1);
	vi answer(q);
	while(sz(queries)){
			auto next = queries.top();
			queries.pop();
			while(sz(edges) && edges.top().f>=next.f){
					auto temp = edges.top();
					edges.pop();
					graph.connect(temp.s.f , temp.s.s);
			}
			answer[next.s.s] = graph.size(next.s.f);
	}
	trav(a , answer)
		cout << a-1<< "\n";
}

int main(){
	setIO("mootube");
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

