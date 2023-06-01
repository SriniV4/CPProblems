/*
  Time: 20:32
  Num Submissions: 1
  Learnt: Don't jump to conclusion without proof
  Time Complexity : O(N)
  Editorial : Find Half-Segments and find intersections ( O(NlogN) )
  Rating: 1700
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
int n ;
vector<ll> k , h;
void solve(){
	cin >> n;
	rsz(k , n);
	rsz(h , n);
	for(int i = 0 ; i<n;i++)
		cin >> k[i];
	
	for(int i = 0 ; i<n;i++)
		cin >> h[i];
	vector<pair<int , int>> suffix(n+1);
	suffix[n] = {k[n-1]-h[n-1] ,n-1};
	for(int i = n-1;i>0;--i){
		if(k[i-1]-h[i-1]<suffix[i+1].f){
			suffix[i] = {k[i-1]-h[i-1] , i-1};
		} else
			suffix[i] = suffix[i+1];
	}
	int pointer = 1;
	ll answer = 0;
	ll currSec = 0;
	ll currSize = 0;
	while(pointer<=n){
		int min = suffix[pointer].f;
		int ind = suffix[pointer].s;
		int required = h[ind];
		if(required>k[ind]-currSec){
			ll amount = currSize + (k[ind] - currSec);
			answer+=(amount*(amount+1))/2 - (currSize * (currSize+1))/2;
			currSec = k[ind];
			currSize = amount;
		} else {
			currSec = k[ind];
			currSize = h[ind];
			answer+=h[ind]*(h[ind]+1)/2;
		}
		pointer = ind+2;
	}
	cout << answer << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
