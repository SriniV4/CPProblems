/*
	Date: 06.06.2023
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define trav(a , b) for(auto&b : a)
#define f first
#define s second
#define clr(x) x.clear()
#define all(a) a.begin() , a.end()
#define pi pair<int , int>
#define vi vector<int>
#define rsz(x ,n) x.resize(0); x.resize(n);
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
bool valid(int time , vi arr , int n){
		int o = arr[0]+time;
		int pointer = 0;
		//int counter = 1;
		while(pointer < n && abs(arr[pointer]-o)<=time){
				pointer++;
		}
		if(pointer==n)
			return true;
		o = arr[pointer]+time;
				while(pointer < n && abs(arr[pointer]-o)<=time){
				pointer++;
		}
		if(pointer==n)
			return true;
		o = arr[pointer]+time;
				while(pointer < n && abs(arr[pointer]-o)<=time){
				pointer++;
		}
		if(pointer==n)
			return true;

	return false;
}
void solve(){
	int n;
	cin >> n;
	set<int> num;
	for(int i = 0;i<n;i++)
	{
			int a;
			cin >> a;
			num.insert(a);
	}
	vi arr;// split into [0,split1) , [split1 , split2) , [split2 , sz-1);
	trav(num,  d)
		arr.pb(d);
	n = arr.size();
	int left =0 , right = arr[n-1] , answer = -1;
	while(left<=right){
			int mid = left+(right-left)/2;
			if(valid(mid , arr , n)){
					right = mid-1;
					answer = mid;
			} else
				left = mid+1;
	}
	cout << answer << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
