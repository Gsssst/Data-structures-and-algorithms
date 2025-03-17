#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;
const int N = 1010;
int p[N];
int degree[N];
int n;
int a,b;
void dfs(int x){
	if(degree[x]==1){
		degree[p[x]]--;
		dfs(p[x]);
	}else{
		return ;
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		p[b] = a;
		degree[a]++;
		degree[b]++;
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	bool flag = false;
	for(int i=1;i<=n;i++){
		if(degree[i]>1) flag = true;
	}
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
