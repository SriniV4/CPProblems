//https://codeforces.com/problemset/problem/1296/B
import java.util.*;
import java.io.*;
public class Main{
	static Scanner in= new Scanner(System.in);
	static void solve(){
		int s = in.nextInt();
		int answer = 0;
		while(s>=10){
			answer+=s-s%10;
			s = s%10 + (s-s%10)/10;
		}
		System.out.println(answer + s);
	}
	public static void main(String args[]){
		int t = in.nextInt();
		for(int i = 0;i<t;i++)
			solve();
	}
}
