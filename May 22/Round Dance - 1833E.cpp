//https://codeforces.com/contest/1833/problem/E
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
int n;
int arr[2*(int)1e5];
vector<bool> visited;
int dfs(int curr , vector<int>& time){
	visited[curr] = true;
	time[curr] = true;
	if(!visited[arr[curr]-1])
		return dfs(arr[curr]-1 , time);
	return (time[arr[curr]-1]?1:0);
}
int getMax(){
	int count = 0;
	visited.resize(0);
	visited.resize(n);
	for(int i =0 ;i<n;i++){
		if(!visited[i]){
			vector<int> vis(n);
			count+=dfs(i , vis);
			
		}
	}
	return count;
}
void solve(){
	cin >> n;
	for(int i = 0 ; i<n;i++)
		cin >> arr[i];
	int num = getMax();
	int countTwo = 0;
	for(int i = 0 ; i<n;i++)
		if(arr[arr[i]-1]-1==i)
			countTwo++;

	cout << num - (countTwo/2)+(countTwo?1:0) << " ";
	cout <<num  <<"\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
