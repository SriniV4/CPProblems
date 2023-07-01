/*
	Date: 29th
	Time:Contest
	Learnt: Don't get stuck on one approach. What makes ths problem hard?
	Rating:?
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

void solve(){
	int n;
	cin >> n;
	ll total = 0;
	vll arr;
	for(int i=0;i<n;i++){
			ll a;
			cin >> a;
			if(total==0)
				total+=a;
			else if((total>0) == (a>0))
				total+=a;
			else{
					arr.pb(total);
					total = a;
			}
	}
	arr.pb(total);
	n = sz(arr);
	if(n==1)
		cout << 0 << "\n";
	else {
			vll prefix(n+1);//prefix[i] -> sum of first i elements
			for(int i =1 ; i<=n;i++)
				prefix[i] = prefix[i-1] + arr[i-1];
			vll dp(n+2) , real(n+2);//dp[0] = 0, dp[n+1] = 0
			dp[n+1] = 0;
			dp[n] = max(0ll , arr[n-1]);
			dp[0] = 0;
			real[n] = arr[n-1];
			for(int i = n-1;i>=1;--i){
					real[i] = real[i+1] + arr[i-1];
					dp[i] = max(max(0ll , real[i]) , dp[i+1]);
			}
			//for(int i=0;i<=n+1;i++)
				//cout << dp[i] << " ";
			//cout << "\n";
			//for(int i=0;i<=n+1;i++)
				//cout << real[i] << " ";
			//cout << "\n";

			ll maxHealth = dp[1] , k = 0;
			//dp[i] = delta of rating i -> rating n ( 1 ind ) 
			for(int i =1;i<=n;i++){
					ll thresh = prefix[i];
					ll health = prefix[i] + dp[i+1];
					if(health>maxHealth){
							k = thresh;
							maxHealth = health;
					}
			}
			cerr<< maxHealth << " ";
			cout << k << "\n";
	}
}

int main(){
	setIO();
	int t = 1;
 	cin >> t;
	while(t--){
		solve();
	}	
}

