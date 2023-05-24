//https://codeforces.com/problemset/problem/1203/B
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
	int n;
	cin >> n;
	map<int , int> counts;
	for(int i = 0 , a ;i<4*n;i++)
	{
		cin >> a;
		counts[a]++;
	}
	vector<int> num;
	for(auto& item : counts){
		if(item.second%2){
			cout << "NO\n";
			return;
		}
		for(int i = 0 ; i<item.second/2;i++){
			num.push_back(item.first);
		}
	}
	int left = 0 , right = num.size()-1;
	int goal = num[left]*num[right];
	while(left<right){
		if(num[left]*num[right]==goal){
			left++;
			right--;
		} else {
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
	while(t--){
		solve();
	}	
}
