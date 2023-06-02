/*
  Time: 34:00
  Num Submissions: 6
  Learnt: IMPLEMENTATION
  Time Complexity : O(N*M)
  Editorial : Same
  Rating: 2500
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
int n ,m;
string grid[1000];
int xP[] = {0,0,1,-1 , 1 , -1 , -1 , 1} , yP[] = {1,-1,0,0 , 1 , -1 , 1 , -1};
vector<vector<bool>> visited , visitedOnes;
int valid = 1 , reached = 0;
void flood(int x , int y , set<pair<int ,int>>& ones){
	for(int i =0 ; i<8;i++){
		int nX = xP[i] + x , nY = yP[i] + y;
		if(nX>=0 && nY>=0 && nX<n && nY<m && !visited[nX][nY]){
			if(grid[nX][nY]=='1')
				ones.insert({nX,nY});
			else
			{
				visited[nX][nY] = 1;
				flood(nX, nY , ones);
			}
		}
	}
}
void check(int x , int y , int pX , int pY , int sX , int sY , int s , set<pair<int ,int>>& ones , int &count){
	if(s && sX==x && sY==y){
		reached = 1;
		valid = (count==ones.size()?1:0);
		return;
	} 
	if(reached)
		return;;
	int cnt = 0;
	for(int i = 0 ; i<4;i++){
		int nX = xP[i] + x , nY = yP[i] + y;
		if(nX>=0 && nY>=0 && nX<n && nY<m  ){
			if(ones.count({nX,nY}))
				cnt++;
		}
	}
	//cout << x << " " << y << "\n";
	if(cnt!=2){
		valid = 0;
		reached = 1;
		return;
	}
	for(int i = 0 ; i<4;i++){
		
		int nX = xP[i] + x , nY = yP[i] + y;
		if(nX>=0 && nY>=0 && nX<n && nY<m &&ones.count({nX,nY}) &&  !(nX==pX && nY==pY) ){
			count++;
			check(nX,nY,x,y,sX,sY,1,ones,count);
		}
	}
}
/*
 *
 *10 10
1111111111
1111111111
1111111111
1110100111
1111101111
1111101111
1111101111
1111101111
1111110111
1111111111
 *
 */
void solve(){
	cin >>n >> m;
	for(int i = 0 ;i<n;i++)
		cin >> grid[i];
	set<pair<int , int>> ones;
	rsz(visited ,n);
	for(int i = 0 ; i<n;i++)
		visited[i].resize(m);
	int answer = 0;
	for(int i = 0; i<n;i++){
		for(int j= 0 ;j<m;j++){
		if(grid[i][j]=='1'){
			if(i+1<n && j+1<m){
				if(grid[i+1][j]==grid[i+1][j+1] && grid[i][j]==grid[i][j+1] && grid[i+1][j]=='1'){
					answer = max(answer , 4);
		}
			}
		}
		if(!visited[i][j] && grid[i][j]=='0'){
				clr(ones);
				flood(i , j , ones);
				valid = 1;
				reached =0;
				//cout << ones.size() << " ";
				int count = 0;
				if(ones.size()==0)
					continue;
				auto p= *(ones.begin());
				if(p >=pair<int ,int>{i,j})
					continue;
				check(p.f,p.s , p.f , p.s , p.f , p.s , 0 , ones , count);
				if(valid && reached)
					answer = max(answer , (int)ones.size());
			}
		}
	}
	cout << answer << "\n";

}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
