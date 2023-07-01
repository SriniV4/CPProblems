/*
	Date: 
	Time:
	Learnt: Finding smallest k such that k>mx and k%a == sx%a -> casework ( dont forget % everywhere )
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
struct seg{
		vi tree;
		int n;
		seg(vi arr){
			n = sz(arr);
			while(sbits(n)!=1){
				arr.pb(0);
				n++;
			}
			rsz(tree , 2*n , INT_MIN);
			for(int i=n;i<2*n;i++)
				tree[i] = arr[i-n];
			for(int i =n-1;i>=0;--i)
				tree[i] = max(tree[i*2] , tree[i*2+1]);
		}
		int get(int l , int r){
				return query(1 , n , l , r , 1);
		}
		int query(int nL , int nR , int qL , int qR , int node){
				if(nL>qR || nR<qL)
					return INT_MIN;
				if(nL>=qL && nR<=qR)
					return tree[node];
				return max(query(nL , nL+(nR-nL)/2 , qL , qR , node*2) , query(nL+(nR-nL)/2+1 , nR , qL , qR , node*2+1));
		}
};
void solve(){
	int n ,m;
	cin >> n >> m;
	vi heights(m);
	for(auto& h : heights)
		cin >> h;
	int q;
	cin >> q;
	seg tree(heights);
	while(q--){
			int sx , sy , ex , ey , k;
			cin >> sx >> sy >> ex >> ey >> k;
			
			if(sx>ex)
				swap(sx , ex);
			if(sy>ey)
				swap(sy , ey);
			int d1 = ey-sy , d2  = sx-ex;
			if(d1%k || d2%k){
					cout << "NO\n";
					continue;
			}
			if(sy+1>ey-1){
					cout << "YES\n";
					continue;
			}
			int mx = tree.get(sy+1 , ey-1);
			//cout << mx << " ";
			if(sx>mx){
					cout << "YES\n";
					continue;
			}
			int mm = sx%k;
			int goal = 0;
			if(mm>mx%k){
				goal = mx + (mm - mx%k);
			} else if(mm!=(mx%k)){
					goal = (k-(mx%k))%k + mm+mx;
			} else
				goal = mx+k;
			//cout << goal << " ";
			if(goal<=n)
				cout << "YES\n";
			else
				cout << "NO\n";
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

