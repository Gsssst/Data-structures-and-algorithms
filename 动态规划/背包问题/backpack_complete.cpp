#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,v;
    cin>>n>>v;
    vector<int> price(n+1,0);
    vector<int> value(n+1,0);
    for(int i=1;i<=n;i++) cin>>price[i]>>value[i];
    vector<int> dp(v+1,0);
    for(int i=1;i<=n;i++){
        for(int j=price[i];j<=v;j++){
            dp[j] = max(dp[j],dp[j-price[i]]+value[i]);
        }
    }
    cout<<dp[v]<<endl;
    return 0;
}
