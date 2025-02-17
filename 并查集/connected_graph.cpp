#include <iostream>

using namespace std;

int parent[1001];

void init(int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

int getroot(int i){
    while(parent[i]!=i){
        i = parent[i];
    }
    return i;
}

void uniontree(int a,int b){
    int root1=getroot(a);
    int root2=getroot(b);
    parent[root1] = root2;
}

int main() {
    int n, m;
    int a, b;
    while (cin >> n >> m) { 
        if(n==0&&m==0) break;
        init(n);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            uniontree(a,b);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(getroot(i)==i) cnt++;
        }
        if(cnt==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
