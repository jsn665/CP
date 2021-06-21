import java.io.*;
import java.util.*;



public class A{

    static Scanner in = new Scanner(System.in);
    static PrintWriter p = new PrintWriter(System.out, true);



    static int solve(){
        int n = in.nextInt();
        int largestIndex = 0;
        int smallestIndex = 0;
        int[] arr = new int[n];
        for (int i = 0; i < n; i++){
            int a = in.nextInt();
            arr[i] = a;
            if (arr[i] > arr[largestIndex]){
                largestIndex = i;
            }
            if (arr[i] < arr[smallestIndex]){
                smallestIndex = i;
            }
        }
        int furthest = Math.max(largestIndex, smallestIndex);
        int closest = Math.min(largestIndex, smallestIndex);
        int destroyAllFromFront = (furthest) + 1;
        int destroyAllFromBack = n - closest;
        int destroyOneFromFront = (closest) + 1;
        int destroyOneFromBack = n - furthest;
        int cost = Math.min(destroyAllFromBack, destroyAllFromFront);
        cost = Math.min(cost, destroyOneFromBack + destroyOneFromFront);
        p.println(cost);

        return 0;
    }

    public static void main(String[] args){

        int t = in.nextInt();
        while (t-- > 0){
            solve();
        }
    }
}