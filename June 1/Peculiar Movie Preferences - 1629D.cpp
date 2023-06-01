/*
  Time: ???
  Num Submissions: 4
  Learnt: 
    Implementation: Make sure to use apprioriate ds and don't overcomplicate it
  Time Complexity : O(Nlog(N))
  Editorial : Same
  Rating: 1700
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define f first
#define s second
#define clr(x) x.clear()
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

int n;
vector<string> arr;
string rev(string other){
	string total = "";
	for(int i = other.length()-1;i>=0;--i)
		total+=other[i];
	return total;
}
void solve(){
	cin >> n;
	map<string , vector<int>> exists;
	rsz(arr , n);
	for(int i = 0 ;i<n;i++){
		cin >> arr[i];
		exists[rev(arr[i])].pb( i+1);
	}
	for(int i = 0;i<n;i++){
		string d = arr[i];
		if(d.length()==1){
			cout << "YES\n";
			return;
		} if(d.length()==2){
			if(exists[(d)].size()){
				cout << "YES\n";
				return;
			}
		} else {
			if(exists[d.substr(1,2)].size() && exists[d.substr(1,2)][0]<=i || exists[(d)].size() || exists[d.substr(0,2)].size() && exists[(d.substr(0,2))][(int)exists[d.substr(0,2)].size()-1]>i){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
