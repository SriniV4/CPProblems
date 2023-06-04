/*
  Time: 8:00
  Learnt:
    a ) Binary Lifting -> QLog(N) Queries -> Use Bitwise representation of number and precompute paths of 1,2,4,.... ( powers of 2 )
    b ) Remember to stay constant in indexing -> 1 or 0 indexing 
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
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
int n , q;
int bin[2*(int)1e5][31];
void binLift(){
	int curr = 1;
	while(curr<31){
		for(int i =0 ; i<n;i++)
			bin[i][curr] = bin[bin[i][curr-1]][curr-1];
		curr++;
	}
	/*for(int i = 0 ; i<2;i++){
		for(int j =0 ;j<n;j++)
			cout << bin[j][i] <<" ";
		cout << "\n";
	}*/
}
void solve(){
	cin >> n >> q;
	for(int i = 0 ; i<n;i++){
		cin >> bin[i][0];
		bin[i][0]--;
	}
	binLift();
	for(int i = 0 ;i<q;i++){
		int x , k;
		cin >> x >> k;
		int planet = x-1;
		int bitCount = 0;
		while(k){
			if(k&1)
				planet = bin[planet][bitCount];
			k>>=1;
			bitCount++;
		}
		cout << planet+1 << '\n';
	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
