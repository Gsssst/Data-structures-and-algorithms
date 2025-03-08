#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
#include<list>
#include<queue>

using namespace std;
const int N =1e5+10;
int n,m,s;
int u,v,w;

class mycomparison{
public:
	bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
		return lhs.second>rhs.second;
	}
};

struct edge{
	int to,val;
	edge(int t,int i):to(t),val(i){}
};

int main(){
	cin>>n>>m>>s;
	vector<list<edge>> g(n+1);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back(edge(v,w));
	}
	int start = s;
	vector<int> mindist(n+1,INT_MAX);
	vector<bool> visit(n+1,false);
	priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> q;
	q.push(pair<int,int>(start,0));//pair.first 结点，pair.second 距离
	mindist[start] = 0;

	while(!q.empty()){
		pair<int,int> cur = q.top();//选取节点
		q.pop();
		if(visit[cur.first]) continue;
		visit[cur.first] = true;
		for(edge e:g[cur.first]){
			if(!visit[e.to]&&mindist[cur.first]+e.val<mindist[e.to]){
				mindist[e.to] = mindist[cur.first]+e.val;
				q.push(pair<int,int>(e.to,mindist[e.to]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<mindist[i]<<" ";
	}
	return 0;
}
