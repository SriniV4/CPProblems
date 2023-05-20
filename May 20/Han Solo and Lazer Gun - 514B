//https://codeforces.com/problemset/problem/514/B
import java.util.*;
import java.io.*;
public class Main{
	static Scanner in = new Scanner(System.in);
    static int gcd(int a, int b)
    {
        // if b=0, a is the GCD
        if (b == 0)
            return a;
 
        // call the gcd() method recursively by
        // replacing a with b and b with
        // modulus(a,b) as long as b != 0
        else
            return gcd(b, a % b);
    }
	public static void main(String args[]){
		int n = in.nextInt() , x = in.nextInt() , y = in.nextInt();
		HashSet<Double> slopes = new HashSet<>();
		for(int i = 0; i<n;i++){
			int a = in.nextInt() , b = in.nextInt();
			int num = a-x;
			int den = b-y;
			int c = gcd(num , den);

			if(b==y)
				slopes.add(Double.POSITIVE_INFINITY);
			else{ 
			num/=c;
			den/=c;
			slopes.add((double)num/den);

			}
		}
		System.out.println(slopes.size());
	}
}
