/*
	Date: 27.06.2023
	Time: ?
	Learnt: If you know answer is in a range -> you can search the entire range if you have time!
	Rating: 1700
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
pi get(int x){
		int sq = (int)sqrt(x);
		return {sq , ceil(x/(ld)sq)};
}
void solve(){
	int x , y;
	cin >> x >> y;
	auto a = get(x) , b = get(y);
	ll mx = max(a.f , b.f);
	const ll leeway = 1e6;
	ll ans = INT64_MAX;
	for(ll i = max(1ll , mx-leeway/2);i<=mx+leeway/2;i++){
			ans = min(ans , i-1 + (ll)ceil(x/(ld)i) + (ll)ceil(y/(ld)i));
	}
	cout << ans << "\n";
}

int main(){
	setIO();
	int t = 1;
 	cin >> t;
	while(t--){
		solve();
	}	
}

