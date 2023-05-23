//https://codeforces.com/contest/1428/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
void setIO(){
	cin.tie(0) -> sync_with_stdio(0);
}

void solve(){
	string line;
	cin >> line;
    vector<int> arr;
    int curr = 0;
    int n = line.length();
    char l = line[0];
    bool seen = line[0]=='A';
    int startB = 0;
    for(int i = 0 ; i<line.length();i++){
        
        if(line[i]==l)
            curr++;
        else {
            if(seen){
                arr.push_back(curr);
            } else {
                startB = curr;
            }
            curr = 1;
        }
        seen |= line[i]=='A';
        l = line[i];
        //cout << curr << " ";
    }
    if(!seen && curr){
        cout << curr%2 << "\n";
        return;
    }
    if(curr)
        arr.push_back(curr);
    int extra = 0;
    //cout << startB << " ";
    /*for(int i  : arr)
        cout << i << " ";*/
    for(int i = 0 ;i<arr.size();i+=2){
        if(i+1 >= arr.size())
            break;
        int num = arr[i] + extra;
        if(num>=arr[i+1])
            extra = num - arr[i+1];
        else {
            
            extra = (arr[i+1] - num)%2; 
            if(extra && startB%2){
                startB = 0;
                extra = 0;
            }
        }
    }
   // cout << extra << " ";
        cout << startB%2 + extra + (arr.size()%2?arr[arr.size()-1]:0) << "\n";
}

int main(){
	setIO();
	int t = 1;
	cin >> t;
	while(t--)solve();
}













