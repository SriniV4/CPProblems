/*


*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define pb push_back
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
const int MAX = 31628;
bool prime_tab[MAX];
vector<int> primes;
void sieve(){
	memset(prime_tab , 1 , sizeof(prime_tab));
	prime_tab[1] = 0;
	for(int i = 2; i<MAX;i++){
		if(prime_tab[i])
			primes.pb(i);
		for(ll j = (ll)i*i;j<MAX;j+=i)
			prime_tab[i] = 0;
	}
}
int sumPow(int num){
	int cnt = 0;
	for(int prime : primes){
		while(num%prime==0){
			num/=prime;
			cnt++;
		}
		if(num==1)
			break;
	}
	return cnt + (num==1?0:1);
}
int getMax(int a ,int b){
	return sumPow(a)+sumPow(b);
}
void solve(){
	int a, b , k;
	cin >> a >> b >> k;
	int g = gcd(a,b);
	if(k==1 &&!(g==b ^ g==a))
	{
		cout << "NO\n";
		return;
	}
	int maxMoves = getMax(a,b);
	cout << (k<=maxMoves?"YES":"NO") << "\n";
}
int main(){
	setIO();
	int t = 1;
	sieve();
	cin >> t;
	while(t--){
		solve();
	}	
}
