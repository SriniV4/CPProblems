/*
	Date: 28.06.2023
	Time: 30
	Learnt: Always look at bounds -> If something requires only prime( others dont matter ) -> dont iterate over all factors 
	Rating: 1600
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
int prime_tab[(int)1e7];
void sieve(){
	for(int i =2 ; i<1e7;i++){
			if(prime_tab[i]==0){
					prime_tab[i] = i;
					for(int j = i+i;j<1e7;j+=i)
						prime_tab[j] = i;
			}
	}
}	
void solve(){
	int x , y;
	cin >> x >> y;
	int diff = y-x;
	//find smallest k such that gcd(x+k , diff)!=1
	//x+k ( mod diff ) = 0 in diff - x%diff moves
	//since we are finding gcd -> we want to find closest factor of diff
	int ans = INT_MAX;
	while(diff!=1){
			int fact = prime_tab[diff];
			ans = min(ans , (fact - x%fact)%fact);
			diff/=fact;
	}
	if(ans==INT_MAX)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}

int main(){
	setIO();
	sieve();
	int t = 1;
 	cin >> t;
	while(t--){
		solve();
	}	
}

