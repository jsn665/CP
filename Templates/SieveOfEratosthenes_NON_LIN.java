import java.util.ArrayList;
import java.util.List;

class SieveOfEratosthenesTemplate{

    // Overall runtime O(n log log n)
    // Overall space O(n)
    static List<Integer> sieveOfE(int N){
        boolean[] isComposite = new boolean[N + 1];
        for(int i = 2; i <= Math.sqrt(N); i++){
            if(!isComposite[i]){
                for(int j = 2; i * j <= N; j++){
                    isComposite[i * j] = true;
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        for(int i = 2; i < isComposite.length; i++){
            if(!isComposite[i]){
                res.add(i);
            }
        }
        return res;
    }
}