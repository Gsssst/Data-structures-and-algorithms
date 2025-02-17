#include <iostream>
#include <vector>
using namespace std;

vector<int> mp(1001,0);

void init(int n){
    for(int i=1;i<=n;i++){
        mp[i] = i;
    }
}

int getroot(int i){
    while(mp[i]!=i){
        i = mp[i];
    }
    return i;
}

void uniontree(int a,int b){
    int roota = getroot(a);
    int rootb = getroot(b);
    mp[roota] = rootb;
}


int main() {
    int n, m;
    int a, b;
    while (cin >> n >> m) { 
        if(n==0) break;
        init(n);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            uniontree(a,b);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(getroot(i)==i) cnt++;
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
