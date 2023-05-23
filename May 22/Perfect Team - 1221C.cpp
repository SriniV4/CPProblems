//https://codeforces.com/problemset/problem/1221/C
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
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
	int c , m , x;
	cin >> c >> m >> x;
	int maxT = min(c,m);
	if(x>=maxT)
		cout << maxT << '\n';
	else {
		int needed = maxT - x;
		int extra = max(c,m)-maxT;
		if(extra >=needed)
			cout << maxT << "\n";
		else {
			m-=x;
			c-=x;
			if(min(m,c)*2<=max(m,c))
				cout << min(m,c) + x << "\n";
			else {
				int temp = max(c,m)-min(c,m);
				c = min(c,m);
				m = min(c,m);
				c-=temp;
				m-=temp;
				int ans = min(m,c)/3 * 2;
				m-=ans/2*3;
				c-=ans/2*3;
				if(c &&  m && c+m>=3)
					ans++;
				cout << ans  + x + temp<< "\n";
			}

		}
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
