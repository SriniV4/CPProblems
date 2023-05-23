//https://codeforces.com/contest/1409/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}

void solve(){
	ll a, b , x , y , n;
	cin >> a >> b >> x >> y >> n;
	if(a-x + b-y <=n)
		cout << x*y << "\n";
	else {
	    cout << min(max(y , b-n)*(a-(n-(b-max(y,b-n)))) , max(x , a-n)*(b-(n-(a-max(x,a-n))))) << "\n";
	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}






