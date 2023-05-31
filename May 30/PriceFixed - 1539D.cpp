//https://codeforces.com/contest/1539/problem/D
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
	vector<array<ll , 2>> prod(n);
	ll sum =0 , sold = 0 , left =0 , right = n-1 , ans = 0;
	for(int i = 0;i<n;i++){
		cin >> prod[i][0] >> prod[i][1];
		sum+=prod[i][0];
	}
	sort(prod.begin() , prod.end() , [&](array<ll , 2> a , array<ll , 2> b){

	return	a[1] < b[1];
	});

	while(sum!=sold){
		while(sum!=sold && prod[left][1]<=sold){
			sold+=prod[left][0];
			ans+=prod[left][0];
			left++;
		}
		if(sum==sold)
			break;
		ll dif = prod[left][1]-sold;
		while(dif){
			ll temp = min(dif , prod[right][0]);
			prod[right][0]-=temp;
			sold+=temp;
			ans+=temp*2;
			dif-=temp;
			if(prod[right][0]==0)
				right--;
			if(sum==sold)
				break;
		}
	}
	cout << ans;
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
