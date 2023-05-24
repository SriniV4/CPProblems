//https://codeforces.com/problemset/problem/1271/B
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
	string line;
	cin >> line;
	bool arr[n];
	for(int i = 0 ; i<n;i++)
		arr[i] = line[i]=='B';
	bool temp[n] ;
	for(int i = 0 ;i<n;i++)
		temp[i] = arr[i];
	bool one = false , z = 0;
	vector<int> ans;
	for(int i = 0 ;i<n-1;i++){
		if(arr[i])
		{
			arr[i] = 0;
			arr[i+1]=!arr[i+1];
			ans.push_back(i);
		} 
	}
	if(arr[n-1]==0){
		cout << ans.size() << "\n";
		for(int d : ans)
			cout << d+1 << " ";
		cout << "\n";
		return;
	}
	ans.resize(0);
	for(int i = 0;i<n;i++)
		arr[i] = temp[i];
	for(int i= 0; i<n-1;i++){
		if(!arr[i]){
			arr[i] = 1;
			arr[i+1] = !arr[i+1];
			ans.push_back(i);
		}
	}	if(arr[n-1]==1){
		cout << ans.size() << "\n";
		for(int d : ans)
			cout << d+1 << " ";
		cout << "\n";
		return;
	}
	cout << -1;

}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
