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
		int get(int curr)
		{
				return (parent[curr]>=0?parent[curr] = get(parent[curr]):curr);
		}
		bool connected(int a , int b){
				return get(a)==get(b);
		}
		int size(int a)
		{
				return -parent[get(a)];
		}
		void connect(int a , int b){
				int pA = get(a) , pB = get(b);
				if(parent[pA]>parent[pB])
					swap(pA , pB);
				parent[pA]+=parent[pB];	
				parent[pB] = pA;
				//cout << parent[pA] << " " << parent[pB] << "\n";
		}
};
void solve(){
	int n, q;
	cin >> n >> q;
	dsu graph(n);
	for(int i=0;i<q;i++){
			cout.flush();
			int t;
			cin >> t;
			int a , b;
			cin >> a >> b;
			if(t)
				cout << graph.connected(a , b) << "\n";
			else 
			//if(!graph.connected(a,b))
				graph.connect(a , b);
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

