#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

const int N = 101;
const int M =5010;
int n,m;
struct edge{
    int a,b,c;
    bool operator<(const edge& t) const
    {
        return c<t.c;
    }
}edge[M];
int p[N];

int find(int x){
    while(p[x]!=x){
        x = p[x];
    }
    return x;
}

int main(){
    while(cin>>n>>m){
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            edge[i] = {a,b,c};
        }
        for(int i=0;i<=n;i++) p[i] = i;//init;
        sort(edge,edge+m);
        int res = 0;//最小费用
        int cnt = 0;
        for(int i=0;i<m;i++){
            int a = edge[i].a;
            int b = edge[i].b;
            int c = edge[i].c;
            if(find(a)!=find(b)){
                p[find(a)] = find(b);//union
                cnt++;
                res += c;
            }
        }
        if(cnt<n-1) cout<<"?"<<endl;
        else cout<<res<<endl;
    }
    
    return 0;
}
