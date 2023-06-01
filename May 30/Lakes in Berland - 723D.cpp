//https://codeforces.com/contest/723/problem/D
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
int n ,m , k;
string grid[50];
bool visited[50][50];
int xP[] = {1 , -1 , 0 , 0} , yP[] = {0,0,-1,1};
vector<pair<pair<int , int> , int>> lakes;
int dfs(int x , int y , int size , bool valid){
	visited[x][y] = 1;
	if(x==0 || x==n-1 || y==0 || y==m-1)
		valid = false;
	for(int i = 0 ;i<4;i++){
		int nX = xP[i] +x ,nY= yP[i]+y;
		if(nX>=0 && nX<n && nY>=0 && nY<m && !visited[nX][nY] && grid[nX][nY]=='.'){
			int num = dfs(nX , nY , size+1 , valid);
			if(num==-1)
				valid = false;
			size = max(num , size);
		}
	}
	return (valid?size:-1);
}
int ans = 0;
void fill(int x , int y){
	grid[x][y] = '*';
	ans++;
	for(int i = 0 ; i<4;i++){
		int nX = xP[i] +x ,nY= yP[i]+y;
		if(nX>=0 && nX<n && nY>=0 && nY<m  &&grid[nX][nY]=='.')
			fill(nX, nY);
		
	}
}
void solve(){
	cin >>n >> m >> k;
	for(int i = 0 ; i<n;i++)
		cin >> grid[i];
	for(int i = 0 ; i<n;i++){
		for(int j =0 ; j<m;j++){
			if(!visited[i][j] && grid[i][j]=='.'){
				int size = dfs(i , j , 0 , 1);
				if(size!=-1){
					lakes.push_back({{i,j},size});
				}
			}
		}
	}
	sort(lakes.begin() , lakes.end() , [&](pair<pair<int ,int> ,int> a , pair<pair<int , int> , int> b){
		return a.s < b.s;
	});
	//for(auto item : lakes)
	//	cout << item.f.f << " " << item.f.s <<" " <<  item.s << "  ";
	int rem = lakes.size()-k;
	for(int i = 0 ; i<rem;i++)
		fill(lakes[i].f.f , lakes[i].f.s);
	cout << ans << "\n";
	for(int i= 0 ; i<n;i++){
		cout << grid[i] << "\n";
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
