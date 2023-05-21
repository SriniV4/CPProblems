//https://codeforces.com/problemset/problem/978/C
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
int n ,m;
ll arr[2*(int)1e5];
vector<ll> prefix;
int bin(ll val){
	int left = 1 , right = n , answer = 0;
	while(left<=right){
		int middle = left + (right-left)/2;
		//cout << prefix[middle] << " ";
		if(prefix[middle]<=val){
			answer = middle;
			left = middle+1;
		} else
			right = middle -1;
	}
	return answer;
}
void solve(){
	cin >> n >> m;
	for(int i = 0 ; i<n;i++)
		cin >> arr[i];
	prefix.resize(0);
	prefix.resize(n+1);
	prefix[0] = 1;
	for(int i = 1 ; i<=n;i++){
		prefix[i] = prefix[i-1] + arr[i-1];
	}
	for(int i = 0 ; i<m;i++){
		ll num;
		cin >> num;
		int answer = bin(num);
		cout << answer+1 << " " << num-prefix[answer]+1 << "\n";
	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
