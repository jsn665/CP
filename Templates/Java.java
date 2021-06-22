import java.io.*;
import java.util.*;



class !!!!
{
	static int MOD = 1000000007;
    static Scanner in = new Scanner(System.in);
    static PrintWriter p = new PrintWriter(System.out, true);



    static int solve(){

        return 0;
    }

    public static void main(String[] args)
    {
        
    }

    static class F{

        public static void swap(int[] a, int i, int j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(String[] a, int i, int j){
            String temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(long[] a, int i, int j){
            long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(double[] a, int i, int j){
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

         static int bisect_right(int[] A, int x) {
            return bisect_right(A, x, 0, A.length);
        }

         static int bisect_right(int[] A, int x, int lo, int hi) {
            int N = A.length;
            if (N == 0) {
                return 0;
            }
            if (x < A[lo]) {
                return lo;
            }
            if (x > A[hi - 1]) {
                return hi;
            }
            for (;;) {
                if (lo + 1 == hi) {
                    return lo + 1;
                }
                int mi = (hi + lo) / 2;
                if (x < A[mi]) {
                    hi = mi;
                } else {
                    lo = mi;
                }
            }
        }

        static int bisect_left(int[] A, int x) {
            return bisect_left(A, x, 0, A.length);
        }

        static int bisect_left(int[] A, int x, int lo, int hi) {
            int N = A.length;
            if (N == 0) {
                return 0;
            }
            if (x < A[lo]) {
                return lo;
            }
            if (x > A[hi - 1]) {
                return hi;
            }
            for (;;) {
                if (lo + 1 == hi) {
                    return x == A[lo] ? lo : (lo + 1);
                }
                int mi = (hi + lo) / 2;
                if (x <= A[mi]) {
                    hi = mi;
                } else {
                    lo = mi;
                }
            }
        }
    }
}
