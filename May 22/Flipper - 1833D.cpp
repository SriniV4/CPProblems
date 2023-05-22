//https://codeforces.com/contest/1833/problem/D
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

/*
 *
 *Find max
 Better for suffix 
 or reverse
 Edge Cases : end or start
 *
 */
void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	int ind = -1 , ind2 = 0;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
		if(arr[i]==n)
			ind = i;
		if(arr[i]==n-1)
			ind2 = i;
	}	
	if(n==1){
		cout << 1 <<"\n";
		return;
	}
	if(ind!=0){
		int pointer = ind - (ind==1 || ind==n-1?1:2);
		while(arr[0]<arr[pointer]){
			pointer--;
		}	
		for(int i = ind ;i<n;i++)
			cout << arr[i] << " ";
		for(int i = ind-1;i>pointer;--i)
			cout << arr[i] << " ";
		for(int i = 0;i<=pointer;i++)
			cout << arr[i] << " ";
		cout << "\n";

	} else {
		int pointer = ind2- (ind2==1 || ind2==n-1?1:2);
		while(arr[0]<arr[pointer]){
			pointer--;
		}	
		for(int i = ind2 ;i<n;i++)
			cout << arr[i] << " ";
		for(int i = ind2-1;i>pointer;--i)
			cout << arr[i] << " ";
		for(int i = 0;i<=pointer;i++)
			cout << arr[i] << " ";
		cout << "\n";

	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
