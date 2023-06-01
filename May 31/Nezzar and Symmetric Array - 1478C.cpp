//https://codeforces.com/contest/1478/problem/C
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define f first
#define s second
#define clr(x) x.clear()
#define rsz(x ,n) x.resize(0); x.resize(n);
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

void solve(){
	int n;
	cin >> n;
	vector<ll> sums(2*n);
	for(int i = 0 ;i<2*n;i++)
		cin >> sums[i];
	sort(sums.begin() , sums.end(),  greater<ll>());
	if(sums[0]!=sums[1]||sums[0]%(2*n)){
		cout << "NO\n";
		return;
	}	
	ll curr = 2*n-2;
	ll a = sums[0]/(2*n);

	ll last = a;
	for(int i = 2 ;i<2*n;i+=2){
		if(sums[i]!=sums[i+1]){
			cout << "NO\n";
			return;
		}
		if((sums[i]-2*a)%curr==0){
			ll b = (sums[i]-2*a)/curr;
			if(b>=last || b<=0)
				goto bad;
			last = b;
			a+=b;
			curr-=2;
		} else {
			bad:;
			cout << "NO\n";
			return;
		}
		
	}
	cout << "YES\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
