/*
	Date: 
	Time:
	Learnt:
	Rating:
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define PI 3.14159265358979323846
#define sbits(x) __builtin_popcount(x)
#define tbits(total_size , num) total_size - __builtin_clz(num)
#define pb push_back
#define trav(name , ds) for(auto&name : ds)
#define f first
#define s second
#define clr(ds) ds.clear()
#define all(ds) ds.begin() , ds.end()
#define pi pair<int , int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define sz(i) (int)i.size()
#define rsz(ds ,size , val) ds.assign(size , val);
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
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
string grid[1000];
int answer[1000][1000];
void solve(){
	int n  , m;
	cin >> n >> m;
	pi start = {0,0}, end = {0,0};
	for(int i = 0;i<n;i++){
		cin >> grid[i];
		for(int j = 0;j<m;j++)
		{ 
			if(grid[i][j]=='A'){
					start = {i,j};
			}
			if(grid[i][j]=='B')
				end = {i,j};
			
	}
	}
	queue<pi> q;
	q.push(start);
	while(q.size()){
			auto next = q.front();
			q.pop();
			for(int i = 0 ;i<4;i++){
					int nX = next.f+xP[i] , nY = next.s+yP[i];
					if(nX>=0 && nY>=0 && nX<n && nY<m && !answer[nX][nY] && grid[nX][nY]!='#'){
							answer[nX][nY] = i+1;
							q.push({nX , nY});
					}
			}
	}
	string dir[4] = {"R","L","D","U"};
	if(answer[end.f][end.s]){
			cout << "YES\n";
			vector<string> ans;
			while(end!=start){
					int num = answer[end.f][end.s]-1;
					ans.pb(dir[num]);
					end.f-=xP[num];
					end.s-=yP[num];
			}
			
			cout << sz(ans) << "\n";
			while(sz(ans)){
				cout << ans.back();ans.pop_back();
}	}
		else
			cout << "NO\n";
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

