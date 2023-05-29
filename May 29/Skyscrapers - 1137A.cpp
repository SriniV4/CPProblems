//https://codeforces.com/contest/1137/problem/A
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
int bin(vector<int>& arr , int num){
	int left = 0 , right =arr.size()-1;
	while(left<=right){
		int mid = left+(right-left)/2;
		if(arr[mid]==num)
			return mid;
		if(arr[mid]>num)
			right = mid-1;
		else 
			left = mid+1;
	}
	return -1;
}
int n ,m;
void solve(){
	cin >> n >> m;
	vector<vector<int>> row(n);
	vector<vector<int>> col(m);
	vector<vector<int>> street(n , vector<int>(m));
	for(int i = 0;i<n;i++){
		unordered_map<int , bool> seen;
		for(int j = 0;j<m;j++){
			cin >> street[i][j];
			if(!seen[street[i][j]])
				row[i].push_back(street[i][j]);
			seen[street[i][j]] = true;
		}
		sort(row[i].begin() , row[i].end());
	}
	for(int i = 0;i<m;i++)
	{
		unordered_map<int , bool> seen;
		for(int j= 0;j<n;j++){
			if(!seen[street[j][i]])
				col[i].push_back(street[j][i]);
			seen[street[j][i]] = true;
		}
		sort(col[i].begin() , col[i].end());
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int a = bin(row[i] , street[i][j]) , b = bin(col[j] , street[i][j]);
			cout << max((int)max(row[i].size(),col[j].size()) , max(a +(int) col[j].size()-b , b+(int)row[i].size()-a)) << " ";
			continue;
			if(a==0 && b==0 || a==row[i].size()-1 && b==col[j].size()-1 || (row[i].size()==1 || col[j].size()==1))
				cout << max(row[i].size() , col[j].size()) << " ";
			else if(a==0 && b==col[j].size()-1 || b==0 && a==row[i].size()-1)
				cout << row[i].size()+col[j].size()-1 << " ";
			else
			cout << (max(row[i].size() , col[j].size())+max(a,b)-min(a,b)) << " ";
		}
		cout << '\n';
	}
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
