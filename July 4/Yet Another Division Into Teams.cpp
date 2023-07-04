/*
	Date: 04.07.2023
	Time: 30
	Learnt: Remember to look for 1/0 indexing -> Notice in the problem how you can't build a n*teams array -> observation that teams cant exceed 5 makes it n*6 which is speeds up both the time and space
	Rating: 2000
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcount(x)
#define tbits(total_size , num) total_size - __builtin_clz(num)
#define pb push_back
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<ll , ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
#define rsz(ds ,size , val) ds.assign(size , val);
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
using namespace std;
uint64_t time() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
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
	vpi arr(n);
	for(int i =0;i<n;i++)
		cin >> arr[i].f , arr[i].s = i;
	vector<vll> dp(n+1 , vll(6 , INT64_MAX/3));
	//dp[i][j] -> best answer for i indexes size j
	dp[0][3] = 0;
	sort(all(arr));
	for(int i =1;i<=n;i++){
			int ind = i-1;
			for(int j =1;j<=5;j++){
				if(i-j<0)
					continue;
				for(int k = 3;k<=5;k++)
					dp[i][j] = min(dp[i][j], dp[i-j][k] + arr[ind].f-arr[ind-j+1].f);
			}
	}
	//for(int i =0;i<=n;i++){
		//for(int j=0;j<=5;j++)
			//cerr << dp[i][j] << " ";
		//cerr << "\n";
	//}
	ll ans = INT_MAX;
	int pointer = n;
	int count = 0;
	vi answer(n+1);
	while(pointer){
			ans = INT_MAX;
			int num = 0;
			for(int i = 3;i<=5;i++)
				if(dp[pointer][i]<ans)
					num = i , ans = dp[pointer][i];
			cerr << num << "\n";
			for(int i = pointer;i>pointer-num;--i)
				answer[arr[i-1].s+1] = count , cerr << i << arr[i-1].s << "\n";
			count++;
			pointer-=num;
	}
	cout << min({dp[n][3] , dp[n][4] , dp[n][5]}) << " " << count << "\n";
	for(int i =1 ; i<=n;i++)
		cout << answer[i]+1 << " ";
	
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

