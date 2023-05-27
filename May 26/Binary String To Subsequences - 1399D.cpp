//https://codeforces.com/contest/1399/problem/D
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
	string line;
	cin >> n;
	cin >> line;
	int count = 1;
	stack<int> z , o;
	vector<int> ans(n);
	for(int i = 0 ;i<n;i++){
		if(line[i]=='0'){
			if(z.size()==0){
				ans[i] = count;
				o.push(count++);
			} else {
				ans[i] = z.top();
				o.push(ans[i]);
				z.pop();
			}
		} else {

			if(o.size()==0){
				ans[i] = count;
				z.push(count++);
			} else {
				ans[i] = o.top();
				z.push(ans[i]);
				o.pop();
			}
		}
	}
	cout << count-1 << "\n";
	for(int d : ans)
		cout << d << " ";
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
