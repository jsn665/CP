
public class BIT{

    private int maxSize;
    private long[] tree;

    public BIT(){
        maxSize = 100000;
        tree = new long[maxSize];
    }

    public BIT(int maxSize){
        this.maxSize = maxSize;
        tree = new long[this.maxSize];
    }

    public void update(int i, long val){
        while(i < maxSize){
            tree[i] += val;
            i += (i & -i);
        }
    }

    public long sum(int i){
        long res = 0;
        while(i > 0){
            res += tree[i];
            i -= (i & -i);
        }
        return res;
    }
}
