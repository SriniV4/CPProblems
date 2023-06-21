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
#define sz(i) i.size()
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
ll choose(ll a , ll b){
		ll ans = 1;
		ll counter = 2;
		for(ll i = a;i>a-b;i--){
			ans*=i;
				while(counter<=b && ans%counter==0)
					ans/=(counter++);
		}
		for(ll i = counter; i<=b;i++)
			ans/=i;
		return ans;
}
void solve(){
	ll n, m , t;
	cin >>n >> m >> t;
	 ll answer = 0;
	 for(int i = 4;i<=n;i++){
			// i = #boys
			int girls = t-i;
			if(girls>m || girls<1)
				continue;
			answer+=(choose(n , i) * choose(m , girls));
	 }
	 cout << answer << "\n";
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

