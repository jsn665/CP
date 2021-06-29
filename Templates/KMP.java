
class KMPTemplate{

    static int[] constructLPS(String pat){
        int m = pat.length();
        int[] lps = new int[m];
        int i = 0;
        int j = 1;
        while (j < m){
            if(pat.charAt(i) == pat.charAt(j)){
                lps[j] = i + 1;
                i++;
                j++;
            }
            else{
                if(i != 0){
                    i = lps[i - 1];
                }
                else{
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }

    static boolean KMP(String a, String pat){
        int[] lps = constructLPS(pat);
        int i = 0;
        int j = 0;
        while (j < pat.length() && i < a.length()){
            if(a.charAt(i) == pat.charAt(j)){
                j++;
                i++;
            }
            else{
                if(j != 0) {
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        return j == pat.length();
    }
}