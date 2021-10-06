#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int> (b + 1));
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1e9 + 7;
                for(int k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
                }
 
                for(int k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << "\n";
}
 
int main(){
    solve();
    return 0;
}