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
/**********************************************************************/
int xP[] = {0,0,1,-1,1,1,-1,-1} , yP[] = {1,-1,0,0,1,-1,-1,1};
int n ,m;
string grid[1000];
void flood(int x , int y){
		grid[x][y] = '#';
		// (x+1,y) , (x-1,y) , (x,y+1) , (x,y-1)
		for(int i = 0;i<4;i++){
				int nX = x+xP[i] , nY = y+yP[i];
				if(nX>=0 && nY>=0 && nX<n && nY<m && grid[nX][nY]=='.'){
						flood(nX,nY);
				}
		}
}
void solve(){
	cin >> n >> m;
	for(int i = 0;i<n;i++){
			cin >> grid[i];
	}	
	int answer = 0;
	for(int i =0;i<n;i++){
			for(int j =0;j<m;j++){
					if(grid[i][j]=='.'){
						flood(i , j);
						answer++;
					}	
			}
	}
	cout << answer << "\n";
}

int main(){
	setIO();
	int t = 1;
// 	cin >> t;
	while(t--){
		solve();
	}	
}

