//https://codeforces.com/contest/1492/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}

int getMax(vector<int>& arr , int right){
	int ind = 0;
	int m = arr[0];
	for(int i =1 ;i<right;i++){
		if(arr[i]>m){
			m = arr[i];
			ind = i;
		}
	}
	return ind;
}
void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0 ;i<n;i++)
		cin >> arr[i];
	int  right = n;
	vector<pair<int , int>> prefix(n);
	prefix[0] = {arr[0] , 0};
	for(int i =1 ;i<n;i++){
		if(arr[i]>prefix[i-1].first){
			prefix[i] = {arr[i] , i};
		} else {
			prefix[i] = prefix[i-1];
		}
	}
	while(right>0){
		int ind = prefix[right-1].second;
		for(int i = ind;i<right;i++){
			cout << arr[i] << " ";
		}
		right = ind;
	}
	cout << "\n";
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}
