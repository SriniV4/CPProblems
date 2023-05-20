//https://codeforces.com/contest/1616/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

size_t hF(pair < int, int > a) {
  return (a.first + a.second) * (a.first + a.second + 1) / 2 + a.second;
}
void setIO(string name = "") {
  cin.tie(0) -> sync_with_stdio(0);
  if (name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void solve() {
   int n;
   cin >> n;
 
   vector<int> arr(n);
   for(int i = 0; i<n;i++)
    cin >> arr[i];
      if(n<=2)
{
    cout << 0 << "\n";
    return;
}
    int answer = 0;
   //for(int i = 0;  i<n;i++){// For each element -> 1. Find Mode of difference 
        
       for(int j =0;j<n;j++){
           unordered_map<pair<int , int> , int , function<size_t(pair<int , int>) > > counts(2 , hF);
           for(int  k = 0; k<n;k++){
               if(j==k)
                continue;
           
           int num = arr[k]-arr[j];
           int den = k-j;
           int c = gcd(num , den);
           num/=c;
           den/=c;
           counts[{num , den}]++;
       }
       for(auto item : counts){
           answer= max(answer , item.second);
           //cout << item.first.first <<  " " << item.first.second << " " << item.second << "   ";
       }
       }
       
  // }
   cout << n-answer-1 << "\n";
}
int main() {
      setIO();
      int t = 1;
      cin >> t;
      while (t--) {
        solve();
      }
    }


