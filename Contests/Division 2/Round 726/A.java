import java.io.*;
import java.util.*;


public class A{

	/*
	Idea: The goal if to make the following true: total sum = n.
	If the total sum is <= 0, only one positive integer is needed.
	If n > total, only one positive integer is needed
	If total sum > k, total sum - k 0's need to be appended to the end
	*/
    static Scanner in = new Scanner(System.in);
    static PrintWriter p = new PrintWriter(System.out, true);

    static int solve(){

        int n = in.nextInt();
        int sum = 0;
        for (int i = 0; i < n; i++){
            int a = in.nextInt();
            sum += a;
        }
        if (sum <= 0 || n > sum){
            p.println(1);
        }
        else{
            p.println(sum - n);
        }
        return 0;
    }


    public static void main(String[] args){
        long t = in.nextLong();
        while (t-- > 0){
            solve();
        }
    }
}