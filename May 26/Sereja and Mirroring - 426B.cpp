//https://codeforces.com/contest/426/problem/B
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
	int x , y;
	cin >> x >> y;
	int arr[x][y];
	for(int i= 0;  i<x;i++)
		for(int j = 0 ;j<y;j++)
			cin >> arr[i][j];
	int size = x;
	while(size%2==0){
		bool valid = true;
		for(int i = size/2-1;i>=0;--i){
			for(int j= 0 ;j<y;j++){
				if(arr[i][j]!=arr[size/2+(size/2-1-i)][j]){
					valid = false;
					goto done;
				}
			}
		}
		done:;	
		if(valid)
			size/=2;
		else
			break;
	}
	cout << size << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
