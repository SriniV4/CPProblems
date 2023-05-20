//https://codeforces.com/contest/1486/problem/A
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i =0 ; i<n;i++){
		cin >> arr[i];
	}
	ll sum = 0;
	for(int i = 0 ;i<n;i++){
		sum+=arr[i];
		if(sum<(i*(i+1))/2)
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}




