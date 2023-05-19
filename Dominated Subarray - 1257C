//https://codeforces.com/problemset/problem/1257/C
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
	vector<int> arr(n);
	for(int i = 0 ; i<n;i++)
		cin >> arr[i];
	unordered_map<int , int> last;
	int answer = INT_MAX;
	for(int i = 0 ; i<n;i++){
		if(last[arr[i]]){
			answer = min(answer , i-last[arr[i]]+1);
		}
			last[arr[i]] = i+1;
	}
	cout << (answer==INT_MAX?-1:answer+1) << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
