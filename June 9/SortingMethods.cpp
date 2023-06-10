#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define PI 3.14159265358979323846
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define f first
#define s second
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<ll>
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

struct segtree{
		vll arr;
		int n;
		segtree(int size){
			while(bits(size)!=1)
				size++;
			 n = size;
			arr.assign(2*n , 0);
		}
		ll find(int curr , int s , int e , int qs , int qe){
			if(s>=qs && e<=qe)return arr[curr];
			if(qe<s || e<qs)return 0;
			return find(2*curr, s , s+(e-s)/2 , qs , qe) + find(2*curr+1 , s+(e-s)/2+1 , e , qs , qe);
		}
		void update(int ind , int val){
				ind+=n;
				arr[ind] = val;
				while(ind!=1){
						ind/=2;
						arr[ind] = arr[ind*2]+arr[ind*2+1];
				}
		}
};
int n;
vll arr;
ll one(){
		ll answer = 0;
		segtree ind(n);
		for(int i = 0;i<n;i++){
				ll greater = ind.find(1, 1 , ind.n, arr[i] , n);
				//int less = ind.query(1 , n , 1 , 1 , arr[i]);
				ind.update(arr[i]-1 , 1);	
				//cout << greater << "\n";
				answer+=greater;
		}
		return answer;
}
vector<vi> adj;
vi visited;
int dfs(int curr){
		visited[curr] = 1;
		if(!visited[adj[curr][0]])
			return 1+dfs(adj[curr][0]);
		else
			return 1;
}
int two(){
	clr(adj);adj.resize(n);
	visited.assign(n , 0);
	for(int i = 0 ; i<n;i++){
			adj[arr[i]-1].pb(i);
	}
	int answer = 0;
	for(int i =0 ;i<n;i++)
		if(!visited[i])
			answer+=dfs(i)-1;
	return answer;
}
int three(){
	/*
	 *	Find LIS -> DP 
	 * 
	 */
	 set<int> nums;
	 for(int i =0 ;i<n;i++){
			if((nums.upper_bound(arr[i]))==nums.end())
				nums.insert(arr[i]);
			else
			{	
					nums.erase(nums.upper_bound(arr[i]));
					nums.insert(arr[i]);
			}
	 }
	 return n-nums.size();
}
int four(){
	/*
	 *	Find Longest sequence that ends with n ( n-k  , n-k+1 .. n) -> This works because these elements are already in order so you put n-k-1 to front ... 1 to front  
	 * 
	 */
	 int goal = n;
	 for(int i = n-1;i>=0;--i)
		if(arr[i]==goal)
			goal--;
	return goal;
}
void solve(){
	cin >> n;
	arr.assign(n , 0);
	for(int i = 0 ;i<n;i++)
		cin >> arr[i];
	cout << one() << " " << two() <<  " " << three() << " " << four() << "\n";
}
int main(){
	setIO();
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}	
}
