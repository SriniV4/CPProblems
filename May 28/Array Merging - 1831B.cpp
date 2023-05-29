//https://codeforces.com/contest/1831/problem/B
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
	vector<int> a(n) , b(n);
	unordered_map<int , int> aC , bC;
	int prev = -1 , count = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
		if(a[i]!=prev){
			if(prev!=-1)
				aC[prev] = max(aC[prev] , count);
			count = 1;
			prev = a[i];
		} else
			count++;
		
	}
	if(count)
		aC[prev] = max(aC[prev] , count);
	prev = -1 , count = 0;
	for(int i = 0;i<n;i++){
		cin >> b[i];
		if( b[i]!=prev){
		if(prev!=-1)
			bC[prev] = max(bC[prev] , count);
			count = 1;
			prev = b[i];
		} else
			count++;
		
	}
	if(count)
		bC[prev] = max(bC[prev] , count);
	int answer = 0;
	for(auto item : aC){
		answer = max(answer ,item.second + bC[item.first]);
	}
	for(auto item : bC)
		answer = max(answer ,item.second + aC[item.first]);
	cout << answer << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
