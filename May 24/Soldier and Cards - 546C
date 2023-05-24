//https://codeforces.com/problemset/problem/546/C
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
	int n;
	cin >> n;
	deque<int> p1 , p2;
	int a;
	cin >> a;
	for(int i = 0 ; i<a;i++){
		int b;
		cin >> b;
		p1.push_front(b);
	}
	cin >> a;
	for(int i = 0;i<a;i++){
		int b;
		cin >> b;
		p2.push_front(b);
	}
	int count  = 0;
	while(count!=100000 && p1.size() && p2.size()){
		int o = p1.back() , t = p2.back();
		p1.pop_back();
		p2.pop_back();
		if(o>t){
			p1.push_front(t);
			p1.push_front(o);
		} else {
			p2.push_front(o);
			p2.push_front(t);

		}
		count++;
	}
	if(p1.size() && p2.size())
		cout << -1;
	else 
		cout << count << " " << (p1.size()?1:2);
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
