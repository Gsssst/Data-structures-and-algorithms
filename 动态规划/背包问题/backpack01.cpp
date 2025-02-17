#include<iostream>
#include<vector>

using namespace std;

int main(){
    int v,n;
    cin>>n>>v;
    vector<int> price(n+1,0);
    vector<int> value(v+1,0);
    for(int i=1;i<=n;i++) cin>>price[i]>>value[i];
    
    vector<vector<int>> dp(n+1,vector<int>(v+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=v;j++){
            if(i==0||j==0) dp[i][j]=0;
            else if(j<price[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i]]+value[i]);
        }
    }
    cout<<dp[n][v]<<endl;
    
    return 0;
}
