//https://codeforces.com/contest/1506/problem/E
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
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	int left = 1 , curr = 1, last = -1;
	vector<bool> seen(n);
	for(int i = 0;i<n;i++){
		if(last!=arr[i]){
			last = arr[i];
			cout << last << " ";
			seen[last-1] = true;
		} else {
			while(seen[left-1])
				left++;
			seen[left-1] = true;
			cout << left++ << " ";
		}
	}
	cout << "\n";
	seen.resize(0);
	seen.resize(n);
	stack<int> ind;
	last = -1 ;int right = -1 ;
	for(int i = 0;i<n;i++){
		if(last!=arr[i]){
			last = arr[i];
			ind.push(right);
			right = last-1;
			seen[last-1] = true;
			cout << last << " ";
		} else {
			while(seen[right-1]){
				right = ind.top();
				ind.pop();
			}
			seen[right-1] = true;
			cout << right-- << " ";
		}
	}
	cout << "\n";
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
