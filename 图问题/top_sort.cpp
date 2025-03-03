#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;
int N = 100010;
int n,m;
int s,t;


int main(){
    cin>>n>>m;
    vector<int> indegree(n,0);
    unordered_map<int,vector<int>> p;
    queue<int> q;
    vector<int> result;
    while(m--){
        cin>>s>>t;
        indegree[t]++;
        p[s].push_back(t);
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(q.size()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        vector<int> files = p[cur];
        if (files.size()) {
            for (int i = 0; i < files.size(); i++) {
                indegree[files[i]] --;
                if(indegree[files[i]] == 0) q.push(files[i]);
            }
        }
    }
    if(result.size()==n){
        for (int i = 0; i < n - 1; i++) cout << result[i] << " ";
        cout << result[n - 1];
    }else cout<<-1<<endl;

    return 0;
}
