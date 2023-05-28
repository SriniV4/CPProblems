//https://codeforces.com/contest/1545/problem/A
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
	vector<int> arr(n);
	for(int i =0;i<n;i++)
		cin >> arr[i];
	vector<int> temp(arr);
	sort(temp.begin() , temp.end());
	map<int , vector<int> > ind;
	for(int i = 0 ; i<n;i++)
		ind[temp[i]].push_back(i);
	
	for(int i = 0 ;i<n;i++){
		bool done = false;
		auto& vec = ind[arr[i]];
		int val = -1;
		for(int& d : vec){
			if((d-i)%2==0){
				done = true;
				val = d;
				break;
			} 
		}
		if(done)
			vec.erase(find(vec.begin() , vec.end() , val));
		else {
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
