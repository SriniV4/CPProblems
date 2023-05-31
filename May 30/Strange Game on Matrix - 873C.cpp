//https://codeforces.com/contest/873/problem/C
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
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

void solve(){
	int n , m ,k;
	cin >> n >> m >> k;
	vector<vector<int>> arr(n , vector<int>(m));
	for(int i = 0; i<n;i++)
		for(int j = 0;j<m;j++){
			cin >> arr[i][j];
		}
	int totalCost = 0 ,  ans = 0;
	for(int i= 0 ;i<m;i++){
		int ones = 0;
		int bestScore = 0 , cost = 0;
		for(int j= 0 ; j<n;j++){
			if(arr[j][i]==1)
				ones++;
			else
				continue;
			int score = 0;
			for(int l = j;l<min(j+k , n);l++){
				if(arr[l][i]==1)
					score++;
			}
			if(score>bestScore){
				bestScore = score;
				cost = ones-1;
			}
		}
		ans+=bestScore;
		totalCost +=cost;
	}
	cout << ans << " " << totalCost << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
