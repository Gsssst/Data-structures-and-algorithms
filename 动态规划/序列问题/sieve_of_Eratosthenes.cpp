#include <vector>
#include <iostream>

using namespace std;

const int N = 1e7+10;
bool isprime[N];
int s[N];
int cnt;

int main(){
    int a,b;
    for(int i=2;i*i<N;i++){
        if(!isprime[i]){
            for(int j=i*2;j<N;j+=i){
                isprime[j] = true;
            }
        }
    }
    for(int i=1;i<N;i++){
        s[i] = s[i-1]+isprime[i];
    }
    while(cin>>a>>b){
        cout<<s[b]-s[a-1]<<endl;
    }
    return 0;
}
