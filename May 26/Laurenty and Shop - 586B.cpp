//https://codeforces.com/contest/586/problem/B
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
int street[2][50];
int mainS[50];
int n;
int m1 = INT_MAX , m2 = INT_MAX;
void dfs(int x , int y , int sum , bool crossed){
	if(x==0 && y==0){
		if(sum <=m1)
		{
			m2 = m1;
			m1 = sum;
		} else if(sum<=m2)
			m2 = sum;
	} else {
		if(y==0){
			if(!crossed)
				dfs(0, 0 , sum+mainS[0] , 1);
		}
		else {
			dfs(x , y-1 , sum+street[x][y-1] , crossed);
			if(!crossed)
				dfs(0 , y , sum+mainS[y] , 1);
		}
	}
}
void solve(){
	cin >> n;
	for(int i = 0;i<n-1;i++)
		cin >> street[0][i];
	for(int j= 0 ;j<n-1;j++)
		cin >> street[1][j];
	for(int i = 0;i<n;i++){
		cin >> mainS[i];
	}	
	m1 = INT_MAX;
	m2 = INT_MAX;
	dfs(1 , n-1 , 0 , 0);
	cout << m1+m2 << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
