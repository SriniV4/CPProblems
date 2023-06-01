//https://codeforces.com/contest/1352/problem/G
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
	cin >>n ;
	switch(n){
	    case 1:
	        cout << "1\n";
	        break;
	    case 2 : case 3:
	        cout << "-1\n";
	        break;
	   default:
	            for(int i = (n%2?1:2); i<=n;i+=2)
	                cout << i << " ";
	            cout << n-3 << " " << n-1 << ' ';
	            for(int i = n-5;i>=(n%2?2:1);i-=2)
	                cout << i << ' ';
	           cout << "\n";

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
