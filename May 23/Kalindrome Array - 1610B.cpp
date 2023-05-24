//https://codeforces.com/contest/1610/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}
bool valid(int num , vector<int> &arr){
	int left =0 , right = arr.size()-1;
	while(right>=0 && left<arr.size() && left<=right){
		if(arr[left]==arr[right]){
			left++;
			right--;
		} else {
			if(arr[left]==num)
				left++;
			else if(arr[right]==num)
				right--;
			else return false;
		}
	}
	return right<=left;
}
void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i<n;i++)
		cin >> arr[i];
	int left =0 , right = n-1;
	while(left < right && arr[left]==arr[right]){
		left++;
		right--;
	}
	if(right<=left)
		cout << "YES\n";
	else {
		int poss1 = arr[left];
	//	cout << poss1 << " ";
		if(valid(poss1 ,arr) || valid(arr[right] , arr) ){
			cout << "YES\n";
		} else
		cout << "NO\n";
	}
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}
