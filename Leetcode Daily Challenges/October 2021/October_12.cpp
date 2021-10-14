/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

# define ll long long int
class Solution {
public:
    int guessNumber(int n) {
        ll low = 1, high = n;
        while(low <= high){
            ll mid = (low + high) >> 1;
            int ans = guess(mid);
            if(ans == 0){
                return mid;
            }
            else if (ans > 0){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
