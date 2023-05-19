//https://codeforces.com/contest/1829/problem/E
import java.util.*;
import java.io.*;

public class Main{
	
	static Scanner in = new Scanner(System.in);
	static int array[][] = new int[1000][1000];
	static int n , m;
	static int answer = 0;
	static int sum = 0;
	static void dfs(int x , int y){
		if(x<0 || y<0 || x>=n || y>=m)
			return;

		sum+=array[x][y];
		if(sum>answer)
		    answer = sum;
		array[x][y] = 0;

		if(x+1<n && array[x+1][y]!=0)
			dfs(x+1 , y);

		if(x!=0 && array[x-1][y]!=0)
			dfs(x-1, y);

		if(y+1<m && array[x][y+1]!=0)
			dfs(x,y+1 );
			
		if(y!=0 && array[x][y-1]!=0)
			dfs(x , y-1 );
	}
	static void solve(){
		n = in.nextInt() ; m = in.nextInt();
		for(int i = 0 ;i<n;i++){
			for(int j = 0 ;j<m;j++){
				array[i][j] = in.nextInt();
			}
		}
		for(int i = 0 ;i<n;i++){
			for(int j = 0 ;j<m;j++){
				if(array[i][j]!=0){
					sum = 0;
					dfs(i , j );
				}
			}
		}
		System.out.println(answer);
		answer = 0;

	}
	public static void main(String args[]){
		
		int t = in.nextInt();
		in.nextLine();
		while(t-- > 0){
			solve();
		}
	}
	
}
