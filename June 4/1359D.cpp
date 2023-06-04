/*
	Date: 04.06.2023
	Time: 30:00
	Learnt: 
		Kadane -> O(N) Max Sum
		Look for Input Specifications -> Low ai
	Rating: 2000
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define f first
#define s second
#define clr(x) x.clear()
#define rsz(x ,n) x.resize(0); x.resize(n);


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
void solve(){
	cin >> n;
	vector<int> arr(n);
	set<int> unique;
	for(int i = 0;i <n;i++)
	{
			cin >> arr[i];
			unique.insert(arr[i]);
	}
	int answer =0;
	for(int d : unique){
		vector<int> temp(arr);
		for(int i = 0;i<n;i++)
			if(temp[i]>d)
				temp[i] = -10000;
		int sum = -31;
		int maxSum = -10000;
		for(int i = 0;i<n;i++){
			sum = max(temp[i] , sum+temp[i]);
			maxSum = max(maxSum , sum);
		}
		cerr << maxSum << " " << d << " ";
		answer =max(answer , maxSum - d);
	}	
	cout << answer << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
