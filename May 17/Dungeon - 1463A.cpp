//https://codeforces.com/problemset/problem/1463/A
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}

void solve(){
	int a , b , c;
	cin >> a >> b >> c;
	int sum = a+b+c;
	if(sum%9)
		cout << "NO\n";
	else {
		int num = sum/9;
		cout << (a>=num && b>=num && c>=num?"YES\n":"NO\n");
	}
}	
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}
