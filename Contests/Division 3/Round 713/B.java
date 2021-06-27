import java.io.*;
import java.util.*;



public class B
{
	static int MOD = 1000000007;
    static FastReader in = new FastReader();
    static PrintWriter p = new PrintWriter(System.out, true);



    static int solve(){

		int n = in.nextInt();
		int s1i = -1, s1j = -1;
		int s2i = 0, s2j = 0;
		boolean finishedFirst = false;
		char[][] arr = new char[n][n];
		for (int i = 0; i < n; i++){
			arr[i] = in.next().toCharArray();
			for (int j = 0; j < n; j++){
				char a = arr[i][j];
				if (a == '*'){
					if (!finishedFirst){
						s1i = i;
						s1j = j;
						finishedFirst = true;
					}
					else{
						s2i = i;
						s2j = j;
					}
				}
				arr[i][j] = a;
			}
		}
		if (s1i == s2i){
			if (s1i - 1 >= 0){
				arr[s1i - 1][s1j] = '*';
				arr[s2i - 1][s2j] = '*';
			}
			else{
				arr[s1i + 1][s1j] = '*';
				arr[s2i + 1][s2j] = '*';
			}
		}
		else if (s1j == s2j){
			if(s1j - 1 >= 0){
				arr[s1i][s1j - 1] = '*';
				arr[s2i][s2j - 1] = '*';
			}
			else{
				arr[s1i][s1j + 1] = '*';
				arr[s2i][s2j + 1] = '*';
			}
		}
		else{
			arr[s2i][s1j] = '*';
			arr[s1i][s2j] = '*';
		}
		
		for (char[] ca: arr){
			for (char c: ca){
				p.print(c);
			}
			p.println();
		}
		
        return 0;
    }

    public static void main(String[] args)
    {
        int t = in.nextInt();
		while (t-- > 0){
			solve();
		}
    }
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
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
