#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
const int N = 10010;
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
vector<vector<int>> res;
vector<vector<int>> g(N);
int n,m;
int u,v;

void tarjan(int x){
	dfn[x]=low[x]=++tot;
	stk[++top] = x;
	instk[x] = 1;
	for(auto y:g[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
		}else if(instk[y]){
			low[x] = min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){
		int y;
		vector<int> path;
		do{
			y = stk[top--];
			instk[y] = 0;
			path.push_back(y);
		}while(y!=x);
		sort(path.begin(),path.end());
		res.push_back(path);
	}
}
bool cmp(vector<int> v1,vector<int> v2){
	return v1[0]<v2[0];
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		g[u].push_back(v);
	}
	tarjan(1);
	sort(res.begin(),res.end(),cmp);
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
