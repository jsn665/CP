class SegmentTreeTemplate{

    // Array Implementation of Segment Tree ------ Min Queries ONLY ------
    private int[] ST;
    private int n;

    public SegmentTreeTemplate(int[] arr){
		n = arr.length;
		ST = new int[n << 1];
        System.arraycopy(arr, 0, ST, n, n);
        for(int i = n - 1; i > 0; i--){
            ST[i] = Math.min(ST[i << 1], ST[(i << 1) + 1]);
        }
	}

    public boolean update(int p, int newVal){
        p += n;
        ST[p] = newVal;
        while (p > 1){
            p >>= 1;
            newVal = Math.min(ST[p << 1], ST[(p << 1) + 1]);
            if(newVal != ST[p]){
                ST[p] = newVal;
            }
            else{
                return true;
            }
        }
        return true;
    }

    public int getMin(int l, int r){
        l += n;
        r += n;
        int min = Integer.MAX_VALUE;
        while (l < r){
            if((l & 1) == 1){
                min = Math.min(min, ST[l]);
                l++;
            }
            if ((r & 1) == 1){
                min = Math.min(min, ST[r]);
                r--;
            }
            r >>= 1;
            l >>= 1;
        }
        return min;
    }
}