//https://codeforces.com/problemset/problem/706/B/
import java.util.*;
import java.io.*;
public class Main{
	static Scanner in = new Scanner(System.in);
	static int n;
	static int[] arr; 
	static int q;
	static int binarySearch(int goal){// Return index of largest element <= goal

		int left = 0 , right = n-1 , answer = -1;
		while(left<=right){
			int middle = (left+right)/2;
			if(arr[middle]<=goal){
				answer = middle;
				left = middle+1;
			} else 
				right = middle -1;
		}
		return answer;
	}
	public static void main(String args[]){
		n = in.nextInt();
		arr = new int[n];
		for(int i = 0 ;i<n;i++){
			arr[i] = in.nextInt();
		}
		Arrays.sort(arr);
		q = in.nextInt();
		for(int i = 0; i<q;i++){
			int val = in.nextInt();
			System.out.println(binarySearch(val)+1);
		}
	}
}
