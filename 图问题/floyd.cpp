#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<climits>

using namespace std;
const int N = 1010;
int n,m;
int u,v,w;


int main(){
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(n+1,10005));
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        dp[u][v] = w;
        dp[v][u] = w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }            
    }
    int start,end,res;
    cin>>res;
    while(res--){
        cin>>start>>end;
        if(dp[start][end]==10005) cout<<-1<<endl;
        else cout<<dp[start][end]<<endl;
    }
    return 0;
}
