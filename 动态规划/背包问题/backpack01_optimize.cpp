#include<iostream>
#include<vector>

using namespace std;

int main(){
    int v,n;
    cin>>n>>v;
    vector<int> price(n+1,0);
    vector<int> value(v+1,0);
    for(int i=1;i<=n;i++) cin>>price[i]>>value[i];
    vector<int> dp(v+1,0);
    for(int i=0;i<=n;i++){
        for(int j=v;j>=price[i];j--){
            dp[j] = max(dp[j],dp[j-price[i]]+value[i]);
        }
    }
    cout<<dp[v]<<endl;
    
    return 0;
}
