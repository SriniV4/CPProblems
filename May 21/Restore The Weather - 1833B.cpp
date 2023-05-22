//https://codeforces.com/problemset/problem/1833/B
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
	int n , k;
	cin >> n >> k;
	vector<pair<int , int> > p(n) , a(n);
	for(int i = 0; i<n;i++){
		cin >> p[i].first;
		p[i].second = i;
	}	
	for(int i = 0; i<n;i++){
		cin >> a[i].first;
		a[i].second = i;
	}	
	sort(a.begin() , a.end());
	sort(p.begin() , p.end());
	vector<int> answer(n);
	for(int i = 0; i<n;i++){
			answer[p[i].second] = a[i].first;
	}
	for(int i = 0; i<n;i++)
		cout << answer[i] << " ";; 
	cout << "\n";
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
