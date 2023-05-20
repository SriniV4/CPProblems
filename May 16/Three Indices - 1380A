//https://codeforces.com/problemset/problem/1380/A
import java.util.*;
import java.io.*;
public class Main{
	static Scanner in = new Scanner(System.in);
	static void solve(){
		int n = in.nextInt();
		int arr[] = new int[n];
		for(int i = 0; i<n;i++)
			arr[i] = in.nextInt();
		int curr = n;
		int left = 0 , right = n-1;
		while((arr[left]==curr || arr[right]==curr) && curr!=1){
			if(arr[left]==curr)
				left++;
			if(arr[right]==curr)
				right--;

			curr--;

		}
		int index = -1;
		for(int i = 0 ; i<n;i++)
			if(arr[i]==curr)
				index = i;
		if(curr==1)
			System.out.println("NO");
		else {
			int smaller = -1 , larger = -1;
			for(int i =0 ;i<index;i++){
				if(arr[i]<curr)
					smaller = i;
			}
			for(int i = index+1;i<n;i++)
				if(arr[i]<curr)
					larger = i;
			System.out.printf("YES\n%d %d %d\n" , smaller+1 , index+1 , larger+1);
			
		}
	}	
	public static void main(String args[]){
		int t = in.nextInt();
		while(t-- > 0)
			solve();
	}
}
