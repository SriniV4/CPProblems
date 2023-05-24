//https://codeforces.com/contest/1213/problem/B
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
for(int i = 0 ; i<n;i++)
	cin >> arr[i];
int count = 0;
int min = arr[n-1];
for(int i = n-1;i>=0;--i){
	if(arr[i]<min){
		min = arr[i];
		
	} else if(arr[i]>min)
		count++;

}	
cout << count << "\n";
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}
