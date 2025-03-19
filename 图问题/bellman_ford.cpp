#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;
struct edge{
	int from;
	int to;
	int value;
};

int main(){
	int n,m,u,v,w;
	cin>>n>>m;
	vector<edge> g(m);
	for(int i=0;i<m;i++){
		cin>>g[i].from>>g[i].to>>g[i].value;
	}
	vector<int> mindis(n+1,INT_MAX);
	int st = 1;
	int ed = n;
	mindis[st] = 0;
	for(int i=1;i<n;i++){
		for(auto it:g){
			int from = it.from;
			int to = it.to;
			int value = it.value;
			if(mindis[from]!=INT_MAX&&mindis[from]+value<mindis[to]){
				mindis[to] = mindis[from] + value;
			}
		}
	}
	if(mindis[ed]==INT_MAX) cout<<"unconnected"<<endl;
	else cout<<mindis[ed]<<endl;

	return 0;
}
