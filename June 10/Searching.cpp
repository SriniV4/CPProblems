/*
	Date: 
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
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
//ll ans = 0;
ll compute(ll a , ll b){
	//cout << a << " " << b << "\n";
	//cout.flush();
	if(a>=b){
		ll ans = 0;
		while(a>b){
			if(a%2)
				a++;
			else
				a/=2;
			ans++;
		}
		return ans + (a==b?0:compute(a , b));
	
			
	}
		if(2*a>=b){
			ll dist = b-a;
			if((a%2?2:1) + (b%2?1:0) +1 + (b/2-(a+1)/2) < dist){
					return (a%2?2:1) + (b%2?1:0) +1 + compute((a+1)/2 , b/2); // always maintains a<=b relationship
			}
			return dist;	
		} else {				// 2*a<=b
			ll ans = 0;
			while(2*a<=b){
				if(b%2)
				{
						b^=1;
						ans++;
				} else{
						b>>=1;
						ans++;
				}
			}
			return compute(a , b) + ans;	
		} 
}

void solve(){
	ll a , b;
	cin >> a >> b;
	cout << compute(a,b) << "\n";
	
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
