#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
#include<list>
using namespace std;
vector<vector<int>> g(155);
int dfn[155],low[155];
int n,m;
int a,b;
int step = 1;
vector<pair<int,int>> res;
int tarjan(int fa,int ch){
	if(low[ch]) return low[ch];
	dfn[ch] = low[ch] = step++;
	for(int i=0;i<g[ch].size();i++){
		if(g[ch][i]==fa) continue;
		low[ch] = min(low[ch],tarjan(ch,g[ch][i]));
	}
	if(fa&&low[ch]==dfn[ch]) res.push_back(pair<int,int>(min(fa,ch),max(fa,ch)));
	return low[ch];
}
bool cmp(pair<int,int> x,pair<int,int>y){
	if(x.first!=y.first) return x.first<y.first;
	else return x.second<y.second;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	tarjan(0,1);
	sort(res.begin(),res.end(),cmp);
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}
