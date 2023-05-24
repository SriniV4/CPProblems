//https://codeforces.com/problemset/problem/1332/A
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
int a , b , c , d ,x , y, x1 , x2 , yy , y2;
bool valid(int u , int v){
	return x1<=u && x2>=u && yy<=v && y2>=v;
}
void solve(){
	cin >> a >> b >> c >> d;
	cin >> x >> y >> x1 >> yy >> x2 >> y2;
	x2-=x;
	x1-=x;
	y2-=y;
	yy-=y;
	if(c!=0 || d!=0){
		if(!(valid(0,1) || valid(0,-1))){
			cout << "NO\n";
			return;
		}
	}
	if(a!=0 || b!=0){
		if(!(valid(1,0) || valid(-1,0))){
			cout << "NO\n";
			return;
		}
	}
	if(!valid(b-a ,  d-c)){
		cout << "NO\n";
	} else 
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
