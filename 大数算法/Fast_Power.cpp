#include<iostream>

using namespace std;

int main(){
    long long x,n;
    cin>>x>>n;
    long long res = 1;
    while(n){
        if(n&1) res = (res*x)%233333;//若n为奇数
        x = x*x%233333;//x倍增
        n = n>>1;//n除以2
    }
    cout<<res<<endl;
    
    return 0;
}
