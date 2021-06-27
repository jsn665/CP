import java.io.*;
import java.util.*;



class B
        {
static int MOD = 1000000007;
static Scanner in = new Scanner(System.in);
static PrintWriter p = new PrintWriter(System.out, true);


static void reverse(int i, int j, List<Character> list){
        while (i <= j){
			char temp = list.get(i);
			list.set(i, list.get(j));
			list.set(j, temp);
			i++;
			j--;
			}
        }

static int solve(){

        int n = in.nextInt();
        String t = in.next();
        List<Character> list = new ArrayList<>(n);
        for (int i = 0; i < n; i++){
			list.add(t.charAt(i));
			}

		for (int i = 1; i <= n; i++){
			if (n % i == 0){
				reverse(0, i - 1, list);
			}
        }


        for (int i = 0; i < n; i++){
			p.print(list.get(i));
        }

        p.close();
        return 0;
        }

public static void main(String[] args)
        {
        solve();
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


    static void swap(int[] a, int i, int j){
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

    static int[] readArrI(int N){
        int[] res = new int[N];
        for (int i = 0; i < N; i++){
            res[i] = in.nextInt();
        }
        return res;
    }

    static String[] readArrS(int N){
        String[] res = new String[N];
        for (int i = 0; i < N; i++){
            res[i] = in.next();
        }
        return res;
    }

    static double[] readArrD(int N){
        double[] res = new double[N];
        for (int i = 0; i < N; i++){
            res[i] = in.nextDouble();
        }
        return res;
    }

    static long[] readArrL(int N){
        long[] res = new long[N];
        for (int i = 0; i < N; i++){
            res[i] = in.nextLong();
        }
        return res;
    }

    static char[] readArrC(int N){
        char[] res = new char[N];
        for (int i = 0; i < N; i++){
            res[i] = in.next().charAt(0);
        }
        return res;
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
