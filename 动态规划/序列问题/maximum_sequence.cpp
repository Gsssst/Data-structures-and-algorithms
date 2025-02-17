#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    long long n;
    while (cin>>n) { // 注意 while 处理多个 case
        vector<long long> dp(n+1,0);
        long long ans = -INT_MAX;
        for(int i=0;i<n;i++){
            cin>>dp[i];
        }
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i],dp[i-1]+dp[i]);
            ans = max(ans,dp[i]); 
        }    
        cout << ans << endl;
    }
}
