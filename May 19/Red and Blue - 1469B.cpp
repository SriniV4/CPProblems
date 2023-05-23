//https://codeforces.com/contest/1469/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}

void solve(){
	int n , m;
	cin >> n ;
	ll sum = 0 , ans = 0;
	for(int i = 0;  i<n;i++){
		int a;
		cin >> a;
		sum+=a;
		ans = max(ans  , sum);
	}
	sum = 0;
	cin >> m;
	ll temp = 0;
	for(int i = 0; i<m;i++){
		int a;
		cin >> a;
		sum+=a;
		temp = max(temp , sum);
	}
	//cout << ans << " ";
	cout << temp + ans << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}





