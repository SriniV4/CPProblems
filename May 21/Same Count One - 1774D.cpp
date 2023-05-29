//https://codeforces.com/contest/1774/problem/D
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
	int n ,m;
	cin >> n >> m;
	int ones = 0;
	vector<vector<int>> grid(n , vector<int>(m));
	vector<int> num(n);
	vector<pair<vector<int> , vector<int>>> counts(n);
	for(int i = 0;i<n;i++){
		for(int j = 0 ;j<m;j++){
			cin >> grid[i][j];
			if(grid[i][j]){
				ones++;
				counts[i].first.push_back(j+1);
			} else
				counts[i].second.push_back(j+1);
		}
		num[i] = counts[i].first.size();
	}
	if(ones%n)
		cout << -1 << '\n';	
	else {
		int ans = 0;
		int each = ones/n;
		vector<int> extra , less;
		for(int i = 0 ;i<n;i++)
			if(num[i]>each){
				ans+=num[i]-each;
				extra.push_back(i);
			} else if(num[i] < each)
				less.push_back(i);
		cout << ans << "\n";
		int eP = 0 , lP = 0 , ePP = 0 ;
		while(eP<extra.size() && lP<less.size()){
			while(num[extra[eP]]>each && num[less[lP]] < each){
				while(grid[extra[eP]][ePP]==grid[less[lP]][ePP] || grid[extra[eP]][ePP]==0)
					ePP = (ePP+1)%m;
				cout << extra[eP]+1 << " " << 1+less[lP] << " " << ePP+1 << "\n";
				grid[extra[eP]][ePP] = 0;
				grid[less[lP]][ePP] = 1;
				ePP = (ePP+1)%m;
				num[extra[eP]]--;
				num[less[lP]]++;
			}
			if(num[extra[eP]]>each)
				lP++;
			else 
				eP++;
		}
		
	}
}
int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}
