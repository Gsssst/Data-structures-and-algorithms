#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,x;
    while (cin >> n) {
        vector<int> res;
        for(int i=0;i<n;i++){
            cin>>x;
            res.push_back(x);
        }
        vector<int> dp(n,0);
        dp[0] = res[0];
        for(int i=1;i<n;i++){
            dp[i] = res[i];
            for(int j=0;j<i;j++){
                if(res[j]<res[i]) dp[i] = max(dp[j]+res[i],dp[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
